#include "bits/stdc++.h"
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
typedef unsigned int ui;
const int MAXN = 1.5e5+10, MAXM = 5e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 5e5+10, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

void solve(){
    //reduced to: is it possible apply op1 to make it increasing
    
    //i will always work from back to front
    //dp[i] -> the min ops needed to fix suffix (i..n-1)
    //dp[i] = max(dp[i+1], a[i]-(a[i+1]-dp[i+1]))
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it;
    vector<ll> dp(n); dp[n-1] = 0;
    for (int i = n-2; i >= 0; i--){
        dp[i] = max(dp[i+1], a[i]-(a[i+1]-dp[i+1]));
        if (dp[i] > a[i]){ cout << no; return; }
    }
    cout << yes;
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}