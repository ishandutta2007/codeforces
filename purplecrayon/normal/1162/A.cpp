#include "bits/stdc++.h"
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 5e5+10, MAXM = 2e5+10, MAXL = 17, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    ll n, m, h; cin >> n >> h >> m;
    vector<ll> l(m), r(m), x(m); for (int i = 0; i < m; i++) cin >> l[i] >> r[i] >> x[i], --l[i], --r[i];
    ll ans=0;
    for (int i = 0; i < n; i++){
        ll mx=h;
        for (int j = 0; j < m; j++) if (l[j] <= i && i <= r[j]) mx = min(mx, x[j]);
        ans += mx*mx;
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}