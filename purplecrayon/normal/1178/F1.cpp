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
const int MAXN = 1e5+10, MAXQ = 3e5+10, MAXL = 18, ALP = 26, MOD = 998244353, MAXK = 17,  MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const int INF = 1e9+10;

ll dp[511][511];

void solve(){
    int n, m; cin >> n >> m;
    vector<int> a(n); for (auto& it : a) cin >> it, --it;
    for (int i = 0; i <= n+1; i++) for (int j = 0; j <= n+1; j++) dp[i][j] = 1;

    for (int i = 1; i <= m; i++) for (int j = 0; j <= m; j++) {
        if (j + i > m) { dp[i][j] = 0; continue; }
        ar<int, 2> mn{a[j], 0};
        for (int k = 0; k < i; k++) mn = min(mn, ar<int, 2>{a[j+k], k});

        if (mn[1] < 0 || mn[1] >= i) continue;
        ll a=0, b=0;
        for (int k = mn[1]+1; k <= i; k++) a += dp[mn[1]+j+1][k-mn[1]-1]*dp[j+k][i-k], a%=MOD;
        for (int k = 0; k <= mn[1]; k++) b += dp[j][k] * dp[j+k][mn[1]-k], b%=MOD;
        dp[j][i] = a*b%MOD;
    }
    cout << dp[0][n] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}