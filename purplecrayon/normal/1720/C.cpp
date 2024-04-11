#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (auto& s : g) cin >> s;

    int cnt = 0, best = 4;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cnt += g[i][j] == '1';
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            for (int a = i-1; a <= i; a++) for (int b = j-1; b <= j; b++) {
                int cur = (g[i-1][j-1] - '0') + (g[i-1][j] - '0') + (g[i][j-1] - '0') + (g[i][j] - '0');
                cur -= (g[a][b] - '0');
                if (cur > 0) best = min(best, cur);
            }
        }
    }
    if (cnt == 0) cout << 0 << '\n';
    else cout << cnt - best + 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}