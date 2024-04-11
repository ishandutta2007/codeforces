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

template <class A, class B> pair<A,B> operator+(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

struct BINARY{
    int n, LOGN=1;
    vvi g;
    vi depth;
    vvi anc;
    BINARY(vvi& _g, int s=0):g(_g), n(_g.size()){
        for(int i=1;i<=n;i<<=1,++LOGN);
        depth.resize(n,0);
        anc.resize(n,vi(LOGN,-1));
        dfs(s);
    }
    void dfs(int cur, int p=-1,int d=0){
        anc[cur][0] = p;
        for(int i=1;anc[cur][i-1]!=-1;i++){
            anc[cur][i] = anc[anc[cur][i-1] ][i-1];
        }
        depth[cur] = d;
        for(auto nei:g[cur]){
            if (nei==p) continue;
            dfs(nei, cur, d+1);
        }
    }
    int lift(int a, int d){
        for(int i=LOGN-1;i>=0;--i){
            if (a==-1) return a;
            if (d>= (1<<i)){
                d-=(1<<i);
                a = anc[a][i];
            }
        }
        return a;
    }
    int child_of_a(int a, int b){
        //cout<<"DD: "<<(depth[b] - depth[a] - 1)<<endl;
        return lift(b, depth[b] - depth[a] - 1);
    }
};

struct DSU{
    vi p, sz;
    DSU(int n): p(n,-1), sz(n,1){}
    int find(int c){
        if (p[c]==-1) return c;
        return p[c] = find(p[c]);
    }
    bool uni(int a, int b){
        a = find(a), b = find(b);
        if (a==b) return 0;
        if (sz[a]>sz[b]) swap(a,b);
        p[a] = b;
        sz[b] += sz[a];
        return 1;
    }
};

vvi g;
vi st, et, d; int tt=0;
vi ord;
void dfs(int cur, int p=-1, int dep=0){
    st[cur] = tt++, d[cur] = dep;
    ord.pb(cur);
    for(int nei:g[cur]) if(nei!=p) dfs(nei, cur, dep+1);
    et[cur] = tt;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n, m; cin>>n>>m;
    vii es;
    g.resize(n);
    DSU dsu(n);
    loop(i,0,m){
        int a,b; cin>>a>>b; a--, b--;
        if (dsu.uni(a,b)){
            g[a].pb(b);
            g[b].pb(a);
        }
        else es.pb({a,b});
    }
    BINARY bin(g, 0);
    st = et = d = vi(n);
    dfs(0);
    vi vec(n+1);
    int need = 0;
    auto add = [&](int l, int r, int dd){
        vec[l]+=dd, vec[r]-=dd;
    };
    for(auto pp:es){
        int a = pp.x, b = pp.y;
        if (d[a]>d[b]) swap(a,b);
        if (st[a]<=st[b] && et[b]<=et[a]){ // a anc of b
            int ch_a = bin.child_of_a(a, b);
            // cout<<"HI: "<<a<<" "<<b<<" "<<ch_a<<endl;
            add(st[ch_a], et[ch_a], -1);
            add(st[b], et[b], 1);
        }
        else {
            add(st[a], et[a], 1);
            add(st[b], et[b], 1);
            need++;
        }
    }
    loop(i,0,n) vec[i+1] += vec[i];
    vi ans(n);
    loop(i,0,n) if(vec[i]==need) ans[ord[i]] = 1;
    loop(i,0,n) cout<<ans[i];
    cout<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4


*/