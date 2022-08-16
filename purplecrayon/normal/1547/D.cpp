#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    int p = 0;
    while (n--) {
        int x; cin >> x;
        int ans = 0;
        for (int i = 29; i >= 0; i--) {
            bool bx = (x>>i)&1, bp = (p>>i)&1;
            if (!bx && bp) ans ^= 1<<i;
        }
        cout << ans << ' ';
        p = x^ans;
    }
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}