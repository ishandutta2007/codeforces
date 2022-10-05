#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <queue>
#define last(x, y) (x)[(x).size() - y]
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, k, a[5001];
ll dp[5001][5001], pre[5001];

int main() {
	fast;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	pre[0] = 0;
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 0; i <= n; i++) dp[i][0] = 0;
	for (int i = 1; i <= k; i++) {
		dp[i * m][i] = pre[i * m];
		for (int j = i * m + 1; j <= n; j++)
			dp[j][i] = max(dp[j - 1][i], dp[j - m][i - 1] + pre[j] - pre[j - m]);
	}
	cout << dp[n][k] << endl;
}