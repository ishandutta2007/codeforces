#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=(s);i<(e);i++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);i--)
#define chkmax(a,b) a = max(a,b)
#define chkmin(a,b) a = min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e18, MOD = 1e9 + 7;

template <class A, class B> pair<A,B> operator+(pair<A,B>& a, pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(pair<A,B>& a, pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);


vb check;
void dfs(int cur, vvii& g, vi& v){
    if (check[cur]) return ;
    check[cur] = 1;
    for(auto nei:g[cur]) dfs(nei.x, g, v);
    v.pb(cur);
}
void dfs2(int cur, vvii& g, vi& d, int& v, int dd=0){
    if (d[cur]!=-1){
        v = __gcd(v,abs(dd-d[cur]));
        return ;
    }
    d[cur] = dd;
    for(auto nei:g[cur]) dfs2(nei.x, g, d, v, dd+nei.y);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vvii g(n), ag(n);
    loop(i,0,m){
        int a,b,c; cin>>a>>b>>c; a--, b--;
        g[a].pb({b,c});
        ag[b].pb({a,c});
    }
    check.resize(n);
    vi order;
    loop(i,0,n) if(!check[i]) dfs(i, g, order);
    reverse(all(order));
    fill(all(check), 0);
    vvi gs;
    vi in(n);
    for(int x:order){
        if (check[x]) continue;
        vi v;
        dfs(x, ag, v);
        for(int x:v) in[x] = gs.size();
        gs.pb(v);
    }
    int cnt = gs.size();
    vvii gg(n);
    loop(i,0,n) for(auto p:g[i]) if(in[i]==in[p.x]) gg[i].pb(p);
    vi d(n,-1);
    vi vals(cnt);
    loop(i,0,cnt){
        dfs2(gs[i][0], gg, d, vals[i]);
    }
    int q; cin>>q;

    vb ans(q);
    loop(i,0,q){
        int v,s,t; cin>>v>>s>>t; v--;
        ans[i] = (s%__gcd(t, vals[in[v]]))==0;
    }
    loop(i,0,q) cout<<(ans[i]?"YES":"NO")<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -D_GLIBCXX_DEBUG -o a & a
4 5
1 2 1
2 3 1
3 1 2
1 4 1
4 3 2
2
1 2 4
4 3 5



4 4
1 2 1
2 3 1
3 1 2
1 4 3
3
1 1 3
1 2 4
4 0 1

*/