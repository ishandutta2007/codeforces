#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 210;

int n, mid[N][N], ans[N], fa[N];
ll s[N][N], f[N][N];

ll T(int l, int r, int x, int y) {
	return s[r][y] - s[l - 1][y] - s[r][x - 1] + s[l - 1][x - 1];
}
ll get(int l, int r) {
	if (r < l) return 0;
	return T(l, r, 1, l - 1) + T(l, r, r + 1, n);
}
int getans(int l, int r) {
	if (l > r) return 0;
	int m = mid[l][r];
	fa[getans(l, m - 1)] = m;
	fa[getans(m + 1, r)] = m;
	return m;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%lld", &s[i][j]);
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= n; i++) mid[i][i] = i, f[i][i] = f[i][i - 1] = 0;
	f[n + 1][n] = 0;
	for (int l = 2; l <= n; l++)
		for (int i = 1; i + l - 1 <= n; i++) {
			int j = i + l - 1;
			for (int k = i; k <= j; k++) {
				ll tmp = f[i][k - 1] + f[k + 1][j] + get(i, k - 1) + get(k + 1, j);
				if (tmp < f[i][j]) {
					f[i][j] = tmp + 1;
					mid[i][j] = k;
				}
			}
		}
	getans(1, n);
	for (int i = 1; i <= n; i++)
		cout << fa[i] << " ";
	cout << endl;
	return 0;
}