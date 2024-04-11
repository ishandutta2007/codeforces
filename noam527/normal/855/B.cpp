#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 149;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

ll n, p, q, r, a[100005], dp[3][100005];

int main() {
	fast;
	cin >> n >> p >> q >> r;
	for (int i = 0; i < n; i++) cin >> a[i], dp[0][i] = a[i] * p;
	for (int i = 1; i < n; i++) dp[0][i] = max(dp[0][i], dp[0][i - 1]);

	dp[1][0] = q * a[0] + dp[0][0];
	for (int i = 1; i < n; i++)
		dp[1][i] = max(dp[1][i - 1], q * a[i] + dp[0][i]);

	dp[2][0] = r * a[0] + dp[1][0];
	for (int i = 1; i < n; i++)
		dp[2][i] = max(dp[2][i - 1], r * a[i] + dp[1][i]);

	cout << dp[2][n - 1] << endl;
}