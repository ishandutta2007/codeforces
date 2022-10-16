#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ios\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
#define VEC(type, name, size)\
    V<type> name(size);\
    IN(name)
#define VVEC(type, name, h, w)\
    VV<type> name(h, V<type>(w));\
    IN(name)
#define INT(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LL(...)\
    ll __VA_ARGS__;\
    IN(__VA_ARGS__)
#define STR(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define CHAR(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define DOUBLE(...)\
    DOUBLE __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LD(...)\
    LD __VA_ARGS__;\
    IN(__VA_ARGS__)
template <class T> void scan(T &a) { cin >> a; }
template <class T> void scan(vector<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
#define ll long long
#define ld long double
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
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
const ll INF = 1e18;
#pragma endregion

struct Edge{
    ll to,cost;
    Edge(ll to,ll cost):to(to),cost(cost){}
    bool operator<(const Edge& a) const{
        return cost >a.cost;
    }
};
using Graph = VV<>;

Graph G;
V<> dfsdata;

ll dfs(int k, int p = -1){
    ll cnt = 0;
    for(auto v : G[k]){
        if(v == p) continue;
        cnt += dfs(v, k);
    }
    if(cnt == 0) cnt++;
    return dfsdata[k] = cnt;
}

void solve(){
    LL(n, s);
    G.clear();
    G.resize(n);
	dfsdata.clear();
    dfsdata.resize(n);
    V<pair<pair<ll,ll>,ll>> data(n - 1);
    REP(i, n - 1){
        LL(u, v, c);
        u--; v--;
        G[u].pb(v);
        G[v].pb(u);
        data[i] = {{u, v}, c};
    }
    dfs(0);
    priority_queue<pair<pair<ll, ll>,ll>> q;
    ll sum = 0;
    REP(i, n - 1){
        ll usednum = min(dfsdata[data[i].first.first], dfsdata[data[i].first.second]);
        ll loss = (data[i].second - data[i].second / 2) * usednum; 
        q.push({{loss, usednum}, i});
        sum += data[i].second * usednum;
    }
    ll res = 0;
    while(sum > s){
        res++;
        ll nloss = q.top().first.first;
        ll usednum = q.top().first.second;
        ll i = q.top().second;
        q.pop();
        sum -= nloss;
        data[i].second /= 2;
        ll loss = (data[i].second - data[i].second / 2) * usednum; 
        q.push({{loss, usednum}, i});
    }
    print(res);
}

int main(){
    ios;
    INT(t);
    while(t--) solve();
}