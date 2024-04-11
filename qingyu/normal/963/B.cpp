#include <bits/stdc++.h>

using namespace std;

#define QINGYU_LOCAL
#ifdef QINGYU_LOCAL
#define debug(x) \
        cerr << "Func " << __FUNCTION__ << ", " << "L" << __LINE__ << ": " << #x << " = " << x << '\n'
#else
#define debug(x) 0
#endif

const int mod = 998244353;

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
const int N = 5e5 + 50;
int n, rt, dp[N], fa[N], deg[N];
vector<int> adj[N], G[N];

void dfs(int x) {
	dp[x] = 1;
	for (int y : adj[x]) {
		dfs(y);
		dp[x] ^= dp[y];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		int p;
		cin >> p;
		fa[i] = p;
		if (!p) {
			rt = i;
			continue;
		}
		adj[p].push_back(i);
	}
	dfs(rt);
	if (!dp[rt]) {
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		if (i != rt) {
			if (dp[i]) {
				G[fa[i]].push_back(i);
				++deg[i];
			} else {
				G[i].push_back(fa[i]);
				++deg[fa[i]];
			}
		}
	}
	queue<int> que;
	for (int i = 1; i <= n; ++i)
		if (!deg[i])
			que.emplace(i);
	while (!que.empty()) {
		int x = que.front(); que.pop();
		cout << x << "\n";
		for (int y : G[x]) {
			if (!--deg[y]) {
				que.emplace(y);
			}
		}
	}
}