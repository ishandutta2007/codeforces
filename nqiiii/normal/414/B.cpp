#include <bits/stdc++.h>
using namespace std;
const int maxN = 2000, mod = 1000000007;
int Add(int x, int y) {
	x += y; return x < mod ? x : x - mod;
}
int f[maxN + 10][maxN + 10], n, k, ans;
int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) f[1][i] = 1;
	for (int i = 1; i < k; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = j; k <= n; k += j)
				f[i + 1][k] = Add(f[i + 1][k], f[i][j]);
	for (int i = 1; i <= n; ++i) ans = Add(ans, f[k][i]);
	printf("%d", ans);
}