#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

void solve(){
    int n; cin >> n;
    vector<ar<ll, 2>> a(n);
    for (auto& it : a) cin >> it[0] >> it[1];

    vector<ar<ll, 3>> dp(n);
    dp[0][0] = 0, dp[0][1] = a[0][1], dp[0][2] = 2ll*a[0][1];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            ll cost = a[i][1]*j, cur = a[i][0]+j;
            dp[i][j] = ll(1e18);
            for (int k = 0; k < 3; k++) {
                ll prev = a[i-1][0]+k;
                if (cur != prev) 
                    dp[i][j] = min(dp[i][j], dp[i-1][k]+cost);
            }
        }
    }
    cout << *min_element(dp[n-1].begin(), dp[n-1].end()) << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}