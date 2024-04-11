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
    int n, k; cin>>n>>k;
    vi a(n); loop(i,0,n) cin>>a[i], a[i]--;
    vi cnt(n); loop(i,0,n) cnt[a[i]]++;
    //cout<<cnt<<endl;
    auto can = [&](int sz) -> int{
        int cur = 0;
        loop(i,0,sz+1) cur += cnt[i];
        loop(i,0,n-sz+1){
            if (cur-(n-cur) >= k) return i;
            if (i+sz+1<n) cur+=cnt[i+sz+1], cur-=cnt[i];
        }
        return -1;
    };
    int l = 0, r = n-1, mid, ans=n-1;
    while(l<r){
        mid = (l+r)/2;
        if (can(mid)!=-1) ans = mid, r = mid;
        else l = mid + 1;
    }
    int x = can(ans), y = x + ans;
    //cout<<"ANS: "<<ans<<" "<<x<<" "<<y<<endl;
    vii res;
    int cc = 0, last = 0;
    loop(i,0,n){
        if (a[i]>=x && a[i]<=y) cc++;
        else cc--;
        if (cc>0){
            cc = 0, res.pb({last, i}), last = i+1;
        }
    }
    if (res.size()<k) loop(j,0,2) j--;
    res.resize(k), res.back().y = n-1;
    cout<<x+1<<" "<<y+1<<endl;
    for(auto p:res) cout<<p.x+1<<" "<<p.y+1<<endl;
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
g++ b.cpp -o a & a
1
4 4
1 2 3 4


3
2 1
1 2
4 2
1 2 2 2
11 3
5 5 5 1 5 5 1 5 5 5 1


*/