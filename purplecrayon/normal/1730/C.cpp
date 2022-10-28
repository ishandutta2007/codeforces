#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int n = sz(s);

    int use = -1;
    vector<bool> vis(n);

    string ans;
    for (int i = '0'; i <= '9'; i++) {
        for (int j = use + 1; j < n; j++) if (s[j] == i) {
            vis[j] = 1;
            use = j;
            ans += i;
        }
    }
    for (int i = 0; i < n; i++) if (!vis[i]) ans += char(min('9', char(s[i]+1)));
    sort(ans.begin(), ans.end());
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}