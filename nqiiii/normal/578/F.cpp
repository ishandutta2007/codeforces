#include <bits/stdc++.h>
using namespace std;
int n, m, mod, cnt;
char s[150][150];
int mp[150][150];
int fa[100000], id[100000];
int a[1000][1000], wcnt;
bool ban;

int getf(int p) {
	return fa[p] == p ? p : fa[p] = getf(fa[p]);
}

void merge(int x, int y) {
	if (!x || !y) return;
	if (getf(x) == getf(y)) ban = 1;
	fa[getf(x)] = getf(y);
}

void adde(int x, int y) {
	if (!x || !y) return;
	x = id[getf(x)]; y = id[getf(y)];
	a[x][x] = (a[x][x] + 1) % mod;
	a[y][y] = (a[y][y] + 1) % mod;
	a[x][y] = (a[x][y] + mod - 1) % mod;
	a[y][x] = (a[y][x] + mod - 1) % mod;
}

int fpow(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = 1ll * ans * x % mod;
		y >>= 1; x = 1ll * x * x % mod;
	}
	return ans;
}

int gauss(int n) {
	--n;
	int ans = 1;
	for (int i = 1; i <= n; ++i) {
		int t = i;
		for (int j = i + 1; j <= n; ++j)
			if (a[j][i] > a[t][i]) t = j;
		if (t != i) {
			for (int j = i; j <= n; ++j)
				swap(a[i][j], a[t][j]);
			ans = (mod - ans) % mod;
		}
		ans = 1ll * ans * a[i][i] % mod;
		if (!ans) break;
		int inv = fpow(a[i][i], mod - 2);
		for (int j = i + 1; j <= n; ++j) {
			t = 1ll * a[j][i] * inv % mod;
			for (int k = i; k <= n; ++k)
				a[j][k] = (a[j][k] + mod - 1ll * t * a[i][k] % mod) % mod;
		}
	}
	return ans;
}

int solve(int d) {
	memset(mp, 0, sizeof mp); cnt = ban = 0;
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			if ((i + j) % 2 == d) mp[i][j] = ++cnt;
	for (int i = 1; i <= cnt; ++i) fa[i] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == '/') merge(mp[i][j - 1], mp[i - 1][j]);
			else if (s[i][j] == '\\') merge(mp[i - 1][j - 1], mp[i][j]);
	if (ban) return 0;
	wcnt = 0;
	for (int i = 1; i <= cnt; ++i)
		if (fa[i] == i) id[i] = ++wcnt;
	if (wcnt >= 500) return 0;
	memset(a, 0, sizeof a);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (s[i][j] == '*') {
				adde(mp[i][j - 1], mp[i - 1][j]);
				adde(mp[i - 1][j - 1], mp[i][j]);
			}
	return gauss(wcnt);
}

int main() {
	scanf("%d%d%d", &n, &m, &mod);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	printf("%d", (solve(0) + solve(1)) % mod);
}