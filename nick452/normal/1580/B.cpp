#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int MOD = 1000000007;

int n, m, c;
int f[128][128][128];
int saved[128][128];
int choose[128][128];

void solve(int n, int p) {
	if (saved[n][p]) {
		return;
	}
	saved[n][p] = 1;
	if (n == 0) {
		f[n][p][0] = 1;
		return;
	}
	int* ret = f[n][p];
	for (int i = 0; i <= n; i++) {
		ret[i] = 0;
	}
	int s[128];
	for (int n1 = 0; n1 < n; ++n1) {
		int n2 = n - 1 - n1;
		if (n1 > n2) {
			continue;
		}
		int c = (p + 1 == m ? 1 : 0);
		solve(n1, p + 1);
		solve(n2, p + 1);
		int* f1 = f[n1][p + 1];
		int* f2 = f[n2][p + 1];
		int l1 = n1;
		for (; l1 > 0 && f1[l1] == 0; --l1);
		int l2 = n2;
		for (; l2 > 0 && f2[l2] == 0; --l2);
		int l0 = l1 + l2 + c;
		assert(l0 <= n);
		for (int i = 0; i <= l0; i++) {
			s[i] = 0;
		}
		for (int i = 0; i <= l1; i++) {
			for (int j = 0; j <= l2; j++) {
				s[i + j + c] = (s[i + j + c] + (ll)f1[i] * f2[j]) % MOD;
			}
		}
		int dup = choose[n1 + n2][n1];
		if (n1 != n2) {
			dup = (dup * 2) % MOD;
		}
		for (int i = 0; i <= l0; i++) {
			ret[i] = (ret[i] + (ll)s[i] * dup) % MOD;
		}
	}
}

int main()
{
#ifdef _MSC_VER
	freopen("b.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	while (cin >> n >> m >> c >> MOD) {
		memset(choose, 0, sizeof(choose));
		for (int i = 0; i < 128; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (j == 0 || j == i) {
					choose[i][j] = 1;
				}
				else {
					choose[i][j] = (choose[i - 1][j - 1] + choose[i - 1][j]) % MOD;
				}
			}
		}
		memset(saved, 0, sizeof(saved));
		memset(f, 0, sizeof(f));
		solve(n, 0);
		printf("%d\n", f[n][0][c]);
	}
	return 0;
}