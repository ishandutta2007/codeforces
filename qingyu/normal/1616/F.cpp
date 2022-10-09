#include <bits/stdc++.h>

const int N = 550;
const int M = 1e4 + 50;

int n, m, A[N][N];

struct Z3vec {
	std::bitset<N> A, B, C;
	Z3vec() {
		A.reset();
		B.reset();
		C = ~(A ^ B);
	}
	Z3vec(std::bitset<N> A, std::bitset<N> B) : A(A), B(B), C(~(A ^ B)) {

	}
	void set(int k, int v) {
		assert(0 <= v && v < 3);
		A.reset(k);
		B.reset(k);
		C.reset(k);
		if (v == 0) {
			C.set(k);
		}
		else if (v == 1) {
			A.set(k);
		}
		else {
			B.set(k);
		}
	}
	void clear() {
		A.reset();
		B.reset();
		C = ~(A ^ B);
	}
	int get(int k) {
		if (A[k]) return 1;
		else if (B[k]) return 2;
		return 0;
	}
} Z[M];

Z3vec operator+(const Z3vec &lhs, const Z3vec &rhs) {
	auto A = (lhs.C & rhs.A) | (lhs.A & rhs.C) | (lhs.B & rhs.B);
	// 1 + 0, 0 + 1, 2 + 2
	auto B = (lhs.A & rhs.A) | (lhs.B & rhs.C) | (lhs.C & rhs.B);
	// 1 + 1, 0 + 2, 2 + 0
	return Z3vec(A, B);
}

Z3vec operator-(const Z3vec &lhs, const Z3vec &rhs) {
	auto A = (lhs.A & rhs.C) | (lhs.B & rhs.A) | (lhs.C & rhs.B);
	// 1 - 0, 2 - 1, 0 - 2
	auto B = (lhs.B & rhs.C) | (lhs.C & rhs.A) | (lhs.A & rhs.B);
	// 2 - 0 0 - 1 1 - 2
	return Z3vec(A, B);
}

void operator+=(Z3vec &lhs, const Z3vec &rhs) {
	auto A = (lhs.C & rhs.A) | (lhs.A & rhs.C) | (lhs.B & rhs.B);
	// 1 + 0, 0 + 1, 2 + 2
	auto B = (lhs.A & rhs.A) | (lhs.B & rhs.C) | (lhs.C & rhs.B);
	// 1 + 1, 0 + 2, 2 + 0
	lhs.A = A, lhs.B = B;
	lhs.C = ~(lhs.A ^ lhs.B);
}

void operator-=(Z3vec &lhs, const Z3vec &rhs) {
	auto A = (lhs.A & rhs.C) | (lhs.B & rhs.A) | (lhs.C & rhs.B);
	// 1 - 0, 2 - 1, 0 - 2
	auto B = (lhs.B & rhs.C) | (lhs.C & rhs.A) | (lhs.A & rhs.B);
	// 2 - 0 0 - 1 1 - 2
	lhs.A = A, lhs.B = B;
	lhs.C = ~(lhs.A ^ lhs.B);
}

int p[N], sol[N], ans[N];

bool gauss(int n, int m) {
	int lst = 1;
	memset(p, 0, sizeof p);
	for (int i = 1; i <= n; ++i) {	
		int k = -1;
		for (int j = lst; j <= m; ++j) {
			assert(Z[j].A[i] + Z[j].B[i] + Z[j].C[i] == 1);
			if (Z[j].C[i] == 0) {
				k = j;
				break;
			}
		}
		if (k == -1) {
			continue;
		}
		p[i] = lst;
		std::swap(Z[lst], Z[k]);
		int x = Z[lst].get(i);
		for (int j = 1; j <= m; ++j)
			if (lst != j) {
				int t = (x * Z[j].get(i)) % 3;
				if (t != 0) {
					auto w = Z[lst];
					if (t == 2) w += w;
					Z[j] -= w;
					assert(Z[j].get(i) == 0);
				}
			}
		++lst;
	}
	for (int i = 1; i <= n; ++i) {
		if (p[i]) sol[i] = (Z[p[i]].get(i) * Z[p[i]].get(n + 1)) % 3;
		else sol[i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int xorsum = 0;
		for (int j = 1; j <= n; ++j)
			xorsum += sol[j] * Z[i].get(j);
		xorsum %= 3;
		if (xorsum != Z[i].get(n + 1))
			return false;
	}
	return true;
}

void solve() {
	int n, m;
	std::cin >> n >> m;
	std::vector<int> u(m + 1), v(m + 1);
	std::vector<std::vector<int>> G(n + 1, std::vector<int>(n + 1, -2));
	auto id = G;
	int cntv = 0, cnte = 0;
	for (int i = 1; i <= m; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;
		u[i] = a, v[i] = b;
		if (c != -1) --c;
		G[a][b] = G[b][a] = c;
		if (c == -1) {
			++cntv;
			id[a][b] = id[b][a] = cntv;
		}
	}
	for (int a = 1; a <= n; ++a)
		for (int b = a + 1; b <= n; ++b)
			for (int c = b + 1; c <= n; ++c)
				if (G[a][b] != -2 && G[a][c] != -2 && G[b][c] != -2) {
					if (G[a][b] != -1 && G[a][c] != -1 && G[b][c] != -1) {
						if ((G[a][b] + G[a][c] + G[b][c]) % 3 != 0) {
							puts("-1");
							return;
						}
					}
					else {
						++cnte;
						int xorsum = 0;
						auto add = [&](int a, int b) {
							if (G[a][b] == -1) {
								Z[cnte].set(id[a][b], 1);
							}
							else {
								xorsum -= G[a][b];
							}
						};
						add(a, b); add(a, c); add(b, c);
						xorsum = (xorsum % 3 + 3) % 3;
						Z[cnte].set(cntv + 1, xorsum);
					}
				}
	if (!gauss(cntv, cnte)) {
		puts("-1");
	}
	else {
		for (int i = 1; i <= m; ++i) {
			int a = u[i], b = v[i];
			if (G[a][b] != -1) {
				ans[i] = G[a][b];
			}
			else {
				ans[i] = sol[id[a][b]];
			}
		}	
		for (int i = 1; i <= m; ++i) {
				printf("%d ", ans[i] + 1);
		}
		putchar('\n');
	}
	for (int i = 1; i <= cnte; ++i)
		Z[i].clear();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
}