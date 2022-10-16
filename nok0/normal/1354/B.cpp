#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
const ll INF = 1e18;
template <typename T>
T pow(T a, long long n, T e = 1) {
    T ret = e;
    while (n) {
        if (n & 1) ret *= a;
        a *= a;
        n >>= 1;
    }
    return ret;
}

string s;

void solve(){
    cin >> s;
    V<> dp(8, INF);
    ll res = INF;
    REP(i, SZ(s)){
        if(s[i] == '1'){
            dp[1] = 1;
            chmin(dp[4], dp[2]);
            chmin(dp[6], dp[3]);
            chmin(dp[7], dp[5]);
            REP(i, 8) if(i != 1) dp[i] += 1;
        }
        if(s[i] == '2'){
            dp[2] = 1;
            chmin(dp[4], dp[1]);
            chmin(dp[5], dp[3]);
            chmin(dp[7], dp[6]);
            REP(i, 8) if(i != 2) dp[i] += 1;
        }
        if(s[i] == '3'){
            dp[3] = 1;
            chmin(dp[5], dp[2]);
            chmin(dp[6], dp[1]);
            chmin(dp[7], dp[4]);
            REP(i, 8) if(i != 3) dp[i] += 1;
        }
        chmin(res, dp[7]);
    }
    cout << ( res > SZ(s) ? 0 : res) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}