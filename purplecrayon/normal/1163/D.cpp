#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;
const int M = 51;

int pre[M][M], cur[M][M];

void solve() {
    auto trans = [&](string s) {
        int n = sz(s);
        vector<ar<int, 26>> ans(n + 1);
        for (int i = 0; i <= n; i++) {
            ans[i].fill(0);
            for (int j = 0; j < 26; j++) {
                string c = s.substr(0, i);
                c += char(j + 'a');

                // longest suffix of c that is a prefix of s
                for (int x = min(sz(c), sz(s)); x > 0; x--) {
                    if (c.substr(sz(c) - x, x) == s.substr(0, x)) {
                        ans[i][j] = x;
                        break;
                    }
                }
            }
        }
        return ans;
    };

    string c, s, t; cin >> c >> s >> t;

    auto one = trans(s), two = trans(t);
    for (int i = 0; i <= sz(s); i++) {
        for (int j = 0; j <= sz(t); j++) {
            if (i || j) pre[i][j] = -MOD;

            cur[i][j] = -MOD;
        }
    }
    for (char _x : c) {
        auto add = [&](int x) {
            for (int i = 0; i <= sz(s); i++) for (int j = 0; j <= sz(t); j++) {
                int ni = one[i][x];
                int nj = two[j][x];

                cur[ni][nj] = max(cur[ni][nj], pre[i][j] + (ni == sz(s)) - (nj == sz(t)));
            }
        };

        if (_x == '*') {
            for (int i = 0; i < 26; i++) add(i);
        } else {
            add(_x - 'a');
        }

        for (int i = 0; i <= sz(s); i++) for (int j = 0; j <= sz(t); j++) {
            pre[i][j] = cur[i][j];
            cur[i][j] = -MOD;
        }
    }

    int ans = -MOD;
    for (int i = 0; i <= sz(s); i++) for (int j = 0; j <= sz(t); j++)
        ans = max(ans, pre[i][j]);

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}