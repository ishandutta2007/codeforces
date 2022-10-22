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

template <class A, class B> pair<A,B> operator+(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x+b.x, a.y+b.y}; }
template <class A, class B> pair<A,B> operator-(const pair<A,B>& a, const pair<A,B>& b) {
    return {a.x-b.x, a.y-b.y}; }
template <class A, class B> istream& operator>>(istream& is, pair<A,B>& a) {
    return is >> a.x >> a.y; }
template <class A, class B> ostream& operator << (ostream& os, const pair<A,B>& a) {
    return os << "< " << a.x << " , " << a.y << " >"; }

template<class T> ostream &operator<<(ostream &os, vector<T> v) { os << '['; if (!v.empty()) { os << v[0]; loop(i, 1, v.size()) os << ',' << v[i]; } return os << ']'; }
template<class T> ostream &operator<<(ostream &os, set<T> v) { os << '{'; if (!v.empty()) { os << *v.begin(); for(auto it = ++v.begin(); it != v.end(); ++it) os << ',' << *it; } return os << '}'; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
auto DIST = uniform_int_distribution<int>(0, INF);


struct Seg{
    int n, sz;
    vi a;
    Seg(int n=0): n(n){
        for(sz = 1; sz<n; sz*=2);
        a.resize(2*sz, INF);
    }
    int query(int l, int r){
        int ans = INF;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) chkmin(ans, a[l++]);
            if (r%2==0) chkmin(ans, a[r--]);
        }
        return ans;
    }
    void update(int i, int x){
        i+=sz;
        chkmin(a[i], x);
        for(i/=2; i; i/=2) a[i] = min(a[2*i], a[2*i+1]);
    }
};
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi right(n, n);
    loop(it, 0, 2){
        // find 3412
        vi st = {0};
        vvi p12(n);
        loop(i,1,n){
            while(st.size() && a[st.back()] > a[i]) st.pop_back();
            if (st.size()) p12[st.back()].pb(i);
            st.pb(i);
        }
        st = {n-1};
        vvi p34(n);
        loopr(i,0,n-1){
            while(st.size() && a[st.back()] < a[i]) st.pop_back();
            if (st.size()) p34[st.back()].pb(i);
            st.pb(i);
        }
        Seg seg(n+1);
        loopr(i,0,n){
            // query p34[i]
            for(int j:p34[i]){
                assert(a[j] < a[i]);
                chkmin(right[j], seg.query(0, a[j]-1));
            }
            // add p12[i]
            for(int j:p12[i]){
                assert(a[i] < a[j]);
                seg.update(a[j], j);
            }
        }

        loop(i,0,n) a[i] = n - a[i] + 1;
    }
    loopr(i,1,n) chkmin(right[i-1], right[i]);
    int ans = 0;
    loop(i,0,n) if (right[i]>=i) ans += right[i] - i;
    cout << ans << endl;
    return 0;
}
/*
color a
cls
g++ dd.cpp -o a & a
6
4 5 2 6 1 3



3
2 3 1


*/