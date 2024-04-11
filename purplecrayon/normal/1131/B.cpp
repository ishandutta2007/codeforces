#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    ar<ll, 2> prv{0, 0};
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ar<ll, 2> cur; cin >> cur[0] >> cur[1];
        ll mx = max(prv[0], prv[1]);
        ll mn = min(cur[0], cur[1]);

        if (mn >= mx) {
            ans += mn-mx+1;
        }
        if (cur[0] == cur[1]) ans--; //correct for overcounting
        prv = cur;
    }
    ans += prv[0] == prv[1];
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}