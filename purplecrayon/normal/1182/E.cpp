#include <bits/stdc++.h>
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
const int MAXN = 2e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MOD2 = 1e9+6, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n", first = "DA\n", second = "NET\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct mat {
    vector<vector<ll>> a;
    mat operator*(const mat& m) const {
        assert(sz(a[0])==sz(m.a));
        mat res; res.a.assign(sz(a), vector<ll>(sz(m.a[0])));
        for (int i = 0; i < sz(a); i++){
            for (int j = 0; j < sz(m.a[0]); j++){
                for (int k = 0; k < sz(a[0]); k++){
                    res.a[i][j] = (res.a[i][j]+a[i][k]*m.a[k][j])%MOD2;
                }
            }
        }
        return res;
    }
};
mat po(mat m, ll n){
    mat res; int csz = sz(m.a);
    res.a.assign(csz, vector<ll>(csz, 0)); for (int i = 0; i < csz; i++) res.a[i][i] = 1; //identity matrix
    for (; n; n /= 2, m=m*m)
        if (n&1) res = res*m;
    return res;
}
ll po(ll b, ll p){
    ll r=1;
    for (; p; p /= 2, b=b*b%MOD) if (p&1) r=r*b%MOD;
    return r;
}
void solve(){
    ll n, f1, f2, f3, c; cin >> n >> f1 >> f2 >> f3 >> c;
    mat m1;
    m1.a = 
    {       {0, 0, 1},
            {1, 0, 1},
            {0, 1, 1}
    };
    ll rn=n-3;
    mat r1 = po(m1, rn);
    mat mf1; mf1.a = {{1, 0, 0}}; ll cf1 = (mf1*r1).a[0][2];
    mat mf2; mf2.a = {{0, 1, 0}}; ll cf2 = (mf2*r1).a[0][2];
    mat mf3; mf3.a = {{0, 0, 1}}; ll cf3 = (mf3*r1).a[0][2];
    ll ans=po(f1, cf1); ans = ans*po(f2, cf2)%MOD; ans = ans*po(f3, cf3)%MOD;
    //now account for the c's
    m1.a = 
    {
            {0, 0, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 2, 1, 0},
            {0, 0, -6, 1, 1}
    };
    r1 = po(m1, rn);
    mat mc1; mc1.a = {{0, 0, 0, 4, 1}}; ll cc  = (mc1*r1).a[0][2];
    ans = ans*po(c, cc)%MOD;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}