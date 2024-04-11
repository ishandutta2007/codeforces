#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int a, b, c; cin >> a >> b >> c;
    ar<int, 4> ans; ans.fill(MOD);
    for (int x = 1; x <= 2*b; x++) {
        for (int y = x; y <= 2*c; y += x) {
            int z = (c%y < y-c%y ? c-c%y : c+(y-c%y));
            int cur = abs(a-x)+abs(y-b)+abs(z-c);
            ans = min(ans, {cur, x, y, z});
        }
    }
    cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}