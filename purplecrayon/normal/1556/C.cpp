#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e3+10, MOD = 1e9+7;


int n, a[MAXN];
ll ans = 0;

bool good(ar<ll, 2> x) {
    return x[0] <= x[1];
}
ar<ll, 2> mrg(ar<ll, 2> x, ar<ll, 2> y) {
    return {max(x[0], y[0]), min(x[1], y[1])};
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int l = 0; l < n; l++) if (l&1^1) {
        ll min_ps = 0, ps = 0;
        for (int r = l+1; r < n; r++) {
            //adding x to the front:
            //  min_ps += x, ps += x
            //adding x to the back:
            //  ps += x
            int mul_l = (l%2 == 0 ? 1 : -1);
            int mul_r = (r%2 == 0 ? 1 : -1);

            assert(mul_l == +1);
            if (mul_r == -1) {
                ar<ll, 2> l_range{max(1ll, -min_ps), a[l]};
                ar<ll, 2> r_range{1ll, a[r]};
                ll diff = ps; //how many extra r's
                r_range[0] -= diff, r_range[1] -= diff;
                r_range[0] = max(r_range[0], 1ll);

                ar<ll, 2> c = mrg(l_range, r_range);

                ans += max(0ll, c[1]-c[0]+1);
            }

            ps += a[r]*mul_r;
            min_ps = min(min_ps, ps);
        }
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}