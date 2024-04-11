#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
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

const int MAX = 2e6;
int sz;
int t[MAX];
ll rr[MAX];
vi g[MAX];
/*struct Data{
    int sz;
    vi t;
    vector<ll> r;
    vvi g;
};*/
pair<pair<ll, ll>, int> segs[MAX];
int solve(int lseg, int rseg ,ll l, ll r){
    //cout<<"SEGS: "<<l<<" "<<r<<" "<<segs.size()<<endl;
    //for(auto x:segs) cout<<x<<endl; cout<<endl;
    if (lseg==rseg){
        if (sz>=MAX) exit(1);
        t[sz] = INF, rr[sz] = r, g[sz] = vi(0);
        sz++;      
        return 1;
    }
    if (rseg-lseg==1 && segs[lseg].x.x <= l && segs[lseg].x.y >= r){
        if (sz>=MAX) exit(1);
        t[sz] = segs[lseg].y,  rr[sz] = r, g[sz] = vi(0);
        sz++;   
        return 1;
    }
    ll mid = (l+r+1)/2;
    int nr = lseg;
    while(nr<rseg && segs[nr].x.x<mid) nr++;
    int befl = sz;
    int lsz = solve(lseg, nr, l, mid-1);
    int nl = rseg;
    while(nl>lseg && segs[nl-1].x.y>=mid) nl--;
    int befr = sz;
    int rsz = solve(nl, rseg, mid, r);
    // create between edges
    int i = befl, j = befr;
    while(i<befl+lsz && j<befr+rsz){
        g[i].pb(j), g[j].pb(i);
        if (rr[i]-l == rr[j]-mid) i++, j++;
        else if (rr[i]-l < rr[j]-mid) i++;
        else j++;
    }
    return lsz + rsz;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,q; cin>>n>>q;
    vector<pair<pair<ll, ll>, int>> qur;
    int segsz = 0;
    loop(i,0,q){
        string s; cin>>s;
        ll a,b; cin>>a>>b;
        if (s=="ask"){
            qur.pb({{a,b}, i});
        }
        else{
            segs[segsz++]= {{a,b},i};
        }
    }
    sort(segs, segs+segsz);
    ll N = ll(1)<<n;
    solve(0, segsz, 0, N-1);
    //cout<<"L: "<<l<<endl; cout<<"R: "<<r<<endl; cout<<"T: "<<t<<endl;
    //cout<<"G: "<<res.g<<endl;
    vvi hist(q+1);
    loop(i,0,sz) {
        if (t[i]==INF) hist[q].pb(i);
        else hist[t[i]].pb(i);
    }
    vii ord;
    loopr(x,0,q+1) for(int i:hist[x]) ord.pb({x,i});
    DSU dsu(sz);
    reverse(all(qur));
    vi ans; int i = 0;
    for(auto qq:qur){
        while(i<sz && ord[i].x>qq.y){
            // enter i
            int cur = ord[i].y;
            for(auto nei:g[cur]) if(t[nei]>=t[cur]){
                dsu.uni(cur, nei);
            }
            i++;
        }
        ll a = qq.x.x, b = qq.x.y;
        int aa = lower_bound(rr, rr+sz, a) - rr;
        int bb = lower_bound(rr, rr+sz, b) - rr;
        ans.pb(dsu.find(aa)==dsu.find(bb));
        //cout<<"QUR: "<<i<<" "<<aa<<" "<<bb<<endl;
    }
    reverse(all(ans));
    for(int x:ans) cout<<x<<endl;
    return 0;
}
/*
color a
cls
g++ g.cpp -D_GLIBCXX_DEBUG -o a & a
6 10
block 12 26
ask 44 63
block 32 46
ask 1 54
block 27 30
ask 10 31
ask 11 31
ask 49 31
block 31 31
ask 2 51




3 3
ask 0 7
block 3 6
ask 0 7




*/