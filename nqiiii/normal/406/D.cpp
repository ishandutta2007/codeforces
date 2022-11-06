#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000, lgn = 20;
int n, dep[maxn + 10], f[maxn + 10][lgn + 1], q;
int stk[maxn + 10], stkcnt;
ll x[maxn + 10], y[maxn + 10];

bool chk(int a, int b, int c) {
	return (y[c] - y[b]) * (x[b] - x[a]) > (y[b] - y[a]) * (x[c] - x[b]);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld%lld", &x[i], &y[i]);
	for (int i = n; i >= 1; --i) {
		while (stkcnt > 1 && chk(i, stk[stkcnt], stk[stkcnt - 1])) --stkcnt;
		f[i][0] = stk[stkcnt]; dep[i] = dep[f[i][0]] + 1;
		for (int j = 1; j <= lgn; ++j) f[i][j] = f[f[i][j - 1]][j - 1];
		stk[++stkcnt] = i;
	}
	scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		if (dep[l] < dep[r]) swap(l, r);
		for (int i = lgn, t = dep[l] - dep[r]; i >= 0; --i)
			if (t >> i & 1) l = f[l][i];
		if (l == r) printf("%d ", l);
		else {
			for (int i = lgn; i >= 0; --i)
				if (f[l][i] != f[r][i]) {
					l = f[l][i]; r = f[r][i];
				}
			printf("%d ", f[l][0]);
		}
	}
}