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


/*struct SEG{
    int n, sz;
    vi a;
    SEG(int n): n(n){
        for(sz=1;sz<n;sz*=2);
        a.resize(2*sz);
    }
    void update(int i, int x){
        a[i+=sz]=x;
        for(i/=2;i;i/=2) a[i] = __gcd(a[2*i], a[2*i+1]);
    }
    int query(int l, int r){
        int res = 0;
        for(l+=sz, r+=sz; l<=r; l/=2, r/=2){
            if (l%2) res = __gcd(res, a[l++]);
            if (r%2==0) res = __gcd(res, a[r--]);
        }
        return res;
    }
};*/
int32_t main(){
    ios_base::sync_with_stdio(false);
    int n; cin>>n;
    vi a(n); loop(i,0,n) cin>>a[i];
    vi pref(n+1); loop(i,0,n) pref[i+1]=pref[i]+(i%2?-1:1)*a[i];
    int ans = 0;
    loop(i,0,n){
        if (i%2==1) continue;
        int mini = a[i]-1;
        loop(j,i+1,n){
            if (j%2==0) continue;
            int bef = pref[j]-pref[i], aft=pref[j+1]-pref[i];
            if (aft<=mini){
                ans+=mini-max(aft, 0LL)+1;
            }
            chkmin(mini, aft);
            if (aft<0) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
/*
color a
cls
g++ c.cpp -o a & a
5
4 1 2 3 1


*/