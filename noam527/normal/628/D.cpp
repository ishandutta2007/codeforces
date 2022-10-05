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

int m;
ll dp[3][2001][2001];
char d;
string a, b;

int calc(string &s, bool inclusive) {
	for (int i = 0; i < s.size(); i++)
		for (int j = 0; j < m; j++)
			dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = 0;

	for (int i = 1; i < in(s[0]); i++)
		if (i != in(d)) dp[0][0][i % m]++;
	if (d != s[0]) dp[1][0][in(s[0]) % m]++;
	for (int i = in(s[0]) + 1; i <= 9; i++)
		if (i != in(d)) dp[2][0][i % m]++;

	for (int i = 1; i < s.size(); i++) {
		if (i & 1) {
			for (int j = 0; j < m; j++) {
				dp[0][i][(j * 10 + in(d)) % m] = (dp[0][i][(j * 10 + in(d)) % m] + dp[0][i - 1][j]) % md;
				dp[2][i][(j * 10 + in(d)) % m] = (dp[2][i][(j * 10 + in(d)) % m] + dp[2][i - 1][j]) % md;
			}
			if (d < s[i]) {
				for (int j = 0; j < m; j++) {
					dp[0][i][(j * 10 + in(d)) % m] = (dp[0][i][(j * 10 + in(d)) % m] + dp[1][i - 1][j]) % md;
					dp[1][i][j] = 0;
				}
			}
			else if (d > s[i]) {
				for (int j = 0; j < m; j++) {
					dp[2][i][(j * 10 + in(d)) % m] = (dp[2][i][(j * 10 + in(d)) % m] + dp[1][i - 1][j]) % md;
					dp[1][i][j] = 0;
				}
			}
			else {
				for (int j = 0; j < m; j++)
					dp[1][i][(j * 10 + in(d)) % m] = (dp[1][i][(j * 10 + in(d)) % m] + dp[1][i - 1][j]) % md;
			}
		}
		else {
			for (int x = 0; x <= 9; x++) {
				if (x != in(d)) {
					for (int j = 0; j < m; j++) {
						dp[0][i][(j * 10 + x) % m] = (dp[0][i][(j * 10 + x) % m] + dp[0][i - 1][j]) % md;
						dp[2][i][(j * 10 + x) % m] = (dp[2][i][(j * 10 + x) % m] + dp[2][i - 1][j]) % md;
					}
					if (x < in(s[i])) {
						for (int j = 0; j < m; j++)
							dp[0][i][(j * 10 + x) % m] = (dp[0][i][(j * 10 + x) % m] + dp[1][i - 1][j]) % md;
					}
					else if (x > in(s[i])) {
						for (int j = 0; j < m; j++)
							dp[2][i][(j * 10 + x) % m] = (dp[2][i][(j * 10 + x) % m] + dp[1][i - 1][j]) % md;
					}
					else {
						for (int j = 0; j < m; j++)
							dp[1][i][(j * 10 + x) % m] = (dp[1][i][(j * 10 + x) % m] + dp[1][i - 1][j]) % md;
					}
				}
			}
		}
	}

//	for (int i = 0; i < s.size(); i++) {
//		cout << "length: " << i + 1 << ":" << endl;
//		for (int j = 0; j < m; j++)
//			cout << "of mod " << j << ": " << dp[0][i][j] << ", " << dp[1][i][j] << ", " << dp[2][i][j] << endl;
//	}

	ll ans = 0;
	for (int i = 0; i < s.size() - 1; i++)
		ans = (ans + dp[0][i][0] + dp[1][i][0] + dp[2][i][0]) % md;

	if (inclusive) ans = (ans + dp[0][s.size() - 1][0] + dp[1][s.size() - 1][0]) % md;
	else ans = (ans + dp[0][s.size() - 1][0]) % md;
	return ans;
}

int main() {
	fast;
	cin >> m >> d >> a >> b;
	cout << (calc(b, true) - calc(a, false) + md) % md << endl;
}