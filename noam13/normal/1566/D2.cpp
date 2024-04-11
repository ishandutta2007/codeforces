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

struct SEG{
    int n, sz;
    vi a;
    SEG(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i, int x){
        a[i+=sz]=x;
        for(i/=2;i;i/=2) a[i] = a[2*i] + a[2*i+1];
    }
    int query(int l, int r){
        int res = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res += a[l++];
            if (r%2==0) res += a[r--];
        }
        return res;
    }
};
int solve(){
    int n,m; cin>>n>>m;
    vii a(n*m); 
    map<int, vi> inds;
    loop(i,0,n*m) {
        cin>>a[i].x, a[i].y = -i;
        inds[a[i].x];
        inds[a[i].x].pb(i);
    }
    vvi ts(1);
    for(auto p:inds){
        vi vec = p.y; reverse(all(vec));
        while(ts.back().size() + vec.size() > m){
            int amt = m - ts.back().size();
            vi v; loop(i,0,amt) v.pb(vec.back()), vec.pop_back();
            while(v.size()) ts.back().pb(v.back()), v.pop_back();
            ts.pb(vi(0));
        }
        loop(i,0,vec.size()) ts.back().pb(vec[i]);
    }
    //loop(i,0,n) {loop(j,0,m) cout<<ts[i][j]<<" "; cout<<endl;}
    //sort(all(a));
    // vi p(n); loop(i,0,n) p[-a[i].y] = i;
    int ans = 0;
    loop(i,0,n){
        SEG seg(m);
        map<int, int> conv;
        loop(j,0,m) conv[ts[i][j]];
        int cnt = 0;
        for(auto &p:conv) p.y = cnt++;
        loop(j,0,m){
            int t = conv[ts[i][j]];
            ans += seg.query(0, t);
            seg.update(t, 1);
        }
    }
    cout << ans << endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
7
1 2
1 2
3 2
1 1 2 2 3 3
3 3
3 4 4 1 1 1 1 1 2
2 2
1 1 2 1
4 2
50 50 50 50 3 50 50 50
4 2
6 6 6 6 2 2 9 6
2 9
1 3 3 3 3 3 1 1 3 1 3 1 1 3 3 1 1 3



*/