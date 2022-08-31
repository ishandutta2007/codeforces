#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 3e5+10, MOD = 1e9+7;

void solve() {
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i <= sz(s); i++) {
        string t = s;
        if (i < sz(s)) t[i] ^= 'V' ^ 'K';

        int cur = 0;
        for (int i = 1; i < sz(s); i++) if (t[i-1] == 'V' && t[i] == 'K')
            cur++;
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}