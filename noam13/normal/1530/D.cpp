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


int solve(){
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i], a[i]--;
    vi b(n, -1);
    vi bb(n, -1);
    loop(i,0,n){
        int p = bb[a[i]];
        b[i] = a[i];
        bb[a[i]] = i;
        if (p!=-1) b[p] = -1;
    }
    vb check(n);
    loop(i,0,n) if(b[i]!=-1) check[b[i]] = 1;
    vi vec;
    loop(i,0,n) if(!check[i]) vec.pb(i);
    int j = 0;
    loop(i,0,n) if(b[i]==-1) b[i] = vec[j++], bb[b[i]] = i;
    loop(i,0,n)if (b[i]==i){
        int x = bb[a[i]];
        swap(b[i], b[x]);
        bb[b[i]] = i;
        bb[b[x]] = x;
    }
    int ans = 0;
    loop(i,0,n) ans+=a[i]==b[i];
    cout<<ans<<endl;
    loop(i,0,n) cout<<b[i]+1<<" "; cout<<endl;
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
2
3
2 1 2
7
6 4 6 2 4 5 6


*/