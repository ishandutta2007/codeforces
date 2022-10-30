#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pii pair<int, int>
#define mp make_pair
#define all(_v) _v.begin(), _v.end()
#define what_is(x) cout << #x << " is " << x << endl;
typedef long double ld;

const int inf = 1e9, mod = 1e9 + 7;
const int max_n = 201, max_k = 1001;

int n, k;
int a[max_n];
int dp[max_k][max_n], dp1[max_k][max_n];

void solve() {
    cin >> n >> k;
    for(int i = 0;i < n;i++) 
        cin >> a[i];

    sort(a, a + n);

    dp[0][0] = 1;
    dp[0][1] = 1;

    for(int i = 1;i < n;i++) {
        for(int j = 0;j < max_k;j++) {
            for(int c = 0;c < max_n;c++) {
                dp1[j][c] = dp[j][c];
                dp[j][c] = 0;
            }
        }

        for(int j = 0;j < max_k;j++) {
            for(int c = 0;c < max_n;c++) {
                int d = j - (c - 1) * (a[i] - a[i - 1]);

                if (c > 0 && d >= 0) dp[j][c] += dp1[d][c - 1];
                d -= (a[i] - a[i - 1]);
                if (d >= 0) dp[j][c] += dp1[d][c] * (c + 1);
                d -= (a[i] - a[i - 1]);
                if (d >= 0) dp[j][c] += dp1[d][c + 1] * (c + 1);

                dp[j][c] %= mod;
            }
        }

        /*for(int j = 0;j <= 3;j++) {
            for(int c = 0;c <= 3;c++) {
                cout << j << " " << c << " " << dp[j][c] << endl;
            }
        }
        cout << endl;*/
    }

    int res = 0;
    for(int i = 0;i <= k;i++) 
        res += dp[i][0];

    cout << res % mod << endl;
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    cout.precision(10);

    solve();
}