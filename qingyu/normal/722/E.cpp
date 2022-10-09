#include <bits/stdc++.h>

const int N = 1e6 + 50;
const int K = 25;
const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }

inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

inline int fastpow(int x, int p) {
	int r = 1;
	while (p) {
		if (p & 1) pud(r, x);
		pud(x, x);
		p >>= 1;
	}
	return r;
}

struct pt {
	int x, y;
	inline bool operator<(const pt &rhs) const {
		if (x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}
} p[N];

int n, m, k, s, w[N], fact[N], inv[N], dp[N][K];

inline int comb(int n, int m) {
	if (n < m) return 0;
	return mul(mul(fact[n], inv[m]), inv[n - m]);	
}

inline void init(int n) {
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = mul(i, fact[i - 1]);
	inv[n] = fastpow(fact[n], mod - 2);
	for (int i = n - 1; i >= 0; --i) inv[i] = mul(i + 1, inv[i + 1]);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> n >> m >> k >> s;
	init(n + m);
	w[1] = s;
	--n, --m;
	for (int i = 2; i <= K; ++i) w[i] = (w[i - 1] + 1) / 2;
	for (int i = 1; i <= k; ++i) {
		std::cin >> p[i].x >> p[i].y;
		--p[i].x, --p[i].y;
	}
	++k; p[k].x = n, p[k].y = m;
	std::sort(p + 1, p + k + 1);
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= i && j < K; ++j) {
			dp[i][j] = comb(p[i].x + p[i].y, p[i].x);
			for (int k = 0; k < j; ++k) dpu(dp[i][j], dp[i][k]);
			for (int k = 1; k < i; ++k)
				if (p[k].x <= p[i].x && p[k].y <= p[i].y) {
					dpu(dp[i][j], mul(dp[k][j], comb(p[i].x - p[k].x + p[i].y - p[k].y, p[i].x - p[k].x)));
				}
		}
	}
	int total = comb(n + m, n), rem = total, ans = 0;
 	for (int i = 1; i < K; ++i) {
 		upd(ans, mul(w[i], dp[k][i]));
		dpu(rem, dp[k][i]);	
 	}
 	upd(ans, rem);
 	pud(ans, fastpow(total, mod - 2));
 	std::cout << ans << '\n';
	return 0;
}