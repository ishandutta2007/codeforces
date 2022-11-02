#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int INF = 1e18;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        vector<vector<int>> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> t(m), p(m);
        for (int i = 0; i < m; i++) {
            int e;
            cin >> e >> t[i] >> p[i];
            e--;
            b[e].pb(i);
        }
        int sum = 0;
        bool bad = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (b[i].size() == 0) {
                bad = 1;
                break;
            }
            int k = b[i].size();
            vector<vector<int>> dp(k + 1, vector<int>(201, INF));
            dp[0][0] = 0;
            for (int j = 0; j < k; j++) {
                for (int pe = 0; pe <= 200; pe++){
                    if (pe + p[b[i][j]] <= 200) {
                        dp[j + 1][pe + p[b[i][j]]] = min(dp[j + 1][pe + p[b[i][j]]], dp[j][pe] + t[b[i][j]]);
                    }
                    dp[j + 1][pe] = min(dp[j + 1][pe], dp[j][pe]);
                }
            }
            int j = 100;
            for (int f = 101; f <= 200; f++) {
                if (dp[k][f] < dp[k][j]) {
                    j = f;
                }
            }
            if (sum + dp[k][j] > a[i]) {
                bad = 1;
                break;
            }
            sum += dp[k][j];
            for (int f = k; f >= 1; f--) {
                if (dp[f - 1][j] == dp[f][j]) continue;
                ans.pb(b[i][f - 1]);
                j -= p[b[i][f - 1]];
            }
        }
        if (bad) {
            cout << -1 << endl;
        } else {
            cout << ans.size() << endl;
            for (auto to : ans) {
                cout << to + 1 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}