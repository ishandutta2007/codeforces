#include <bits/stdc++.h>
using namespace std;
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
const int INF = 1e9, MOD = 1e9 + 7;

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
        p[a] = b, sz[b]+=sz[a];
        return 1;
    }
};
int n, m, k;
vii edges;
vi wgts;
vi max_d;
struct Gmat{
    DSU dsu;
    Gmat(): dsu(n){}
    bool insert(int a, int b){
        return dsu.uni(a,b);
    }
    bool insert(int i){
        return insert(edges[i].x,edges[i].y);
    }
    bool indep(int a, int b){
        return dsu.find(a)!=dsu.find(b);
    }
    bool indep(int i){
        return indep(edges[i].x, edges[i].y);
    }
};
struct Cmat{
    vi cnt;
    Cmat(): cnt(k){}
    bool insert(int a, int b){
        if (a<k && ++cnt[a]>max_d[a]) return 0;
        if (b<k && ++cnt[b]>max_d[b]) return 0;
        return 1;
    }
    bool insert(int i){
        return insert(edges[i].x, edges[i].y);
    }
    bool indep(int a, int b){
        if (a<k && cnt[a]>=max_d[a]) return 0;
        if (b<k && cnt[b]>=max_d[b]) return 0;
        return 1;
    }
    bool indep(int i){
        return indep(edges[i].x, edges[i].y);
    }
};


vb ins;
vi find_path(int n, vector<pair<ii, int>> es, int s, int t){
    vi dist(n, INF); dist[s] = 0;
    vi prv(n, -1);
    loop(i,0,n) for(auto e:es){
        if (dist[e.x.x] + e.y < dist[e.x.y]){
            dist[e.x.y] = dist[e.x.x] + e.y;
            prv[e.x.y] = e.x.x;
        }
    }
    if (dist[t]>=INF/2) return vi(0);
    vi path(1, t); int cur = t;
    while(cur!=s){
        cur = prv[cur];
        path.pb(cur);
    }
    reverse(all(path));
    return path;
}

bool augment(Gmat baseg, Cmat basec){
    vector<pair<ii, int>> g;
    int S = m, T = m+1;
    vb ok1(m,1), ok2(m,1);
    auto getW = [](int w){
        return w*1000 + 1;
    };
    loop(i,0,m) if(!ins[i]){ 
        Gmat gmat = baseg; Cmat cmat = basec;
        loop(j,0,m) if(ins[j]) gmat.insert(j), cmat.insert(j);
        // check for source - indep in gmat
        if (gmat.indep(i)){
            g.pb({{S, i}, 0});
            ok1[i] = 0;
        }
        // check for sink - indep in cmat
        if (cmat.indep(i)){
            g.pb({{i, T}, getW(wgts[i])});
            ok2[i] = 0;
        }
    }
    loop(i,0,m) if (ins[i]){
        Gmat gmat = baseg; Cmat cmat = basec;
        loop(j,0,m) if(ins[j] && j!=i) gmat.insert(j), cmat.insert(j);
        loop(j,0,m) if(!ins[j]){
            if (ok1[j] && gmat.indep(j)){
                g.pb({{i,j}, getW(-wgts[i])});
            }
            if (ok2[j] && cmat.indep(j)){
                g.pb({{j,i}, getW(wgts[j])});
            }
        }
    }
    vi path = find_path(m+2, g, S, T);
    if (!path.size()) return 0;
    loop(i,1,int(path.size())-1){
        ins[path[i]]=ins[path[i]]^1;
    }
    return 1;
}
int solve(Gmat gmat, Cmat cmat, int need){
    ins = vb(m);
    loop(i,0,need){
        //cout<<"NEED: "<<i+1<<" / "<<need<<endl;
        if (!augment(gmat, cmat)) return INF;
    }
    int w = 0, cnt=0;
    loop(i,0,m) if(ins[i]) w+=wgts[i], cnt++;
    // assert(cnt==need);
    return w;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    max_d = vi(k); loop(i,0,k) cin>>max_d[i];
    vector<pair<int, ii>> kes, es;
    loop(i,0,n) loop(j,i+1,n){
        int w; cin>>w;
        if (i<k && j<k) kes.pb({w,{i,j}});
        else if (i<k || j<k) edges.pb({i,j}), wgts.pb(w);
        else es.pb({w, {i,j}});
    }
    sort(all(es));
    DSU dsu(n);
    for(auto e:es){
        if (dsu.uni(e.y.x, e.y.y)){
            edges.pb(e.y), wgts.pb(e.x);
        }
    }
    m = edges.size();
    int ans = INF;
    int sz = kes.size();
    loop(mask,0,(1<<sz)){
        Gmat gmat; Cmat cmat;
        int w = 0, ok = 1, cnt = 0;
        loop(i,0,sz) if(mask&(1<<i)){
            int a = kes[i].y.x, b = kes[i].y.y;
            w+=kes[i].x, cnt++;
            if (!gmat.insert(a,b) || !cmat.insert(a,b)) ok = 0;
        }
        if (!ok) continue;
        //cout<<"HI: "<<endl;
        int res = solve(gmat, cmat, n-1-cnt);
        //cout<<"BI: "<<endl;
        chkmin(ans, res + w);
    }
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ h.cpp -D_GLIBCXX_DEBUG -o a & a
10 5
5 3 4 2 1
29 49 33 12 55 15 32 62 37
61 26 15 58 15 22 8 58
37 16 9 39 20 14 58
10 15 40 3 19 55
53 13 37 44 52
23 59 58 4
69 80 29
89 28
48




*/