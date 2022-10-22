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

int x;
struct DSU{
    int n;
    vi p, amt;
    vvii g;
    DSU(vi& a): n(a.size()), p(n,-1), amt(a), g(n){}
    void add(int a, int b, int i){
        g[a].pb({b,i});
        g[b].pb({a,i});
    }
    int find(int c){
        return p[c]==-1?c:p[c] = find(p[c]);
    }
    bool uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b) return 0;
        if (g[a].size()>g[b].size()) swap(a,b);
        p[a] = b;
        amt[b] += amt[a] - x;
        for(auto p:g[a]) g[b].pb(p);
        return 1;
    }
    ii move(int a){
        a = find(a);
        while(g[a].size()){
            ii b = g[a].back(); g[a].pop_back();
            b.x = find(b.x);
            if (amt[a] + amt[b.x] >=x && uni(a,b.x)) return b;
        }
        return {-1,-1};
    }
}; 
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m>>x;
    vi a(n); loop(i,0,n) cin>>a[i];
    DSU dsu(a);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        dsu.add(a,b,i);
    }
    set<ii> q;
    loop(i,0,n) q.insert({-a[i], i});
    vi ans;
    while(ans.size()<n-1 && q.size()){
        int cur = q.begin()->y; q.erase(q.begin());
        ii p = dsu.move(cur);
        int b = p.x, i = p.y;
        if (b==-1) return cout<<"NO"<<endl,0;
        ans.pb(i);
        q.erase({-a[b], b});
        int c = dsu.find(cur);
        a[c] = dsu.amt[c];
        q.insert({-a[c], c});
    }
    if (ans.size()!=n-1) return cout<<"NO"<<endl,0;
    cout<<"YES"<<endl;
    for(int x:ans) cout<<x+1<<endl;
    return 0;
}
/*
color a
cls
g++ f.cpp -D_GLIBCXX_DEBUG -o a & a
5 4 1
0 0 0 4 0
1 2
2 3
3 4
4 5


5 6 5
0 9 4 0 10
1 2
1 3
2 3
3 4
1 4
4 5
*/