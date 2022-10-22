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

int solve(vi &a, vvi& mexs, int off){
    int n = a.size();
    vi dp(n+1); dp[off] = 0;
    loop(i,off+1,n+1){
        loopr(j,off,i){
            chkmax(dp[i], dp[j]+1+mexs[j][i-1]);
        }
    }
    //cout<<"DP: "<<dp<<endl;
    int ans = 0;
    loop(i,off,n+1) ans+=dp[i];
    return ans;
}
int solve(){
    int n; cin >> n;
    vi a(n); loop(i,0,n) cin>>a[i];
    vvi mexs(n, vi(n));
    loop(i,0,n){
        vi arr;
        loop(j,i,n){
            arr.pb(a[j]);
            sort(all(arr)); arr.resize(unique(all(arr))-arr.begin());
            int &c = mexs[i][j];
            while(c<arr.size() && c==arr[c])  c++;
        }
    }
    //cout<<mexs<<endl;
    int ans = 0;
    loop(i,0,n){
        ans += solve(a, mexs, i);
        //cout<<"ANS: "<<ans<<endl;
        /*loop(i,1,a.size()) a[i-1] = a[i];
        a.pop_back();*/
    }
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
g++ b.cpp -o a & a
4
2
1 2
3
2 0 1
4
2 0 5 1
5
0 1 1 0 1


*/