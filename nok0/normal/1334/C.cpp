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

ll n;

void solve(){
    cin >> n;
    V<> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];
    ll sumh = 0;
    REP(i, n) sumh += a[i];
    ll non = 0, loss = INF;
    REP(i, n){
        if(min(b[i], a[(i + 1) % n]) < loss){
            non = i;
            loss = min(b[i], a[(i + 1) % n]);
        }
    }
    ll st = (non + 1) % n;
    ll res = a[st];
    REP(i, n){
        if(i == non) continue;
        res += max(a[(i + 1) % n] - b[i], 0ll);
    }
    cout << res << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}