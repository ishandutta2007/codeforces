#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7, MAXL = 34;
const int INF = 1e9+10;
const ll INFLL = 1e18+10;

struct mat {
    vector<vector<ll>> a;
    mat operator*(const mat& m) const {
        assert(sz(a[0])==sz(m.a));
        mat res; res.a.assign(sz(a), vector<ll>(sz(m.a[0]), INFLL));
        for (int i = 0; i < sz(a); i++){
        	for (int k = 0; k < sz(a[0]); k++){
            	for (int j = 0; j < sz(m.a[0]); j++){
                    res.a[i][j] = min(res.a[i][j], a[i][k]+m.a[k][j]);
                }
            }
        }
        return res;
    }
};
mat po(mat m, ll n){
    mat res=m; n--;
    for (; n; n /= 2, m=m*m)
        if (n&1) res = res*m;
    return res;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& it : a) cin >> it;
    vector<int> b(n); for (auto& it : b) cin >> it;

    vector<vector<int>> mn(n+1, vector<int>(2*n+1, INF));
    for (int i = 0; i < (1<<n); i++) {
        int ps = 0, mn_ps = 0;
        int tot = 0;
        for (int j = 0; j < n; j++) {
            int cur = (i>>j)&1;
            ps += cur ? 1 : -1;

            mn_ps = min(mn_ps, ps);

            if (cur) tot += a[j]; 
            else tot += b[j];
        }
        mn[-mn_ps][ps+n] = min(mn[-mn_ps][ps+n], tot);
    }
    const int BAL = 4*n+1;
    mat dp; dp.a.assign(BAL, vector<ll>(BAL, INFLL));
    for (int i = 0; i < BAL; i++) {
        for (int j = 0; j < BAL; j++) {
            int tot_ps = j - i;
            if (tot_ps < -n || tot_ps > n) continue;

            int mn_ps = -i; //mn_ps >= -i, -mn_ps <= i
            for (int k = -mn_ps; k >= 0; k--) {
                if (k <= n)
                    dp.a[i][j] = min<ll>(dp.a[i][j], mn[k][tot_ps+n]);
            }
        }
    }

    dp = po(dp, m);
    cout << dp.a[0][0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}