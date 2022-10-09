#include <bits/stdc++.h>

const int N = 2e5 + 50;

long long ans;
int n, h[N], f[N];
std::vector<int> G[N];

void dfs(int x, int fa = 0) {
	int mx = 0, smx = 0;
	for (int y : G[x]) {
		if (y != fa) {
			dfs(y, x);
			if (f[y] > mx) {
				smx = mx;
				mx = f[y];
			}
			else if (f[y] > smx) {
				smx = f[y];
			}
		}
	}
	if (fa != 0) {
		ans += std::max(0, h[x] - mx);
		f[x] = std::max(h[x], mx);
	}
	else {
		ans += std::max(0, h[x] - mx) + std::max(0, h[x] - smx);
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	int rt = 1;
	for (int i = 1; i <= n; ++i) {
		std::cin >> h[i];
		if (h[i] > h[rt])
			rt = i;
	}
	for (int i = 1; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(rt);
	std::cout << ans << '\n';
}