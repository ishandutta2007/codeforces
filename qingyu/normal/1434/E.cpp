#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 50;
const int M = 450 + 10;
const int V = 1e5;

struct dsu_t {
	int f[N], val[N];
	inline int find(int x) {
		while (x != f[x])
			x = f[x] = f[f[x]];
		return x;
	}
	inline void assign(int l, int r, int v) {
		for (int x = find(r); x >= l; x = find(x)) {
			f[x] = x - 1;
			val[x] = v;
		}
	}
	inline void reset(int n) {
		for (int i = 0; i <= n; ++i) {
			f[i] = i;
			val[i] = -1;
		}
	}
} p[M];
int a[N], suc[N], pos[N];
bool buc[N];

int solve() {
	int n;
	cin >> n;
	memset(suc, 0, sizeof suc);
	memset(buc, 0, sizeof buc);
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		suc[a[i]] = i;
	}
	for (int i = V; i >= 0; --i)
		if (!suc[i])
			suc[i] = suc[i + 1];
	for (int i = 0; i < M; ++i)
		p[i].reset(n);
	p[0].assign(1, n, n);
	buc[0] = true;
	for (int i = n - 1; i > 0; --i) {
		pos[0] = n + 1;
		int failed = -1;
		for (int j = 0; j < M; ++j) {
			int z = p[j].val[i];
			if (z == -1) {
				failed = j;
				buc[j] = true;
				break;
			}
			pos[j + 1] = min(pos[j], z);
		}
		assert(failed != -1);
		int t = i;
		for (int k = failed; k > 0; --k) {
			int u = a[i] - (a[pos[k]] - a[i]) + 1;
			int l = 1;
			if (u >= 0) l = suc[u];
			if (t > l) {
				p[k].assign(l, t - 1, i);
				t = l;
			}
		}
	}
	int mex = 0;
	while (buc[mex]) ++mex;
	return mex;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	std::cin >> T;
	int xorsum = 0;
	while (T--) {
		xorsum ^= solve();
	}
	cout << (xorsum ? "YES" : "NO") << '\n';
}