#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 5e4 + 10;

namespace MOD {
	const int P = 998244353;
	inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
	inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
	inline int mul(int x, int y) {return (long long)x * y % P;}
	inline void inc(int &x, int y) {x = add(x, y);}
	inline void dec(int &x, int y) {x = sub(x, y);}
	inline void upd(int &x, int y) {x = mul(x, y);}
	inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}
};
using namespace MOD;

int n, m, tr[10][10], dp[N][1024];
vector<int> f[1024];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int a, b; scanf("%d%d", &a, &b);
		tr[a][b] = tr[b][a] = 1;
	}
	for (int i = 0; i < 1024; i++)
		for (int j = 0; j < 10; j++)
			if (!(i >> j & 1)) {
				int to = i;
				for (int k = 0; k < j; k++) {
					if (tr[k][j]) to |= 1 << k;
					else to &= (1023 - (1 << k));
				}
				for (int k = j + 1; k < 10; k++)
					if (!tr[k][j]) to &= (1023 - (1 << k));
				f[i].push_back(to);
			}
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j < 1024; j++) {
			if (!dp[i][j]) continue;
			for (int v : f[j]) inc(dp[i + 1][v], dp[i][j]);
		}
	int ans = 0;
	for (int i = 0; i < 1024; i++)
		inc(ans, dp[n][i]);
	printf("%d\n", ans);
	return 0;
}