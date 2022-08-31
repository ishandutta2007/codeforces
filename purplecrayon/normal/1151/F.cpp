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
const int MAXN = 2.5e2+10, MAXM = 1e5+10, MAXL = 17, ALP = 26, MOD = 1e9+7, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct mat {
    vector<vector<ll>> a;
    mat operator*(const mat& m) const {
        assert(sz(a[0])==sz(m.a));
        mat res; res.a.assign(sz(a), vector<ll>(sz(m.a[0])));
        for (int i = 0; i < sz(a); i++){
            for (int j = 0; j < sz(m.a[0]); j++){
                for (int k = 0; k < sz(a[0]); k++){
                    res.a[i][j] = (res.a[i][j]+a[i][k]*m.a[k][j]%MOD + MOD)%MOD;
                }
            }
        }
        return res;
    }
};
mat po(mat m, ll n){
    int sz=sz(m.a);
    mat res; res.a.assign(sz, vector<ll>(sz, 0ll)); for (int i = 0; i < sz; i++) res.a[i][i]=1;
    for (; n; n /= 2, m=m*m)
        if (n&1) res = res*m;
    return res;
}
ll mul(ll a, ll b){ return a*b%MOD; }
ll po(ll b, ll p){
    ll r=1;
    for (; p; p/=2, b=b*b%MOD) if (p&1) r=r*b%MOD;
    return r;
}
ll inv(ll x){ return po(x, MOD-2); }
ll di(ll a, ll b){ return mul(a, inv(b)); }
ll ad(ll a, ll b){ 
    a += b; 
    if (a >= MOD) a -= MOD; 
    return a;
}
ll sub(ll a, ll b){ return ad(a, MOD-b); }
void solve(){
    int n; ll k; cin >> n >> k;
    int l=0, r=0;
    vector<int> a(n);
    for (auto& it : a) { 
        cin >> it;
        if (!it) l++;
        else r++;
    }
    auto c2 = [&](ll x){
        return di(mul(x, x-1), 2ll);
    };
    //dp[i][j] -> prob with i zeroes in the left with j moves left that it ends up being sorted
    //dp[i][j] =
    //either move a zero to the right (i--)
    //or move a zero to the left (i++)
    
    //ans = dp[l][0];
    /*vector<ll> pre(l+1, 0), cur(l+1, 0);
    int st=0; for (int i = 0; i < l; i++) st += a[i]^1;
    pre[st]=1; ll nc2 = c2(n);
    for (int rep = 0; rep < k; rep++){
        for (int zl = 0; zl <= l; zl++){
            int zr = l-zl, onl = zr, onr = r-zr;
            cur[zl] = 0;
            if (zr > r) continue;
            if (zl && zr < r) { //move zero from right to the left -> zl--, zr++, onl++, onr--;
                cur[zl] = mul(di(mul(zr+1, onl+1), nc2), pre[zl-1]);
            }
            if (zl < l) { //move zero from left to right -> zl++, zr--, onl--, onr++;
                cur[zl] = ad(cur[zl], mul(di(mul(zl+1, onr+1), nc2), pre[zl+1]));
            }
            //chose something from the same side
            cur[zl] = ad(cur[zl], mul(pre[zl], di(ad(c2(l), c2(r)), nc2)));
            //chose the same num from different sides
            cur[zl] = ad(cur[zl], mul(pre[zl], di(ad(mul(zl, zr), mul(onl, onr)), nc2)));
        }
        // for (int i = 0; i < n; i++) cout << cur[i] << ' '; cout << '\n';
        swap(pre, cur);
    }
    cout << pre[l];*/
    
    mat m1; m1.a.assign(l+1, vector<ll>(l+1, 0ll));
    ll nc2 = c2(n);
    for (int zl = 0; zl <= l; zl++){ //calculating column zl
        int zr = l-zl, onl = zr, onr = r-zr;
        if (zr > r) continue;
        if (zl && zr < r){
            m1.a[zl-1][zl] = ad(m1.a[zl-1][zl], di(mul(zr+1, onl+1), nc2));
        }
        if (zl < l){
            m1.a[zl+1][zl] = ad(m1.a[zl+1][zl], di(mul(zl+1, onr+1), nc2));
        }
        m1.a[zl][zl] = ad(m1.a[zl][zl], di(ad(c2(l), c2(r)), nc2));
        m1.a[zl][zl] = ad(m1.a[zl][zl], di(ad(mul(zl, zr), mul(onl, onr)), nc2));
    }
    int sti=0; for (int i = 0; i < l; i++) sti += a[i]^1;
    mat st; st.a.assign(1, vector<ll>(l+1, 0ll)); st.a[0][sti]=1;
    mat r1 = st*po(m1, k);
    cout << r1.a[0][l] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}