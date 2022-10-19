#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;

inline int add(int x, int y) {return x + y >= P ? x + y - P : x + y;}
inline int sub(int x, int y) {return x < y ? x - y + P : x - y;}
inline int mul(int x, int y) {return 1ll * x * y % P;}
inline int Pow(int x, int y) {int r = 1; for (; y; y >>= 1, x = mul(x, x)) if (y & 1) r = mul(r, x); return r;}

const int N = 1e5 + 10, G = 3, Gi = Pow(3, P - 2);

int r[N * 4], l, a[N * 4], b[N * 4], lim;

void DFT(int *a, int type) {
	for (int i = 0; i < lim; i++) if (i < r[i]) swap(a[i], a[r[i]]);
	for (int i = 1; i < lim; i <<= 1) {
		int t = Pow(type == 1 ? G : Gi, (P - 1) / (i << 1));
		for (int j = 0; j < lim; j += (i << 1)) {
			int tmp = 1;
			for (int k = 0; k < i; k++, tmp = mul(tmp, t)) {
				int tx = a[j + k], ty = mul(tmp, a[i + j + k]);
				a[j + k] = add(tx, ty), a[i + j + k] = sub(tx, ty);
			}
		}
	}
	if (type == -1) {
		int inv = Pow(lim, P - 2);
		for (int i = 0; i < lim; i++) a[i] = mul(a[i], inv);
	}
}

vector <int> multi(vector <int> x, vector <int> y) {
	vector <int> z(x.size() + y.size() - 1);
	lim = 1, l = 0; while (lim < z.size()) lim <<= 1, l++;
	for (int i = 0; i < lim; i++) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	for (int i = 0; i < lim; i++) a[i] = b[i] = 0;
	for (int i = 0; i < x.size(); i++) a[i] = x[i]; DFT(a, 1);
	for (int i = 0; i < y.size(); i++) b[i] = y[i]; DFT(b, 1);
	for (int i = 0; i < lim; i++) a[i] = mul(a[i], b[i]); DFT(a, -1);
	for (int i = 0; i < z.size(); i++) z[i] = a[i]; return z;
}

int n, m, sum;

void solve(int l, int r, vector<int> &a, vector<int> &b, vector<int> &c) {
	if (r - l == 1) return; int mid = (l + r) >> 1;
	solve(l, mid, a, b, c), solve(mid, r, a, b, c);
	vector <int> mul = multi(vector<int>(a.begin() + l, a.begin() + mid),
							 vector<int>(b.begin() + mid, b.begin() + r));
	for (int i = 0; i < mul.size(); i++)
		c[i + l + mid] = add(c[i + l + mid], mul[i]);
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr);
	cin >> n >> m;
	vector <int> a(n), p(m), p2(n + 1, 1);
	vector <int> pre(n), suf(n), pr(n);
	for (int i = 1; i <= n; i++) p2[i] = add(p2[i - 1], p2[i - 1]);
	for (int &x : a) cin >> x;
	for (int &x : p) cin >> x, x--;
	for (int type = 0; type < 2; type++) {
		for (int i = 0; i < n; i++) pre[i] = suf[i] = 0;
		for (int i = 0; i < m; i++) {
			pre[p[i]] = p2[i];
			if (p[i] - type >= 0) suf[p[i] - type] = 1;
		}
		for (int i = n - 1, t = 0; i >= 0; i--)
			t = add(t, suf[i]), suf[i] = p2[t];
		vector <int> t1(2 * n), t2(2 * n);
		solve(0, n, pre, suf, t1), pr = pre;
		for (int i = 0; i < n; i++) pre[i] = mul(pre[i], i);
		solve(0, n, pre, suf, t2);
		for (int i = 0; i < n; i++)
			sum = add(sum, mul(a[i], sub(mul(i, t1[2 * i]), t2[2 * i])));
		for (int i = 0, j = 0, s = 0, ws = 0; i < n; i++) {
			for (; j < i && 2 * i - j >= n; j++)
				s = add(s, pr[j]), ws = add(ws, pre[j]);
			sum = add(sum, mul(a[i], sub(mul(s, i), ws)));
		}
		reverse (a.begin(), a.end()), reverse (p.begin(), p.end());
		for (int &x : p) x = n - x - 1;
	}
	printf("%d\n", mul(sum, Pow(sub(p2[m], 1), P - 2)));
	return 0;
}