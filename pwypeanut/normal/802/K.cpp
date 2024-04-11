#include <bits/stdc++.h>
using namespace std;

int N, K;
vector< pair<int, int> > V[100005], child[100005];
int dp[100005][2];

void dfs(int x, int p) {
	for (int i = 0; i < V[x].size(); i++) {
		if (V[x][i].first == p) continue;
		child[x].push_back(V[x][i]);
		dfs(V[x][i].first, x);
	}
}

int f(int x, int ret) {
	if (dp[x][ret] != -1) return dp[x][ret];
	if (ret) {
		vector<int> v;
		for (int i = 0; i < child[x].size(); i++) v.push_back(f(child[x][i].first, 1) + child[x][i].second);
		sort(v.begin(), v.end(), greater<int>());
		int ans = 0;
		for (int i = 0; i < min((int)v.size(), K - 1); i++) ans += v[i];
		return dp[x][ret] = ans;
	} else {
		int ans = 0;
		vector<pair<int, int> > v;
		vector<int> cost;
		for (int i = 0; i < child[x].size(); i++) {
			v.push_back(make_pair(f(child[x][i].first, 1) + child[x][i].second, i));
			cost.push_back(f(child[x][i].first, 0) + child[x][i].second);
		}
		sort(v.begin(), v.end(), greater< pair<int, int> >());
		bool sel[child[x].size()];
		memset(sel, 0, sizeof(sel));
		int nxt = 0;
		for (int i = 0; i < min((int)v.size(), K - 1); i++) {
			ans += v[i].first;
			sel[v[i].second] = 1;
		}
		if (v.size() >= K) nxt = v[K - 1].first;
		int mx = 0;
		for (int i = 0; i < v.size(); i++) {
			if (!sel[v[i].second]) {
				mx = max(mx, ans + cost[v[i].second]);
			} else {
				mx = max(mx, ans + cost[v[i].second] - v[i].first + nxt);
			}
		}
		return dp[x][ret] = mx;
	}
}

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N - 1; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		V[a].push_back(make_pair(b, c));
		V[b].push_back(make_pair(a, c));
	}
	memset(dp, -1, sizeof(dp));
	dfs(0, -1);
	printf("%d\n", f(0, 0));
}