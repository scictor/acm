class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        vector<vector<int>> result;
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        unordered_map<int,vector<pair<int,int>>> cache;
        for (size_t i = 0; i < A.size(); ++i) {
            for (size_t j = 0; j < B.size(); ++j) {
                cache[A[i]+B[j]].push_back(make_pair<int,int>(i,j));
            }
        }
        for (size_t k = 0; k < C.size(); ++k) {
            for (size_t l = 0; l < D.size(); ++l) {
                const int key = 0-C[k]-D[l];
                if(cache.find(key) == cache.end()) continue;
                const auto &vec = cache[key];
                for (int m = 0; m < vec.size(); ++m) {
                    result.push_back({A[vec[key].first],B[vec[key].second],C[k],D[l]});
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result.size();
    }
};

//a better method by freeprogrammer https://discuss.leetcode.com/topic/78430/concise-c-11-code-beat-99-5
 class Solution {
public:
      int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int>  abSum;
        for(auto a : A) {
            for(auto b : B) {
                ++abSum[a+b];
            }
        }
        int count = 0;
        for(auto c : C) {
            for(auto d : D) {
                auto it = abSum.find(0 - c - d);
                if(it != abSum.end()) {
                    count += it->second;
                }
            }
        }
        return count;
    }
};
