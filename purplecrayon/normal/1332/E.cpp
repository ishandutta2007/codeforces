#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct mat {
    vector<vector<ll>> a;
    mat operator*(const mat& m) const {
        assert(sz(a[0])==sz(m.a));
        mat res; res.a.assign(sz(a), vector<ll>(sz(m.a[0])));
        for (int i = 0; i < sz(a); i++){
            for (int j = 0; j < sz(m.a[0]); j++){
                for (int k = 0; k < sz(a[0]); k++){
                    res.a[i][j] = (res.a[i][j]+a[i][k]*m.a[k][j])%MOD;
                }
            }
        }
        return res;
    }
};
mat po(mat m, ll n){
    int siz=sz(m.a);
    mat res; res.a.assign(siz, vector<ll>(siz, 0));
    for (int i = 0; i < siz; i++) res.a[i][i] = 1ll;
    for (; n; n /= 2, m=m*m)
        if (n&1) res = res*m;
    return res;
}
void solve(){
    auto _nmO = [&](ll x){
        return (x+1)/2;
    };
    auto _nmE = [&](ll x){
        return x/2;
    };
    auto nmO = [&](ll l, ll r){
        return _nmO(r)-_nmO(l-1);
    };
    auto nmE = [&](ll l, ll r){
        return _nmE(r)-_nmE(l-1);
    };
    ll n, m, l, r; cin >> n >> m >> l >> r;
    ll x = nmO(l, r), y=nmE(l, r); assert(x+y==r-l+1);
    mat m1; 
    m1.a = {{y, x},
           {x, y}};
    mat r1;
    r1.a = {{1, 0}};
    mat ans;
    ans = r1*po(m1, n*m);
    if ((n*m)&1){
        cout << (ans.a[0][0]+ans.a[0][1])%MOD << '\n';
    } else {
        cout << (ans.a[0][0])%MOD << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    //cin >> t;
    while (t--) solve();
}