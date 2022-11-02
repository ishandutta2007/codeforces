#define _CRT_SECURE_NO_WARNINGS
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
#include <chrono>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vi;

const int sz = 5e5 + 5;
ll n, m, k;
ll a[sz], dp[sz];
//m = 3
//1, 3, -4, 2, 5, 6, 1, 7
//dp[7] = max(7 - k, 8 - k, 14 - k,
//           19 - 2k, 21 - 2k, 17 - 2k,
//           13 - 3k, 16 - 3k, 17 - 3k

//dp[7] = max(7 - k, 8 - k, 14 - k,
//            -k + (7 + 1 + 6) + dp[7 - m])

const ll INF = 1e18;

int main() {
    fast;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i], dp[i] = -INF;
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = i; i - j + 1 <= m; j--) {
            sum += a[j];
            dp[i] = max(dp[i], sum - k);
        }
        if (i - m >= 0)
            dp[i] = max(dp[i], sum - k + dp[i - m]);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
    return 0;
}