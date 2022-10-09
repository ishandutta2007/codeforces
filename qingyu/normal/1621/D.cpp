#include <bits/stdc++.h>

const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

const int M = 505;
const int N = 1e6 + 50;

int n, m;
int c[M][M];
long long d[N];

int id(int x, int y) {
	return x * m + y;
}

void solve() {
	std::cin >> n;
	m = n * 2;
	long long ans = 0;
	long long extra = 1e10;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			std::cin >> c[i][j];
			auto upd = [&]() {
				extra = std::min(extra, (long long)c[i][j]);
			};
			if (i >= n && j >= n)
				ans += c[i][j];
			else if (i >= n || j >= n) {
				if (i == 0 && j == n) upd();
				if (i == 0 && j == m - 1) upd();
				if (i == n - 1 && j == n) upd();
				if (i == n - 1 && j == m - 1) upd();
				if (i == n && j == 0) upd();
				if (i == m - 1 && j == 0) upd();
				if (i == n && j == n - 1) upd();
				if (i == m - 1 && j == n - 1) upd();
			}
		}

	std::cout << extra + ans << '\n';
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