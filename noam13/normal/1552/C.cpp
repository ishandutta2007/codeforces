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
        for(i/=2;i;i/=2) a[i] = a[2*i]+a[2*i+1];
    }
    int query(int l, int r){
        int res = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res+=a[l++];
            if (r%2==0) res+=a[r--];
        }
        return res;
    }
};
int solve(){
    int n,k; cin>>n>>k;
    vi a(2*n,-1);
    loop(i,0,k){
        int x,y; cin>>x>>y; x--, y--;
        a[x] = a[y] = i;
    }
    vi vec;
    loop(i,0,2*n) if(a[i]==-1) vec.pb(i);
    int sz = vec.size(), best = 0;
    //cout<<"SZ: "<<sz<<" "<<2*(n-k)<<endl;
    //loop(iter,0,sz+1){
    int iter = 0;
        //cout<<"BI: "<<iter<<endl;
    loop(i,0,sz/2) a[vec[(i+iter)%sz]] = a[vec[(i+sz/2+iter)%sz]]= i+k;
    //loop(i,0,2*n) cout<<a[i]<<" "; cout<<endl;
    vi s(n,-1);
    SEG seg(2*n);
    int ans = 0, in = 0;
    loop(i,0,2*n){
        int j = a[i];
        if (s[j]==-1) {
            seg.update(i, 1);
            s[j] = i;
        }
        else {
            seg.update(s[j], 0);
            ans += seg.query(s[j], i);
            s[j] = -1;
        }
    }
    chkmax(best, ans);
        //cout<<"HI: "<<ans<<endl;
    //}
    cout << best << endl;
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
g++ c.cpp -D_GLIBCXX_DEBUG -o a & a
4
4 2
8 2
1 5
1 1
2 1
2 0
10 6
14 6
2 20
9 10
13 18
15 12
11 7


*/