#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 5e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    int ans = MOD;
    for (char c = 'a'; c <= 'z'; c++) {
        string t;
        vector<int> v{0};

        int cur = 0;
        for (char x : s) {
            if (x == c) v[sz(v)-1]++, cur++;
            else v.emplace_back(), t += x;
        }
        bool bad = 0;
        for (int l = 0, r = sz(t)-1; l < r; l++, r--) {
            if (t[l] != t[r]) {
                bad = 1;
                break;
            }
        }
        if (bad) continue;
        for (int l = 0, r = sz(v)-1; l <= r; l++, r--) {
            if (l == r) cur -= v[l];
            else cur -= min(v[l], v[r]) * 2;
        }
        ans = min(ans, cur);
    }
    if (ans == MOD) cout << -1 << '\n';
    else cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}