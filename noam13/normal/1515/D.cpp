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
    int n,l,r; cin>>n>>l>>r;
    vi a(l), b(r);
    vi ca(n), cb(n);
    loop(i,0,l) cin>>a[i], a[i]--, ca[a[i]]++;
    loop(i,0,r) cin>>b[i], b[i]--, cb[b[i]]++;
    int ans = 0;
    int ll = 0, rr = 0, lll = 0, rrr = 0;
    loop(i,0,n){
        int amt = min(ca[i], cb[i]);
        ca[i]-=amt, cb[i]-=amt;
        ll += ca[i];
        rr += cb[i];
        lll += ca[i]/2;
        rrr += cb[i]/2;
        /*ans+=ca[i]/2;
        ll += ca[i]%2;
        ans+=cb[i]/2;
        rr += cb[i]%2;*/
    }
    int amt = min(ll, rr);
    ans += amt, ll-=amt, rr-=amt;
    amt = min(ll/2, lll);
    ans += amt, ll-=amt*2;
    amt = min(rr/2, rrr);
    ans += amt, rr-=amt*2;
    ans += ll+rr;
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
g++ d.cpp -D_GLIBCXX_DEBUG -o a & a
4
6 3 3
1 2 3 2 2 2
6 2 4
1 1 2 2 2 2
6 5 1
6 5 4 3 2 1
4 0 4
4 4 4 3

*/