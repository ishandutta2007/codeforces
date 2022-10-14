#include <bits/stdc++.h>
// #define TESTCASE
#define int long long
using namespace std;
using lint = long long;


void solve() {

    int M, N, K, Time;
    cin >> M >> N >> K >> Time;
    vector<int> A(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }
    vector<pair<pair<int, int>, int>> T(K);
    for (int i = 0; i < K; i++) {
        cin >> T[i].first.first >> T[i].first.second >> T[i].second;
    }
    
    sort(T.begin(), T.end());
    sort(A.begin(), A.end(), greater<int>());

    int le = 0, ri = M - 1, ans = 0;

    while (le <= ri) {
        int mid = (le + ri) / 2;

        lint res = 5 * N;
        vector<pair<int, int>> tmp, tmp2;

        for (int i = 0; i < T.size(); i++) {
            if (T[i].second > A[mid]) tmp.emplace_back(T[i].first);
        }
        
        sort(tmp.begin(), tmp.end());
        
        // for (lint k = 0; k <= 100; k++) {
            tmp2.clear();
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp2.empty()) {
                    tmp2.emplace_back(tmp[i]);
                    continue;
                }    

                if (tmp2.back().second >= tmp[i].first) {
                    lint l = min(tmp2.back().first, tmp[i].first);
                    lint r = max(tmp[i].second, tmp2.back().second);
                    tmp2.pop_back();
                    tmp2.push_back({l, r});
                } else {
                    tmp2.emplace_back(tmp[i]);
                }
            }

            lint cur = N + 1;
            for (int i = 0; i < tmp2.size(); i++) {
                cur += (tmp2[i].second - tmp2[i].first + 1) * 2ll;
            }

            res = min(res, cur);
        // }
        
        // res = N + 1;
        
        // cout << mid << " " << res << "\n";
        if (res <= Time) {
            ans = mid + 1;
            le = mid + 1;
        } else {
            ri = mid - 1;
        }

    }

    cout << ans << "\n";

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tc = 1;

    #ifdef TESTCASE
    cin >> tc;
    #endif
    
    while (tc--) {
        solve();
    }
}