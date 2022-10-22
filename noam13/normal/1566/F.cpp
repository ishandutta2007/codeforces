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
    int n,m; cin>>n>>m;
    set<int> s; s.insert(INF);
    vi a(n+1); loop(i,0,n) cin>>a[i], s.insert(a[i]);
    a[n] = INF;
    sort(all(a));
    vii segs;
    loop(i,0,m){
        int l,r; cin>>l>>r;
        if (*s.lower_bound(l)>r) segs.pb({l,r});
    }
    m = segs.size();
    sort(all(segs));
    //cout<<"M: "<<m<<endl;
    // cout<<segs<<endl;
    vvii ss(n+1); int ind = 0;
    loop(i,0,n+1){
        while(ind<m && segs[ind].y < a[i]) ss[i].pb(segs[ind++]);
    }
    //cout<<ss<<endl;
    vvi dp(n, vi(2, INF));
    int mini = a[0]; for(auto s:ss[0]) chkmin(mini, s.y);
    dp[0][0] = a[0] - mini, dp[0][1] = 2 * dp[0][0];
    
    loop(i,1,n){
        // between i-1 and i, in ss[i]
        loop(b1,0,2) loop(b2,0,2){ 
            // i-1 pays b1+1, i pays b2+1
            vii &vec = ss[i];
            int m = vec.size();
            vi mini(m+1, a[i]);
            loopr(i,0,m) mini[i] = min(mini[i+1], vec[i].y);
            int val = (a[i]-mini[0])*(b2+1);
            loop(j,0,m){
                chkmin(val, (vec[j].x-a[i-1])*(b1+1) +
                            (a[i]-mini[j+1])*(b2+1));
            }
            chkmin(dp[i][b2], dp[i-1][!b1] + val);
        }
    }
    int maxi = a[n-1]; for(auto p:ss[n]) chkmax(maxi, p.x);
    int dif = maxi - a[n-1];
    int ans = min(dp[n-1][0]+2*dif, dp[n-1][1]+dif);
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
g++ f.cpp -o a & a
2
4 11
2 6 14 18
0 3
4 5
11 15
3 5
10 13
16 16
1 4
8 12
17 19
7 13
14 19
4 12
-9 -16 12 3
-20 -18
-14 -13
-10 -7
-3 -1
0 4
6 11
7 9
8 10
13 15
14 18
16 17
18 19


*/