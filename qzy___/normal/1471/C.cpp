#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

int T, n, m, k[N], c[N], fa[N];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) fa[i] = i;
		for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
		for (int i = 1; i <= m; i++) scanf("%d", &c[i]);
		sort (k + 1, k + n + 1); long long ans = 0;
		for (int i = n; i >= 1; i--) {
			int x = find(1);
			if (x < k[i]) {
				ans += c[x];
				find(x), find(x + 1);
				fa[fa[x]] = fa[x + 1];
			}
			else ans += c[k[i]];
		}
		printf("%lld\n", ans);
	}
	return 0;
}