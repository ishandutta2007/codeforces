#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const ll INF = 1e18;

signed main() {
#ifdef LOCAL
   // freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll x, y;
        int n;
        cin >> n >> x >> y;
        vector<int> a(n), b(n);
        int res = 0;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            a[i] = c - '0';
            res ^= a[i];
        }
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            b[i] = c - '0';
            res ^= b[i];
        }
        if (res) {
            cout << -1 << endl;
            continue;
        }
        if (x >= y) {
            vector<int> pos;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    pos.pb(i);
                }
            }
            int cnt = pos.size();
            assert(cnt % 2 == 0);
            if (cnt == 0) {
                cout << 0 << endl;
            } else if (cnt > 2 || abs(pos[0] - pos[1]) > 1) {
                cout << y * cnt / 2 << endl;
            } else {
                if (pos[0] > 1 || n - pos.back() - 1 > 1) {
                    cout << min(x, y * 2) << endl;
                } else if (pos[0] == 1 && pos[1] == 2) {
                    cout << min(x, y * 3);
                } else {
                    cout << x << endl;
                }
            }
            continue;
        }
        vector<vector<ll>> dp(n + 1, vector<ll>(2, INF));
        int last = 0;
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            vector<vector<ll>> dpp(n + 1, vector<ll>(2, INF));
            for (int j = 0; j <= n; j++) {
                dpp[j][0] = dp[j][last];
                dpp[j][1] = min(dpp[j][1], dp[j][last ^ 1] + x);
                if (j + 1 <= n) {
                    dpp[j][1] = min(dpp[j][1], dp[j + 1][last] + y);
                }
            }
            for (int j = 0; j < n; j++) {
                for (int f = 0; f < 2; f++) {
                    dpp[j + 1][f ^ 1] = min(dpp[j + 1][f ^ 1], dpp[j][f]);
                }
            }
            swap(dp, dpp);
            last = a[i] ^ b[i];
        }
        cout << dp[0][last] << endl;
    }
    return 0;
}