#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

char a[N], b[N];
int f[N][3][3];
int n, m;

int main() {
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1), m = strlen(b + 1);
	for (int i = 1; i <= n; i++) a[i] %= 3;
	for (int i = 1; i <= m; i++) b[i] %= 3;
	for (int i = 2; i <= m; i++) {
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
			f[i][j][k] = f[i - 1][j][k];
		 f[i][b[i - 1]][b[i]]++;
	}
	int l = 1, r = 1;
	while (r < m && a[1] != b[r]) r++;
	long long ans = r - l + 1;
	for (int i = 2; i <= n; i++) {
		if (r < m) {
			r++;
			while (r < m && b[r] != a[i]) r++;
		}
		if (a[i - 1] == b[l]) l++;
		if (l > m) break;
		ans += r - l + 1;
		if (a[i - 1] != a[i]) ans -= f[r][a[i]][a[i - 1]] - f[l - 1][a[i]][a[i - 1]];
	}
	printf("%lld\n", ans);
	return 0;
}