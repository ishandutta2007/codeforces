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

typedef pair<int, ii> Edge;
bool inter(ii a, ii b){
    return a.x==b.x || a.x==b.y || a.y==b.x || a.y==b.y;
}
map<ii, int> AllEdges;
vi vals; multiset<int> svals;
vector<set<ii>> g, restg;
set<Edge> edges;

Edge getE(int a, int b, int c){
    if (a>b) swap(a,b);
    return {c,{a,b}};
}
Edge flip(Edge e){
    return {e.x, {e.y.y, e.y.x}};
}
const int K = 3;
void fix(int a, bool flag = 1){
    if (flag && vals[a]!=-1) svals.erase(svals.find(vals[a])), vals[a]=-1;
    while(g[a].size()>K) {
        auto it = prev(g[a].end());
        auto itt = edges.find(getE(a, it->y, it->x));
        if (itt!=edges.end()) edges.erase(itt);
        restg[a].insert(*it);
        g[a].erase(it);
    }
    while(g[a].size()<K && restg[a].size()){
        auto it = restg[a].begin();
        int b = it->y, c = it->x;
        if (g[b].find({c,a})!=g[b].end()) edges.insert(getE(a, b, c));
        g[a].insert(*it);
        restg[a].erase(it);
    }
    if (flag && g[a].size()>=3){
        int v = 0, cnt=0;
        for(auto p:g[a]) if(cnt++<3) v += p.x;
        vals[a] = v;
        svals.insert(v);
    }
}
void addE(int a, int b, int c){
    if (a>b) swap(a,b);
    AllEdges[{a,b}] = c;
    edges.insert(getE(a,b,c)); //, edges.insert({c, {b,a}});
    g[a].insert({c,b}), g[b].insert({c,a});
    fix(a), fix(b);
}
void removeE(int a, int b){
    if (a>b) swap(a,b);
    int c = AllEdges[{a,b}];
    AllEdges.erase({a,b});
    {
        auto it = edges.find(getE(a,b,c));
        if (it!=edges.end()) edges.erase(it);
    }
    {
        auto it = g[a].find({c,b});
        if (it!=g[a].end()) g[a].erase({c,b});
        else restg[a].erase({c,b});
    }
    {
        auto it = g[b].find({c,a});
        if (it!=g[b].end()) g[b].erase({c,a});
        else restg[b].erase({c,a});
    }
    fix(a), fix(b);
}
int solve(){
    int ans = INF;
    Edge e = *edges.begin();
    int a = e.y.x, b = e.y.y, c = e.x;
    vector<Edge> backup;
    for(auto p:g[a]) {
        Edge e = getE(a, p.y, p.x);
        auto it = edges.find(e);
        if (it!=edges.end()) edges.erase(e), backup.pb(e);
        /*e = flip(e);
        it = edges.find(e);
        if (it!=edges.end()) edges.erase(e), backup.pb(e);*/
    }   
    for(auto p:g[b]){
        Edge e = getE(b, p.y, p.x);
        auto it = edges.find(e);
        if (it!=edges.end()) edges.erase(e), backup.pb(e);
    }   
    if (edges.size()) {
        chkmin(ans, c + edges.begin()->x);
        //cout<<"G: "<<a<<" "<<g[a]<<endl;
        //cout<<"G: "<<b<<" "<<g[b]<<endl;
        //cout<<"E: "<<e<<" "<<*edges.begin()<<endl;
        assert(!inter(e.y, edges.begin()->y));
        //cout<<"BACK: "<<backup<<endl;
    }
    for(auto e:backup) edges.insert(e);
    for(auto p:g[a]){
        if (p.y==b) continue;
        for(auto q:g[b]){
            if (q.y==a || p.y==q.y) continue;
            assert(!inter({a, p.y}, {b, q.y}));
            chkmin(ans, p.x+q.x);
        }
    }
    return min(ans, *svals.begin());
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vals.resize(n+1,-1), g.resize(n+1), restg.resize(n+1), svals.insert(INF);
    loop(i,0,m){
        int a,b,c; cin>>a>>b>>c; //a--, b--; 
        addE(a,b,c);
    }
    cout<<solve()<<endl;
    int q; cin>>q;
    loop(i,0,q){
        int op, a,b,c; cin>>op>>a>>b; //a--, b--;
        if (op==0) {
            removeE(a,b);
        }
        else {
            cin>>c;
            addE(a,b,c);
        }
        cout<<solve()<<endl;
    }
    return 0;
}
/*
color a
cls
g++ g.cpp -o a & a
6 6
1 3 6
4 3 1
1 4 1
2 6 4
2 4 2
5 4 3
4
1 2 5 2
0 1 4
0 3 4
1 6 1 3



*/