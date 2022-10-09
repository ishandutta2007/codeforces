#include <bits/stdc++.h>

const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

int guess(int x) {
	std::cout << "? " << x << std::endl;
	int y;
	std::cin >> y;
	return y;
}

const int N = 1e6 + 50;
int f[N], ret[N];
bool vis[N];

void solve() {
	int n;
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
		f[i] = vis[i] = ret[i] = 0;
	int total = 0;
	for (int i = 1; i <= n; ++i) {
		if (!f[i]) {
			std::vector<int> circle;
			int init = total;
			int x = guess(i);
			while (!vis[x]) {
				vis[x] = true;
				++total;
				circle.push_back(x);
				x = guess(i);
			}
			//  i  i % |circle|
			//
			int p = -1;
			for (p = 0; p < circle.size(); ++p)
				if (circle[p] == i)
					break;
			for (int i = 0; i < circle.size(); ++i) {
				ret[i] = circle[(p + i) % circle.size()];
			}
			int len = circle.size();
		
			for (int i = 0; i < len; ++i) {
				f[ret[(i - 1 + len) % len]] = ret[i % len];
			}
			//  i  init, init + 1, ..., total 
		}
	}
	std::cout << "! ";
	for (int i = 1; i <= n; ++i) std::cout << f[i] << " ";
	std::cout << '\n';
}

int main() {
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
}