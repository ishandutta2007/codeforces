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

vi dijkstra(int n, vvi& tab, int s){
    vi d(n, INF); d[s] = 0;
    priority_queue<ii, vii, greater<ii>> q; q.push({0,s});
    while(q.size()){
        ii tmp = q.top(); q.pop();
        int cur = tmp.y, dd = tmp.x;
        if (d[cur]<dd) continue;
        int j = 0;
        int bonus=0;
        loop(i,0,n){
            int ind = ((i-dd)%n + n)%n;
            int v = d[cur] + tab[cur][ind];
            if (v<d[i]){
                d[i] = v;
                q.push({d[i], i});
            }
        }
    }
    return d;
}
vi preproces(int n, vii& v){
    sort(all(v));
    int best = INF; //last.y - (last.x-n);
    for(auto p:v){
        chkmin(best, p.y - p.x + n);
    }
    int j = 0;
    vi res(n, INF);
    loop(i,0,n){
        while(j<v.size() && v[j].x<=i){
            chkmin(best, v[j].y - v[j].x);
            j++;
        }
        res[i] = i + best;
    }
    return res;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    vvii g(n);
    loop(i,0,m){
        int a,b,c; cin>>a>>b>>c;
        g[a].pb({b, c});
    }
    vvi tab(n);
    loop(i,0,n) {
        tab[i] = preproces(n, g[i]);
        /*int sz = g[i].size();
        loop(j,0,sz) g[i].pb({g[i][j].x+n, g[i][j].y});*/
    }
    vvi d(n);
    loop(i,0,n) d[i] = dijkstra(n,tab, i);
    loop(i,0,n) {loop(j,0,n) cout<<d[i][j]<<" "; cout<<endl;}
    return 0;
}
/*
color a
cls
g++ d.cpp -D_GLIBCXX_DEBUG -o a & a
3 4
0 1 1
0 2 3
1 0 1
2 0 1

*/