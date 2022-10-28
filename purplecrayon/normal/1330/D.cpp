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
typedef unsigned int ui;
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 50;
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};


void solve(){
    ll d, m; cin >> d >> m;
    //dp[i][j] = seq of len i where highest set bit is <= j
    
    auto get = [&](int j) -> ll {
        //number of numbers with highest set bit == j
        ll nmV = (1ll<<j); if (d&(1ll<<j) && (1ll<<(j+1)) > d) nmV = (d^(1ll<<j))+1;
        return nmV;
    };
    
    vector<vector<ll>> dp(MAXB, vector<ll>(MAXB, 0));
    for (int j = 0; j < MAXB; j++) if ((1ll<<j) <= d) {
        dp[1][j] = get(j); //cout << dp[1][j] << '\n';
    }
    for (int j = 1; j < MAXB; j++) dp[1][j] = (dp[1][j]+dp[1][j-1])%m;
    for (int i = 2; i < MAXB; i++){
        for (int j = i-1; j < MAXB; j++) if ((1ll<<j) <= d){
            ll nmV = get(j);
            // if (i < 3) cout << i << ' ' << j << ' ' << nmV << '\n';
            dp[i][j] = dp[i-1][j-1]*nmV%m;
        }
        for (int j = 1; j < MAXB; j++) dp[i][j] = (dp[i][j-1]+dp[i][j])%m;
    }
    ll ans=0;
    for (int i = 1; i < MAXB; i++) ans = (ans+dp[i][MAXB-1])%m;
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}