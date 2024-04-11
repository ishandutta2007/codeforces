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
#define last(x, y) (x)[(x).size() - (y)]
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
//const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int n, m, mod, dp[501][501], c[500] = {}, v[2] = {};
char b;

int main() {
	fast;
	cin >> n >> m >> mod;

	for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) {
		cin >> b;
		if (b == '1') c[j]++;
	}
	for (int i = 0; i < n; i++)
		if (c[i] != 2) v[c[i] ^ 1]++;

	for (int i = 0; i <= 500; i++) for (int j = 0; i + j <= 500; j++) {
		if ((i + j) < 2) dp[i][j] = 1 - i - j;
		else {
			dp[i][j] = 0;
			if (i > 1) dp[i][j] = (dp[i][j] + (ll)i * (i - 1) / 2 * dp[i - 2][j + 2]) % mod;
			if (j > 1) dp[i][j] = (dp[i][j] + (ll)j * (j - 1) / 2 * dp[i][j - 2]) % mod;
			if (i > 0 && j > 0) dp[i][j] = (dp[i][j] + (ll)i * j * dp[i - 1][j]) % mod;
		}
	}
	cout << dp[v[1]][v[0]] << endl;
}