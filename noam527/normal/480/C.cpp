#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
const int md = 1e9 + 7;
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, a, b, k, dp[2][5000];

int main() {
	fast;
	cin >> n >> a >> b >> k, --a, --b;
	if (a > b) a = (n - 1) - a, b = (n - 1) - b;
	for (int i = 0; i < b; i++) dp[0][i] = 0;
	dp[0][a] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j < b; j++) dp[i & 1][j] = 0;
		for (int j = 0; j < b - 1; j++) {
			dp[i & 1][max(0, 2 * j - b + 1)] = (dp[i & 1][max(0, 2 * j - b + 1)] + dp[(i - 1) & 1][j]) % md;
			dp[i & 1][j] = (dp[i & 1][j] - dp[(i - 1) & 1][j]) % md;
			dp[i & 1][j + 1] = (dp[i & 1][j + 1] + dp[(i - 1) & 1][j]) % md;
		}
		for (int j = 1; j < b; j++) dp[i & 1][j] = (dp[i & 1][j] + dp[i & 1][j - 1]) % md;
	}
	int ans = 0;
	for (int i = 0; i < b; i++) ans = (ans + dp[k & 1][i]) % md;
	cout << (ans + md) % md << endl;
	return 0;
}