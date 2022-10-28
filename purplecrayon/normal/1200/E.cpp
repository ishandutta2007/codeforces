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
const int MAXN = 1e6+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 61;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll MAXBB = (1ll<<MAXB);

typedef pair<ll, ll> pl;
pl mul(pl a, pl b){ return {a.first*b.first%MOD, a.second*b.second%MOD}; }
pl mul(pl a, ll b){ return {a.first*b%MOD, a.second*b%MOD}; }
pl add(pl a, pl b){ return {(a.first+b.first)%MOD, (a.second+b.second)%MOD}; }
pl sub(pl a, pl b){ return add(a, {MOD-b.first, MOD-b.second}); }
ll mpo(ll b, ll p){
    ll r=1;
    for (; p; p/=2, b=b*b%MOD) if (p&1) r=r*b%MOD;
    return r;
}
ll inv(ll x){ return mpo(x, MOD-2); }
pl inv(pl x){ return {inv(x.first), inv(x.second)}; }
ll conv(char c){ return (c >= '0' && c <= '9' ? c-'0' : (c >= 'a' && c <= 'z' ? 10+c-'a' : 36+c-'A'))+1; }
const pl BASE = {13807, 435059};

pl po[MAXN], ipo[MAXN];

void pre(){
    po[0] = ipo[0] = {1, 1};
    for (int i = 1; i < MAXN; i++) po[i] = mul(BASE, po[i-1]), ipo[i] = inv(po[i]);
}
void solve(){
    int n; cin >> n;
    vector<string> v(n); for (auto& it : v) cin >> it;
    
    auto getHsh = [&](string& s){
        vector<pl> r(sz(s));
        for (int i = 0; i < sz(s); i++){
            r[i] = mul(po[i], conv(s[i]));
            if (i) r[i] = add(r[i-1], r[i]);
        }
        return r;
    };
    auto get = [&](vector<pl>& hsh, int l, int r){
        pl c=hsh[r]; if (l) c = sub(c, hsh[l-1]);
        c = mul(c, ipo[l]); return c;
    };
    
    vector<char> ans;
    vector<pl> ps; //hash of ans
    for (int i = 0; i < n; i++){
        string& s = v[i]; vector<pl> cur = getHsh(s);
        int pre=0;
        for (int j = 1; j <= min(sz(s), sz(ps)); j++) if (get(ps, sz(ps)-j, sz(ps)-1) == get(cur, 0, j-1)) pre=j;
        for (int j = pre; j < sz(s); j++) {
            ans.push_back(s[j]);
            pl cur = mul(po[sz(ps)], conv(s[j]));
            if (sz(ps)) cur = add(cur, ps.back());
            ps.push_back(cur);
        }
    }
    for (auto it : ans) cout << it;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; pre();
    //cin >> t; 
    while (t--) solve();
}