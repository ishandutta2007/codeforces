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

/*int solve(vii a, vii b){
    int n = a.size(), b = b.size(), ans = 0;
    
    return ans;
}*/
int solve(vii& p){
    int n = p.size(), ans = 0;
    // vi v(n); loop(i,0,n) v[i] = 
    int cnt[2][2];
    loop(a,0,2) loop(b,0,2) cnt[a][b] = 0;
    loop(i,0,n){
        int a = abs(p[i].x)%2, b = abs(p[i].y) % 2;
        if (!a && !b) ans += n-1 - cnt[a][b];
        else ans += cnt[a][b];
        cnt[a][b]++;
    }
    return ans;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vii a(n);
    loop(i,0,n) cin>>a[i], a[i].x/=2, a[i].y/=2;
    int ans = 0;
    loop(i,2,n){
        vii p;
        loop(j,0,i) p.pb(a[j]-a[i]);
        ans += solve(p);
    }
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ d.cpp -o a & a
3
0 0
2 0
0 4

*/