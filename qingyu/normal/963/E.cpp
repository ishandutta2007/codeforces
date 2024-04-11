#include <bits/stdc++.h>

using namespace std;

#define QINGYU_LOCAL
#ifdef QINGYU_LOCAL
#define debug(x) \
        cerr << "Func " << __FUNCTION__ << ", " << "L" << __LINE__ << ": " << #x << " = " << x << '\n'
#else
#define debug(x) 0
#endif

const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }  
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int64_t p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

const int N = 150;
int R, p1, p2, p3, p4;

bool ok(int x, int y) {
	return (R - x) * (R - x) + (R - y) * (R - y) <= R * R;
}

struct formula_t {
	int eq[N], c; 
	formula_t() : c(0) {
		memset(eq, 0, sizeof eq);
	}
	// sum_i eq[i] * x_i + c
} eq[N][N];

formula_t operator+(const formula_t &lhs, const formula_t &rhs) {
	formula_t ret;
	for (int i = 0; i < N; ++i) {
		ret.eq[i] = inc(lhs.eq[i], rhs.eq[i]);
	}
	ret.c = inc(lhs.c, rhs.c);
	return ret;
}
formula_t operator-(const formula_t &lhs, const formula_t &rhs) {
	formula_t ret;
	for (int i = 0; i < N; ++i) {
		ret.eq[i] = dec(lhs.eq[i], rhs.eq[i]);
	}
	ret.c = dec(lhs.c, rhs.c);
	return ret;
}
formula_t operator+(const formula_t &lhs, const int k) {
	formula_t ret = lhs;
	upd(ret.c, k);
	return ret;
}
formula_t operator-(const formula_t &lhs, const int k) {
	formula_t ret = lhs;
	dpu(ret.c, k);
	return ret;
}
formula_t operator*(const formula_t &lhs, const int k) {
	formula_t ret;
	for (int i = 0; i < N; ++i) {
		ret.eq[i] = mul(lhs.eq[i], k);
	}
	ret.c = mul(lhs.c, k);
	return ret;
}
formula_t operator*(const int k, const formula_t &lhs) {
	formula_t ret;
	for (int i = 0; i < N; ++i) {
		ret.eq[i] = mul(lhs.eq[i], k);
	}
	ret.c = mul(lhs.c, k);
	return ret;
}

int n, a[N][N], tot, x[N];

void add_equation(formula_t F) {
	//printf("Add-equation: ");
	//for (int i = 1; i <= n; ++i)
	//	printf("%d, ", F.eq[i]);
	//printf("[c = %d]\n", F.c);
	++tot;
	for (int i = 1; i <= n; ++i) {
		a[tot][i] = F.eq[i];
	}
	a[tot][n + 1] = dec(0, F.c);
}
void go() {
	printf("Matrix A:\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			printf("%d ", a[i][j]);
		}
		printf("[%d]\n", a[i][n + 1]);
	}
}
void gauss() {
	//go();
	for (int i = 1; i <= n; ++i) {
		for (int j = i; j <= n; ++j)
			if (a[j][i]) {
				swap(a[i], a[j]);
				break;
			}
		if (!a[i][i]) throw;
		for (int j = 1; j <= n; ++j) {
			if (i != j) {
				int t = mul(a[j][i], fastpow(a[i][i], mod - 2));
				for (int k = 1; k <= n + 1; ++k) {
					dpu(a[j][k], mul(a[i][k], t));
				}
				assert(!a[j][i]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j)
			if (i != j) assert(!a[i][j]);
		x[i] = mul(a[i][n + 1], fastpow(a[i][i], mod - 2));
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int a1, a2, a3, a4;
	cin >> R >> a1 >> a2 >> a3 >> a4;
	int inv = fastpow(a1 + a2 + a3 + a4, mod - 2);
	p1 = mul(a1, inv);
	p2 = mul(a2, inv);
	p3 = mul(a3, inv);
	p4 = mul(a4, inv);
	n = 2 * R + 1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
	for (int i = 0; i <= 2 * R; ++i) {
		for (int j = 0; j <= 2 * R; ++j) {
			if (ok(i, j)) {
				if (!ok(i - 1, j)) {
					que.emplace(i, j);
					eq[i][j].eq[j + 1] = 1;
				}
			}
		}
	}
	while (!que.empty()) {
		auto [x, y] = que.top();
		//printf("x = %d, y = %d\n", x, y);
		//printf("formula: ");
		//for (int i = 1; i <= n; ++i) printf("%d, ", eq[x][y].eq[i]);
		//printf("c = %d\n", eq[x][y].c);
		que.pop();
		int invp3 = fastpow(p3, mod - 2);
		formula_t e1 = eq[x][y], e2, e3, e4 = eq[x][y + 1];
		if (x > 0)
			e2 = eq[x - 1][y];
		if (y > 0)
			e3 = eq[x][y - 1];
		eq[x + 1][y] = invp3 * (e1 - 1 - p1 * e2 - p2 * e3 - p4 * e4);
		if (ok(x + 1, y)) {
			que.emplace(x + 1, y);
		}
		else {
			add_equation(eq[x + 1][y]);
		}
	}
	assert(n == tot);
	gauss();
	int ans = eq[R][R].c;
	for (int i = 1; i <= n; ++i) {
		upd(ans, mul(eq[R][R].eq[i], x[i]));
	}
	cout << ans << '\n';
}