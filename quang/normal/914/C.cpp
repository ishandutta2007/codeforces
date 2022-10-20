#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int N = 1010;

inline int add(int u, int v) {
	u += v;
	if (u >= MOD) {
		u -= MOD;
	}
	return u;
}

int dp[N];
char a[N];
int k;
int n;
int c[N][N];

bool check() {
	if (n == 1) {
		return 0;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += a[i] == '1';
	}
	return dp[cnt] + 1 == k;
}

int main() {
	scanf("%s", a + 1);
	n = strlen(a + 1);
	scanf("%d", &k);
	if (k == 0) {
		cout << 1 << endl;
		return 0;
	}
	dp[1] = 0;
	dp[0] = -1e9;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) {
				c[i][j] = 1;
			} else {
				c[i][j] = add(c[i - 1][j - 1], c[i - 1][j]);
			}
		}
	}
	for (int i = 2; i <= 1000; i++) {
		int u = 0;
		int v = i;
		while (v) {
			u++;
			v -= (v & -v);
		}
		dp[i] = dp[u] + 1;
	}
	int cnt = 0;
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] == '1') {
			int sz = n - i;
			for (int j = 0; j <= sz; j++) {
				if (dp[cnt + j] + 1 == k) {
					res = add(res, c[sz][j]);
				}
			}
			cnt++;
		}
	}
	res = add(res, check());
	if (k == 1 && n != 1) {
		res--;
		if (res < 0) {
			res += MOD;
		}
	}
	cout << res << endl;
	return 0;
}