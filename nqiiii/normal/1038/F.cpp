#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 40;
int n, m, ch[maxn + 10][2], nxt[maxn + 10];
ll f[maxn + 10][maxn + 10][maxn + 10], ans;
char s[maxn + 10];
int main() {
	scanf("%d%s", &n, s + 1);
	m = strlen(s + 1);
	for (int i = 1; i <= m; ++i) {
		ch[i - 1][s[i] - '0'] = i;
	}
	for (int i = 1; i <= m; ++i) {
		for (int j = 0; j < 2; ++j)
			if (ch[i][j]) nxt[ch[i][j]] = ch[nxt[i]][j];
			else ch[i][j] = ch[nxt[i]][j];
	}
	ans = 1ll << n;
	for (int i = 0; i < m; ++i) {
		memset(f, 0, sizeof f);
		f[0][0][i] = 1;
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k)
				for (int l = 0; l < m; ++l)
					if (f[j][k][l]) {
						for (int p = 0; p < 2; ++p) {
							int x = ch[k][p], y = ch[l][p];
							if (x != m && y != m) 
								f[j + 1][x][y] += f[j][k][l];
						}
					}
		for (int j = 0; j < m; ++j)
			ans -= f[n][i][j];
	}
	printf("%lld", ans);
}