#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int T, n, p[N], per[N], fa[N], l[N], r[N];
multiset <int> s;

int find(int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}

void con(int x, int y) {
	if (find(x) != find(y)) {
		if (r[fa[x]] != n) s.erase(s.find(r[fa[x]] - l[fa[x]] + 1));
		if (r[fa[y]] != n) s.erase(s.find(r[fa[y]] - l[fa[y]] + 1));
		l[fa[y]] = min(l[fa[y]], l[fa[x]]);
		r[fa[y]] = max(r[fa[y]], r[fa[x]]);
		fa[fa[x]] = fa[y];
		if (r[fa[y]] != n) s.insert(r[fa[y]] - l[fa[y]] + 1);
	}
}

int main() {
	for (scanf("%d", &T); T; T--) {
		scanf("%d", &n); s.clear();
		for (int i = 1; i <= n; i++)
			scanf("%d", &p[i]), per[p[i]] = i;
		for (int i = 1; i <= n + 1; i++) fa[i] = l[i] = r[i] = 0;
		for (int i = 1; i <= n; i++) s.insert(0);
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			int x = per[i];
			int lch = find(x - 1), rch = find(x + 1);
			if ((lch ? r[lch] - l[lch] + 1 : 0) != *(--s.end())) {
				flag = 1;
				break;
			}
			if (x != n) s.erase(s.find(0)), s.insert(1);
			fa[x] = l[x] = r[x] = x;
			if (lch) con(lch, x);
			if (rch) con(rch, x);
		}
		puts(flag ? "No" : "Yes");
	}
	return 0;
}