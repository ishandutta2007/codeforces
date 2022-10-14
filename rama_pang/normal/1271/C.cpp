#include <bits/stdc++.h>
// #define TESTCASE
using namespace std;
using lint = long long;
int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    #ifdef TESTCASE
    cin >> T;
    #else
    T = 1;
    #endif
    while (T--) {
        solve();
    }
    return 0;
}




int solve() {

    int N;
    pair<int, int> S;
    cin >> N >> S.first >> S.second;

    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int ans = -1;
    pair<int, int> opt;
    for (int i = S.first - 1; i <= S.first + 1; i++) {
        for (int j = S.second - 1; j <= S.second + 1; j++) {
            if (make_pair(i, j) == S) continue;
            if (i < 0 || j < 0 || i > 1e9 || j > 1e9) continue;
            int cur = 0;
            for (int k = 0; k < N; k++) {
                int dist = abs(A[k].first - S.first) + abs(A[k].second - S.second);
                int dist1 = abs(i - S.first) + abs(j - S.second);
                int dist2 = abs(i - A[k].first) + abs(j - A[k].second);
                if (dist == dist1 + dist2) cur++;
            }
            if (cur > ans) {
                ans = cur;
                opt = {i, j};
            }
        }
    }

    cout << ans << "\n";
    cout << opt.first << " " << opt.second << "\n";


}