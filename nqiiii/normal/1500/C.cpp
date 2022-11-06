#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn = 2000;
int n, m;
int can[maxn + 10], ans[maxn + 10];
int a[maxn + 10][maxn + 10], b[maxn + 10][maxn + 10];
bool vis[maxn + 10], fre[maxn + 10];
map<ull, queue<int> > mp;

ull gethsh(int *a) {
	ull v = 0;
	for (int i = 1; i <= m; ++i)
		v = (v * 10007 + a[i]) % 1000000000000037;
	return v;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
		mp[gethsh(a[i])].push(i);
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) scanf("%d", &b[i][j]);
		ull v = gethsh(b[i]);
		if (mp[v].empty()) {
			printf("-1\n"); return 0;
		}
		b[i][m + 1] = mp[v].front();
		mp[v].pop();
	}
	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= m + 1; ++j)
			if (b[i][j] <= b[i + 1][j]) ++can[j];
	for (int i = 1; i <= m + 1; ++i) {
		int k = -1;
		for (int j = 1; j <= m + 1; ++j)
			if (!vis[j] && can[j] == n - 1) k = j;
		if (k == -1) {
			printf("-1\n");
			return 0;
		}
		ans[i] = k; vis[k] = 1;
		for (int j = 1; j < n; ++j)
			if (!fre[j] && b[j][k] < b[j + 1][k]) {
				fre[j] = 1;
				for (int l = 1; l <= m + 1; ++l)
					if (b[j][l] > b[j + 1][l]) ++can[l];
			}
	}
	int p = 0;
	for (int i = m + 1; i >= 1; --i)
		if (ans[i] == m + 1) {
			p = i - 1;
			break;
		}
	printf("%d\n", p);
	for (int i = p; i >= 1; --i)
		printf("%d ", ans[i]);
}