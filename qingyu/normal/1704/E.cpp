#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 50;
const int mod = 998244353;
 
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

typedef long long ll;

int n, m, a[N], d[N];
vector<int> G[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		std::cin >> n >> m;
		for (int i = 1; i <= n; ++i) cin >> a[i];
		for (int i = 1; i <= m; ++i) {
			int x, y;
			cin >> x >> y;
			++d[y];
			G[x].push_back(y);
		}
		vector<int> ord;
		queue<int> que;
		auto ins = [&](int x) {
			que.emplace(x);
			ord.push_back(x);
		};
		for (int i = 1; i <= n; ++i)
			if (!d[i]) {
				ins(i);
			}
		while (!que.empty()) {
			int x = que.front(); que.pop();
			for (int y : G[x]) {
				if (--d[y] == 0) {
					ins(y);
				}
			}
		}
		reverse(ord.begin(), ord.end());
		int ans = 0;
		for (int _ = 1; _ <= n; ++_) {
			bool ok = false;
			for (int x : ord) {
				if (a[x]) {
					--a[x];
					ok = true;
					for (int y : G[x])
						++a[y];
				}
			}
			if (ok) ++ans;
		}
		reverse(ord.begin(), ord.end());
		for (int x : ord) {
			a[x] %= mod;
			for (int y : G[x])
				upd(a[y], a[x]);
		}
		upd(ans, a[ord.back()]);
		cout << ans << '\n';
		for (int i = 1; i <= n; ++i) G[i].clear();
	}
	return 0;
}