#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <time.h>
#include <stack>
#include <queue>
#include <fstream>
#include <random>
#define endl '\n'
#define flush fflush(stdout), cout.flush()
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, b, mod, a[500], dp[2][501][501];

int main() {
	fast;
	cin >> n >> m >> b >> mod;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i <= m; i++) for (int j = 0; j <= b; j++) dp[1][i][j] = 0;
	dp[1][0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= m; j++) for (int k = 0; k <= b; k++)
			dp[i & 1][j][k] = dp[(i + 1) & 1][j][k];
		for (int j = 1; j <= m; j++) {
			for (int k = a[i]; k <= b; k++) {
				dp[i & 1][j][k] = (dp[i & 1][j][k] + dp[i & 1][j - 1][k - a[i]]) % mod;
			}
		}
	}
	int tot = 0;
	for (int i = 0; i <= b; i++) tot = (tot + dp[(n - 1) & 1][m][i]) % mod;
	cout << tot << endl;
}