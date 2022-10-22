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
#define loop(i,s,e) for(int i=(s);i<(e);(i)++)
#define loopr(i,s,e) for(int i=(e)-1;i>=(s);(i)--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
const int INF = 1e18, MOD = 1e9+7;

template <class A, class B> pair<A,B> operator+(pair<A,B>& a, pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(pair<A,B>& a, pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << a.x << ' ' << a.y; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);

struct DSU{
    int n;
    vi p, sz, d, psz, have;
    DSU(int n): n(n), p(n,-1), sz(n,1), d(n,0), psz(n,1), have(n, 0){}
    bool t = 0;
    int find(int c){
        if (p[c]==-1) return c;
        bool bt = t;
        t ^= d[c];
        int v = find(p[c]);
        d[c] = bt ^ t;
        return p[c] = v;
    }
    int ans = 0;
    int get(int a){ 
        if (have[a]==1) return psz[a];
        if (have[a]==-1) return sz[a]-psz[a];
        return min(psz[a], sz[a]-psz[a]);
    }
    void sethave(int a, bool c){
        t = c;
        a = find(a);
        ans -= get(a);
        have[a] = (t?1:-1);
        ans += get(a);
    }
    void uni(int a, int b, bool c){
        t = c;
        a = find(a);
        bool tt = t;
        b = find(b);
        if (a==b) return ;
        if (sz[a]>sz[b]) swap(a,b);
        ans -= get(a) + get(b);
        p[a] = b, d[a] = t;
        sz[b] += sz[a];
        if (d[a]) psz[b] += sz[a] - psz[a];
        else psz[b] += psz[a];
        if (have[a]){
            have[b] = (d[a]?-1:1) * have[a];
        }
        ans += get(b);
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,k; cin>>n>>k;
    string s; cin>>s; for(auto &c:s) c-='0';
    vvi in(n);
    vvi a(k);
    loop(i,0,k){
        int c; cin>>c;
        a[i].resize(c);
        loop(j,0,c) cin>>a[i][j], a[i][j]--, in[a[i][j]].pb(i);
    }
    DSU dsu(k);
    loop(i,0,n){
        if (in[i].size()==1){
            dsu.sethave(in[i][0], !s[i]);
        }
        else if (in[i].size()==2){
            dsu.uni(in[i][0], in[i][1], !s[i]);
        }
        cout << dsu.ans << endl;
    }
    return 0;
}
/*
color a
cls
g++ temp.cpp -D_GLIBCXX_DEBUG -o a & a
8 6
00110011
3
1 3 8
5
1 2 5 6 7
2
6 8
2
3 5
2
4 7
1
2




7 3
0011100
3
1 4 6
3
3 4 7
2
2 3

*/