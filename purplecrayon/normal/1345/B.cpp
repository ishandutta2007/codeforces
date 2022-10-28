#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)v.size()
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 4e3+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, INF = 1e9+10, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
// const ll INF = 1e18+10;

unordered_map<ll, ll> dp;

ll f(ll x){
    if (dp.count(x)) return dp[x];
    if (x == 0) return 0;
    if (x == 1) return 2;
    return dp[x] = f(x-1)+3+f(x-1)-f(x-2);
}
ll bld(ll x){
    ll lo = 0, hi = 2e6+10, mid = (lo+hi)/2;
    while (lo < mid && mid < hi){
        if (f(mid) <= x) lo = mid;
        else hi = mid;
        mid = (lo+hi)/2;
    }
    return f(lo);
}
void solve(){
    ll n; cin >> n;
    int ans = 0;
    while (n >= 2){
        ll m = bld(n);
        n -= m, ans++;
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1; 
    cin >> t; 
    while (t--) solve();
}