#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000;
int n, k, ans;
vector<int> g[maxn + 10];

int dfs(int p, int fa) {
	if (g[p].size() == 1) return 0;
	else {
		vector<int> now;
		for (int i = 0; i < g[p].size(); ++i) {
			int e = g[p][i];
			if (e != fa) now.push_back(dfs(e, p) + 1);
		}
		sort(now.begin(), now.end());
		for (int i = (int)now.size() - 1; i >= 0; --i) {
			int t = now[i] + (i ? now[i - 1] : 0);
			if (t > k) ++ans;
			else return now[i];
		}
		return -1e9;
	}
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		g[l].push_back(r); g[r].push_back(l);
	}
	for (int i = 1; i <= n; ++i)
		if (g[i].size() > 1) {
			if (dfs(i, 0) > 0) ++ans;
			printf("%d", ans);
			return 0;
		}
}