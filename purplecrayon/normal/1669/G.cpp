#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

void solve() {
    int n, m; cin >> n >> m;
    vector<string> g(n);
    for (auto& s : g) cin >> s;
    for (int j = 0; j < m; j++) {
        string t = "";
        for (int i = 0; i < n; i++) t += g[i][j];
        reverse(t.begin(), t.end());
        for (int i = 0; i < n; i++) if (t[i] != 'o') {
            int r = i;
            while (r < n && t[r] != 'o') r++;
            r--;

            int cnt = 0;
            for (int k = i; k <= r; k++) cnt += t[k] == '*';
            for (int k = i; k <= r; k++) {
                if (k < i + cnt) t[k] = '*';
                else t[k] = '.';
            }

            i = r;
        }
        reverse(t.begin(), t.end());
        for (int i = 0; i < n; i++) g[i][j] = t[i];
    }
    for (auto s : g) cout << s << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}