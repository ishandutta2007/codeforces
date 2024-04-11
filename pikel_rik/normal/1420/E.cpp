#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 85;

int n, m, a[N], pos[N];
int dp[N][N][N*N];

int f(int x) {
	return (x * x - x) / 2;
}

int recurse(int i, int j, int moves) {
	if (moves < 0) {
		return INT_MAX;
	}
	if (pos[j + 1] == -1) {
		return f(n - i);
	}
	int& ans = dp[i][j][moves];
	if (ans != -1) {
		return ans;
	}
	ans = INT_MAX;
	for (int ii = i; ii <= n - (m - j); ii++) {
		int rec = recurse(ii + 1, j + 1, moves - abs(pos[j + 1] - ii));
		if (rec != INT_MAX) {
			ans = min(ans, f(ii - i) + rec);
		}
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(pos, -1, sizeof(pos));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		if (a[i]) {
			pos[++m] = i;
		}
	}

	int total = f(n - accumulate(a, a + n, 0));

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i <= (n * n - n) / 2; i++) {
		cout << total - recurse(0, 0, i) << ' ';
	}
	cout << '\n';
	return 0;
}