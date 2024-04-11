#include <bits/stdc++.h>

typedef long long LL;
constexpr int N = 2e5 + 10;
std::vector<int> adj[N];
int c[N];
LL best[N];
int picked[N], down[N];
bool hold[N];

std::set<int> ans;
void dfs(int u, int p) {
	int mx = -1, mxv = -1;
	bool repeat = false;

	for (int v: adj[u]) {
		if (v == p) continue;
		dfs(v, u);
		best[u] += best[v];
		// mx = max(mx, {c[picked[v]], v});
		if (mx == c[picked[v]]) {
			repeat = true;
		} else if (mx < c[picked[v]]) {
			mx = c[picked[v]];
			mxv = v;
			repeat = false;
		}
	}

	if (mx == -1) {
		best[u] = c[u];
		picked[u] = u;
		ans.insert(u);
		return;
	}

	if (c[u] < mx) {
		best[u] -= mx;
		best[u] += c[u];

		if (!repeat) {
			int w = picked[mxv];
			while (w != -1 && !hold[w]) {
				ans.erase(w);
				w = down[w];
			}
		}
		ans.insert(u);
		// trace("remove", 1+picked[v], "instead", 1+u);
		picked[u] = u;
	} else if (c[u] > mx) {
		mxv = picked[mxv];
		picked[u] = mxv;
		if (repeat) hold[mxv] = true;
	} else if (c[u] == mx) {
		picked[u] = u;
		if (!repeat) down[u] = picked[mxv];
		ans.insert(u);
	}
}


inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;
}

int main() {
	int n = read();
	for (int i = 0; i < n; i++) c[i] = read();
	for (int i = 0; i < n - 1; i++) {
		int u = read() - 1, v = read() - 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	memset(picked, -1, sizeof picked);
	memset(down, -1, sizeof down);
	dfs(0, 0);
	std::cout << best[0] << " " << ans.size() << std::endl;
	//printf("%d %d\n", best[0], (int)ans.size());
	for (int x: ans) printf("%d ", x + 1);
	
	return 0;
}