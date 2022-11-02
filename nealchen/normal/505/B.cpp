#include <cstdio>
struct UFS {
	int f[101], r[101];
	void ii(int n) {
		for(int i = 1; i <= n; i++) {
			f[i] = i;
			r[i] = 1;
		}
	}
	int ff(int x) {
		return f[x] == x ? x : ff(f[x]);
	}
	void uu(int x, int y) {
		int u = ff(x), v = ff(y);
		if(u != v) {
			if(r[u] < r[v]) {
				f[u] = v;
				r[v] += r[u];
			}
			else {
				f[v] = u;
				r[u] += r[v];
			}
		}
	}
	bool cc(int x, int y) {
		return ff(x) == ff(y);
	}
};
UFS x[101];
int main() {
	int n, m, q;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		x[i].ii(n);
	}
	for(int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		x[c].uu(a, b);
	}
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int a, b, s = 0;
		scanf("%d%d", &a, &b);
		for(int i = 1; i <= m; i++) {
			if(x[i].cc(a, b)) {
				s++;
			}
		}
		printf("%d\n", s);
	}
	return 0;
}