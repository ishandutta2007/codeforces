#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

const int MOD = 998244353;

int mul(int a, int b) {
    return (a * b % MOD);
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<bool> used_row(n), used_col(m);
        vector<pair<int,int>> u(q);
        int cnt_row = n, cnt_col = m;
        for (int i = 0; i < q; i++) {
            int x, y;
            cin >> x >> y;
            x--, y--;
            u[i] = {x, y};
        }
        reverse(u.begin(), u.end());
        int ans = 1;
        for (auto [x, y] : u) {
            if (!used_row[x] && used_col[y]) {
                if (cnt_col > 0) {
                    ans = mul(ans, k);
                }
            } else if (!used_col[y] && used_row[x]) {
                if (cnt_row > 0) {
                    ans = mul(ans, k);
                }
            } else if (!used_row[x] && !used_col[y]) {
                ans = mul(ans, k);
            }
            if (!used_row[x]) {
                cnt_row--;
                used_row[x] = 1;
            }
            if (!used_col[y]) {
                cnt_col--;
                used_col[y] = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}