
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <math.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int sz = 5e5;
int n, x, a[sz];
ll dp[sz][2][2], bst[sz];

void solve() {
    cin >> n;
    foru(i, 0, n)cin >> a[i];
    cin >> x;
    foru(i, 0, n)a[i] -= x;
    foru(i, 0, n) {
        bst[i] = -1e9;
        foru(j, 0, 2) {
            foru(k, 0, 2)dp[i][j][k] = -1e9;
        }
    }
    dp[0][0][0] = dp[0][0][1] = 0;
    dp[0][1][0] = dp[0][1][1] = 1;
    bst[0] = 1;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    dp[1][0][0] = 0;
    dp[1][0][1] = 1;
    dp[1][1][0] = 1;
    if (a[0] + a[1] >= 0)dp[1][1][1] = 2;
    else dp[1][1][1] = -1e9;
    bst[1] = max(1LL, dp[1][1][1]);
    foru(i, 2, n) {
        dp[i][0][0] = bst[i - 2];
        dp[i][0][1] = max(dp[i - 1][1][0], dp[i - 1][1][1]);
        dp[i][1][0] = 1 + bst[i - 2];
        if (a[i] + a[i - 1] >= 0) {
            dp[i][1][1] = 1 + dp[i - 1][1][0];
            if (a[i] + a[i - 1] + a[i - 2] >= 0)dp[i][1][1] = max(dp[i][1][1], 1 + dp[i - 1][1][1]);
        }
        foru(j, 0, 2) {
            foru(k, 0, 2)bst[i] = max(bst[i], dp[i][j][k]);
        }
    }
    ll ans = -1e9;
    foru(j, 0, 2) {
        foru(k, 0, 2)ans = max(ans, dp[n - 1][j][k]);
    }
    cout << ans << '\n';
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--)solve();
    return 0;
}