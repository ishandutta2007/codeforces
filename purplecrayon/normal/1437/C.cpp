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
const int MAXN = 2e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n", first = "DA\n", second = "NET\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

ll dp[MAXN][2*MAXN];
void solve(){
    int n; cin >> n;
    vector<ll> a(n); for (auto& it : a) cin >> it, --it;
    sort(a.begin(), a.end());
    for (int i = 0; i <= n; i++) for (int j = 0; j <= 2*n; j++) dp[i][j] = 1e18;
    //always going to take them in sorted order
    //dp[i][x] -> ans for the first i given that everything taken is less than or equal to time x
    for (int i = 0; i <= 2*n; i++) {
        dp[0][i] = abs(a[0]-i);
        if (i) dp[0][i] = min(dp[0][i], dp[0][i-1]);
    }
    for (int i = 1; i < n; i++){
        for (int j = 1; j <= 2*n; j++){
            dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]+abs(j-a[i]));
        }
    }
    cout << dp[n-1][2*n] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t; 
    while (t--) solve();
}