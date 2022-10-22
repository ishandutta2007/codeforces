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

/*int gcd(int a, int b){
    if (a<b) swap(a,b);
    if (!b) return a;
    return gcd(b, a%b);
}*/
int solve(){
    int n,m; cin>>n>>m;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi b(m); loop(i,0,m) cin>>b[i];
    int g = b[0];
    loop(i,1,m) g = __gcd(g, b[i]);
    vi cnt(g), mini(g, INF);
    loop(i,0,n){
        int j = i%g;
        if (a[i]<0) cnt[j]++;
        chkmin(mini[j], llabs(a[i]));
    }
    int ans = 0; loop(i,0,n) ans+=llabs(a[i]);
    int x = 0, y = 0;
    loop(i,0,g){
        if (cnt[i]%2==1) x+=mini[i];
        else y+=mini[i];
    }
    ans -= 2*min(x,y);
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
3
6 2
0 6 -2 1 -4 5
1 2
7 1
1 -1 1 -1 1 -1 1
2
6 3
-1000000000 -1000000000 -1000000000 -1000000000 -1000000000 -1
2 3 4

*/