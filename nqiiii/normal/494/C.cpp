#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5, maxq = 5000;
int n, q, s[maxn + 10];
stack<int> stk;

struct data {
	int l, r; double p;

	bool operator < (const data &t) const {
		return l == t.l ? r > t.r : l < t.l;
	}

}a[maxq + 10];
vector<int> g[maxq + 10];


namespace qwq {
	const int lgn = 18;
	int lg[maxn + 10], f[lgn + 1][maxn + 10];
	void initrmq() {
		lg[0] = -1;
		for (int i = 1; i <= n; ++i) {
			lg[i] = lg[i >> 1] + 1;
			f[0][i] = s[i];
		}
		for (int i = 1; i <= lgn; ++i)
			for (int j = 1; j <= n - (1 << i) + 1; ++j)
				f[i][j] = max(f[i - 1][j], f[i - 1][j + (1 << (i - 1))]);
	}

	int query(int l, int r) {
		if (l > r) return -2e9;
		int d = lg[r - l + 1];
		return max(f[d][l], f[d][r - (1 << d) + 1]);
	}
}

void merge(vector<double> &a, const vector<double> &b) {
	double s0 = 0, s1 = 0;
	for (int i = 0; i <= q * 2; ++i) {
		s0 += a[i]; s1 += b[i];
		a[i] = s0 * s1;
	}
	assert(fabs(s0 - 1) <= 1e-7);
	assert(fabs(s1 - 1) <= 1e-7);
	for (int i = q * 2; i >= 1; --i) {
		a[i] -= a[i - 1];
	}
}

bool cmp(int x, int y) {
	return a[x].l < a[y].l;
}

vector<double> dfs(int p) {
	vector<double> f(q * 2 + 1);
	f[0] = 1;
	int lst = a[p].l, mx = 0;
	sort(g[p].begin(), g[p].end(), cmp);
	for (auto i: g[p]) {
		mx = max(mx, qwq::query(lst, a[i].l - 1));
		lst = a[i].r + 1;
		vector<double> h = dfs(i);
		merge(f, h);
	}
	mx = max(mx, qwq::query(lst, a[p].r));
	for (int i = 0; i < mx; ++i) {
		f[mx] += f[i]; f[i] = 0;
	}
	for (int i = q * 2; i >= 0; --i) {
		f[i] *= (1 - a[p].p);
		if (i) f[i] += f[i - 1] * a[p].p;
	}
	/*
	printf("|%d|\n", p);
	for (auto i: f) printf("%.2lf ", i);
	printf("\n");
	*/
	return f;
}

int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) scanf("%d", &s[i]);
	int v = *max_element(s + 1, s + n + 1);
	for (int i = 1; i <= n; ++i) s[i] -= v - q;
	qwq::initrmq();
	for (int i = 1; i <= q; ++i)
		scanf("%d%d%lf", &a[i].l, &a[i].r, &a[i].p);
	a[0].l = 1; a[0].r = n;
	sort(a + 1, a + q + 1);
	stk.push(0);
	for (int i = 1; i <= q; ++i) {
		while (a[i].l > a[stk.top()].r) stk.pop();
		assert(a[i].r <= a[stk.top()].r);
		g[stk.top()].push_back(i);
		stk.push(i);
	}
	vector<double> ans = dfs(0);
	double res = v - q;
	for (int i = 0; i <= q * 2; ++i) res += i * ans[i];
	printf("%.10lf", res);
}