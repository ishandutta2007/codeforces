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
const int INF = 1e18, MOD = 998244353;

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

void add(int& a, int b){ a = (a+b)%MOD;}
struct SEG{
    int n, sz;
    vi a;
    SEG(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    int query(int i){
        int res = 0;
        for(i+=sz;i;i/=2) add(res, a[i]);
        return res;
    }
    void update(int l, int r, int x){
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) add(a[l++], x);
            if (r%2==0) add(a[r--],x);
        }
    }
};
int solve(){
    int n; cin>>n; n++;
    vi x(n),y(n),s(n);
    loop(i,1,n) cin>>x[i]>>y[i]>>s[i];
    SEG seg(n);
    int ans = 1;
    loop(i,1,n){
        add(ans, x[i]-x[i-1]);
        seg.update(0, i-1, x[i]-x[i-1]);
        int ind = lower_bound(all(x), y[i]) - x.begin();
        int cur = seg.query(ind) + x[ind]-y[i];
        if (s[i]) add(ans, cur);
        seg.update(0, i, cur);
        //cout<<"I: "<<i<<" "<<ans<<endl;
        //loop(j,0,i) cout<<seg.query(j)<<" "; cout<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    int t=1;
    loop(i,0,t) solve();
    return 0;
}
/*
color a
cls
g++ f.cpp -D_GLIBCXX_DEBUG -o a & a
4
3 2 0
6 5 1
7 4 0
8 1 1


*/