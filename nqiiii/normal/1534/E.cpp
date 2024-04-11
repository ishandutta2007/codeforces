#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;
int n, k;
queue<int> q;
int f[maxn + 10], ans;

bitset<maxn + 10> dfs(int p) {
	if (p == 0) return bitset<maxn + 10>();
	int e = p - (k - f[p]) + f[p];
	auto a = dfs(e);
	int v1 = f[p], v2 = k - f[p];
	printf("? ");
	for (int i = 1; i <= n; ++i) 
		if (a[i] == 0 && v2) {
		 	--v2; a[i] = 1;
			printf("%d ", i);
		} else if (a[i] == 1 && v1) {
			--v1; a[i] = 0;
			printf("%d ", i);
		}
	printf("\n"); fflush(stdout);
	int x; scanf("%d", &x);
	ans ^= x;
	return a;
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) f[i] = -1;
	f[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int p = q.front(); q.pop();
		for (int i = 0; i <= k; ++i)
			if (p >= i && n - p >= k - i) {
				int e = p - i + (k - i);
				if (f[e] == -1) {
					f[e] = i; q.push(e);
				}
			}
	}
	if (f[n] == -1) {
		printf("-1"); return 0;
	}
	dfs(n);
	printf("! %d\n", ans);
	fflush(stdout);
}