#include <bits/stdc++.h>

const int N = 1e6 + 50;
const int mod = 998244353;

int n, q;
char s[N];

struct matrix_t {
	int n, m, a[3][3];
	matrix_t(int n = 0, int m = 0) : n(n), m(m) {
		memset(a, 0, sizeof a);
	}
} A(3, 3), B(3, 3), C(3, 3), a[N], prod[N << 2];

inline matrix_t operator*(const matrix_t &a, const matrix_t &b) {
	assert(a.m == b.n);
	matrix_t r(a.n, b.m);
	for (int i = 0; i < a.n; ++i)
		for (int j = 0; j < a.m; ++j) {
			r.a[i][j] = 0x3f3f3f3f;
			for (int k = 0; k < b.m; ++k)
				r.a[i][j] = std::min(r.a[i][j], a.a[i][k] + b.a[k][j]);
		}
	return r;
}

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

inline void push_up(int o) {
	prod[o] = prod[rc(o)] * prod[lc(o)];
}

void build(int o, int l, int r) {
	if (l == r) prod[o] = a[l];
	else {
		const int mid = l + r >> 1;
		build(lc(o), l, mid);
		build(rc(o), mid + 1, r);
		push_up(o);
	}
}

void modify(int o, int l, int r, int p, matrix_t R) {
	if (l == r) {
		prod[o] = R;
	}
	else {
		const int mid = l + r >> 1;
		if (p <= mid) modify(lc(o), l, mid, p, R);
		else modify(rc(o), mid + 1, r, p, R);
		push_up(o);
	}
}

int main() {
	scanf("%d%d", &n, &q);
	scanf("%s", s + 1);
	const int inf = 0x3f3f3f3f;
	A.a[0][0] = 1, A.a[0][1] = inf, A.a[0][2] = inf;
	A.a[1][0] = 0, A.a[1][1] = 0, A.a[1][2] = inf;
	A.a[2][0] = 0, A.a[2][1] = 0, A.a[2][2] = 0;
	B.a[0][0] = 0, B.a[0][1] = inf, B.a[0][2] = inf;
	B.a[1][0] = 0, B.a[1][1] = 1, B.a[1][2] = inf;
	B.a[2][0] = 0, B.a[2][1] = 0, B.a[2][2] = 0;
	C.a[0][0] = 0, C.a[0][1] = inf, C.a[0][2] = inf;
	C.a[1][0] = 0, C.a[1][1] = 0, C.a[1][2] = inf;
	C.a[2][0] = 0, C.a[2][1] = 0, C.a[2][2] = 1;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'a') a[i] = A;
		else if (s[i] == 'b') a[i] = B;
		else a[i] = C;
	}
	build(1, 1, n);
	matrix_t res(3, 1);
	res.a[0][0] = res.a[1][0] = res.a[2][0] = 0;
	while (q--) {
		int p;
		char s[4], ch;
		scanf("%d%s", &p, s), ch = s[0];
		if (ch == 'a') modify(1, 1, n, p, A);
		else if (ch == 'b') modify(1, 1, n, p, B);
		else modify(1, 1, n, p, C);
		matrix_t ans = prod[1] * res;
		printf("%d\n", std::min(std::min(ans.a[0][0], ans.a[1][0]), ans.a[2][0]));
	}
	return 0;
}