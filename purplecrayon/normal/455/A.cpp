#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
const int MAXN = 1e5+10, MAXM = 2e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 810;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 9e18+10;

int n, a[MAXN];
ll dp[MAXN];
map<int, int> mp;
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; mp[a[i]]++;
    }
    const int mx=1e5;
    dp[mx+1]=dp[mx+2]=0;
    for (ll i=mx; i >= 0; i--){
        dp[i] = dp[i+1];
        if (mp.count(i+1)) dp[i] = max(dp[i], (i+1)*mp[i+1]+dp[i+2]);
    }
    cout << dp[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    // cin >> t; 
    while (t--) solve();
}