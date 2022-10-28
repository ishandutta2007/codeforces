#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void fsc(int &x){
    register int c;
    x = 0; c=getchar();
    for(;(c>47 && c<58);c=getchar())
        x = (x<<1)+(x<<3)+c-48;
}
void read(){}
template <typename T, typename... Types> 
void read(T& var1, Types&... var2) { 
    fsc(var1);
    read(var2...) ; 
}

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 61;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll MAXBB = (1ll<<MAXB);

typedef pair<ll, ll> pl;
pl mul(pl a, pl b){ return {a.first*b.first%MOD, a.second*b.second%MOD}; }
pl add(pl a, pl b){ return {(a.first+b.first)%MOD, (a.second+b.second)%MOD}; }
pl sub(pl a, pl b){ return add(a, {MOD-b.first, MOD-b.second}); }
ll po(ll b, ll p){
    ll r=1;
    for (; p; p/=2, b=b*b%MOD) if (p&1) r=r*b%MOD;
    return r;
}
ll inv(ll x){ return po(x, MOD-2); }
const pl BASE = {13807, 435059};
void pre(){
    
}
void solve(){
    ll n, m, q; cin >> n >> m >> q;
    ll g = __gcd(n, m), na=n/g, ma=m/g;
    auto conv = [&](ll x, ll y){
        y--;
        if (x == 1) return y/na;
        else return y/ma;
    };
    while (q--){
        ll sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
        cout << (conv(sx, sy)==conv(ex, ey)?yes:no);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; pre();
    //cin >> t; 
    while (t--) solve();
}