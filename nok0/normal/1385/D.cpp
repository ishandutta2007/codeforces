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

int n;
string s;

int cfs(int n, int c, int sz){
    ll cnt = 0;
    for(int i = n; i < n + sz; i++) if(s[i] - 'a' != c) cnt++;
    return cnt;
}

int dfs(int n, int c, int sz){
    if(sz == 1) return (s[n] - 'a' == c ? 0 : 1);
    return min(cfs(n, c, sz / 2) + dfs(n + sz / 2, c + 1, sz / 2), dfs(n, c + 1, sz / 2) + cfs(n + sz / 2, c, sz / 2));
}

void solve(){
    cin >> n >> s;
    ll res = 0;
    cout << dfs(0, 0, n) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}