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
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define in(X) ((X) - '0')
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

string s;
int n, q, l, r;
bool palin[5000][5000];
ll dp[5000][5000];

int main() {
	fast;
	cin >> s;
	n = s.size();
	for (int i = 0; i < n - 1; i++) dp[i][i] = palin[i][i] = 1, dp[i][i + 1] = (s[i] == s[i + 1] ? 3 : 2), palin[i][i + 1] = (dp[i][i + 1] - 2 ? true : false);
	dp[n - 1][n - 1] = palin[n - 1][n - 1] = 1;
	for (int i = 2; i < n; i++)
		for (int j = 0; j + i < n; j++) {
			if (palin[j + 1][j + i - 1] && s[j] == s[j + i]) palin[j][j + i] = true;
			else palin[j][j + i] = false;
			dp[j][j + i] = dp[j][j + i - 1] + dp[j + 1][j + i] - dp[j + 1][j + i - 1] + palin[j][j + i];
		}

	cin >> q;
	while (q--) {
		cin >> l >> r;
		cout << dp[l - 1][r - 1] << endl;
	}
}