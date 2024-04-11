#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000;
int n, s[maxn * 2 + 10], l[maxn + 10], r[maxn + 10], scnt;
int fa[maxn * 2 + 10], m1[maxn * 2 + 10], m2[maxn * 2 + 10], ans;
bool b[maxn * 2 + 10];

int getf(int p) {
	return fa[p] == p ? p : fa[p] = getf(fa[p]);
}

void merge(int x, int y) {
	x = getf(x); y = getf(y);
	if (x == y) {
		if (b[x]) {
			printf("-1"); exit(0);
		}
		b[x] = 1;
	} else {
		b[y] |= b[x]; fa[x] = y;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		s[++scnt] = l[i]; s[++scnt] = r[i];
	}
	sort(s + 1, s + scnt + 1);
	scnt = unique(s + 1, s + scnt + 1) - s - 1;
	for (int i = 1; i <= scnt; ++i) fa[i] = i;
	for (int i = 1; i <= n; ++i) {
		l[i] = lower_bound(s + 1, s + scnt + 1, l[i]) - s;
		r[i] = lower_bound(s + 1, s + scnt + 1, r[i]) - s;
		merge(l[i], r[i]);
	}
	for (int i = 1; i <= scnt; ++i) {
		int p = getf(i);
		if (s[i] > m1[p]) {
			m2[p] = m1[p]; m1[p] = s[i];
		} else if (s[i] > m2[p]) m2[p] = s[i];
	}
	for (int i = 1; i <= scnt; ++i)
		if (fa[i] == i)
			if (b[i]) ans = max(ans, m1[i]);
			else ans = max(ans, m2[i]);
	printf("%d", ans);
}