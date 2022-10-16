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
const  ll NAX = 1e5 + 10;

ll n, l, r;

V<> v(NAX);

void solve(){
    cin >> n >> l >> r; l--; r--;
    ll st = 0, sum = 0;
    for(int i = 0; i < n and sum + 2 * (n - i - 1) <= l; i++){
        st++;
        sum += 2 * (n - i - 1);
    }
    for(ll i = l; i <= r; i++){
        if(i == n * (n - 1)){
            cout << 1;
            break;
        }
        if((i % 2)){
            cout << (i - max(sum - 1, 0ll) + 3) / 2 + st  << " ";
            if((i - max(sum - 1, 0ll) + 3) / 2 + st == n){
                st++;
                sum += 2 * (n - st);
            }
        }
        else cout << st + 1 << " ";
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}