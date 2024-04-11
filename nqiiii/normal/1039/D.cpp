#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, a[maxn + 10], dfscnt, fa[maxn + 10], f1[maxn + 10], f2[maxn + 10];
vector<int> g[maxn + 10];

void dfs(int p) {
	a[++dfscnt] = p;
	for (int i = 0; i < g[p].size(); ++i) {
		int e = g[p][i];
		if (e != fa[p]) {
			fa[e] = p; dfs(e);
		}
	}
}

int calc(int k) {
	int ans = 0;
	memset(f1, 0, sizeof f1); memset(f2, 0, sizeof f2);
	for (int i = n; i >= 1; --i) {
		int p = a[i];
		if (f1[p] + f2[p] + 1 >= k) ++ans;
		else if (fa[p]) {
			if (f1[p] + 1 > f1[fa[p]]) {
				f2[fa[p]] = f1[fa[p]]; f1[fa[p]] = f1[p] + 1;
			} else if (f1[p] + 1 > f2[fa[p]])
				f2[fa[p]] = f1[p] + 1;
		}
	}
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	dfs(1);
	for (int i = 1; i <= min(n, 1000); ++i) printf("%d\n", calc(i));
	for (int i = min(n, 1000) + 1; i <= n; ) {
		int l = i, r = n, v = calc(i);
		while (l != r) {
			int mid = l + r + 1 >> 1;
			if (calc(mid) == v) l = mid;
			else r = mid - 1;
		}
		for (int j = i; j <= l; ++j) printf("%d\n", v);
		i = l + 1;
	}
}