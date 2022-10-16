#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
const ll INF = 1e18;
template <typename T>
T pow(T a, long long n, T e = 1) {
    T ret = e;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

void solve(){
    ll n; cin >> n;
    string a, b; cin >> a >> b;
    V<> k(n, 0);
    ll nc = -1;
    REP(i, n) if(a[i] != b[i]) nc = i;
    V<> res;
    while(nc > -1){
        if(a[0] == b[nc]){
            res.pb(0);
            a[0] = (a[0] == '0' ? '1' : '0');
        }
        res.pb(nc);
        string u = a.substr(0, nc + 1);
        reverse(all(u));
        REP(i, nc + 1) u[i] = (u[i] == '0' ? '1' : '0');
        a = u;
        b = b.substr(0, SZ(a));
        nc = -1;
        REP(i, SZ(a)) if(a[i] != b[i]) nc = i;
    }
    cout << SZ(res) << " ";
    for(auto v: res) cout << v + 1 << " "; cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}