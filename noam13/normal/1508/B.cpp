#include <bits/stdc++.h>
#define int int64_t
#define vi vector<int>
#define ii pair<int,int>
#define vb vector<bool>
#define vvi vector<vi>
#define vvb vector<vb>
#define vii vector<ii>
#define vvii vector<vii>
#define x first
#define y second
#define pb push_back
#define loop(i,s,e) for(int i=s;i<e;i++)
#define loopr(i,s,e) for(int i=e-1;i>=s;i--)
#define chkmax(a,b) a=max(a,b)
#define chkmin(a,b) a=min(a,b)
#define all(x) x.begin(),x.end()
using namespace std;
const int INF = 2e18, MOD = 1e9+7;

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
    vi dp(n+1);
    dp[0] = dp[1] = 1;
    int s = 2;
    loop(i,2,n+1){
        dp[i] = s;
        s+= dp[i];
        chkmin(s, INF);
    }
    //loop(i,0,n) pref[i+1] = pref[i] + dp[i];
    k--;
    vi a(n);
    loop(i,0,n){
        int j = i;
        while(j+1<n && dp[n-j-1]<=k){
            k -= dp[n-j-1];
            j++;
        }
        //cout<<"IJ: "<<i<<" "<<j<<endl;
        loop(k,0,j-i+1) a[i+k] = j - k;
        //cout<<"BI: "<<endl;
        i = j;
        //a[i] = i;
    }
    if (k) return cout<<-1<<endl,0;
    loop(i,0,n) cout<<a[i]+1<<" "; cout<<endl;
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
g++ b.cpp -D_GLIBCXX_DEBUG -o b & b
5
1 1
1 2
3 3
6 5
3 4


*/