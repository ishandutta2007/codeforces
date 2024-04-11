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

using P = pair<ll, ll>;

void solve(){
    //Toporogical sort___________________________________

    //n:, m:
    ll n, m; cin >> n >> m;
    VV<> G(n);
    V<> h(n, 0);
    V<P> dir;
    V<P> nodir;
    //input
    REP(i, m) {
        ll t, u, v; cin >> t >> u >> v; u--; v--;
        if(t){
            G[u].push_back(v);
            h[v]++;
            dir.pb({u, v});
        }
        else nodir.pb({u, v});
    }
    stack<int> st;
    REP(i, n) if(!h[i]) st.push(i);

    //toporogical sort
    V<> t_sort;
    while(SZ(st)) {
        ll p = st.top(); st.pop();
        t_sort.push_back(p);
        for(auto v: G[p]) {
            h[v]--;
            if(!h[v]) st.push(v);
        }
    }
    
    //if Graph is DAG, return true. Else return false.
    auto is_DAG = [&](){return SZ(t_sort) == n;};

    //____________________________________________________
    if(!is_DAG()){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    V<> pl(n);
    REP(i, n) pl[t_sort[i]] = i;
    for(auto v: dir) cout << v.first + 1 << " " << v.second + 1 << endl;
    for(auto v: nodir){
        if(pl[v.first] < pl[v.second]) cout << v.first + 1 << " " << v.second + 1 << endl;
        else cout << v.second + 1 << " " << v.first + 1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}