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
const int md = 1e9 + 7;
const long long hs = 137;
//const double pi = acos(-1);
typedef long long ll;
typedef long double ldb;
using namespace std;

int n, a[50], dp[2][51], sum = 0;

int main() {
	fast;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	dp[0][n] = dp[1][n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		dp[0][i] = max(dp[0][i + 1], (sum - dp[1][i + 1]) + a[i]);
		dp[1][i] = max(dp[1][i + 1], (sum - dp[0][i + 1]) + a[i]);
		sum += a[i];
	}
	cout << sum - dp[0][0] << " " << dp[0][0] << endl;
}