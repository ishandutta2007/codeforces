#include <stdio.h>
#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 250010;

int d[N];
vector <pair<int,int> > G[N];

multiset <int> H[N];
int s[N], dp[N][2];

int n, per[N], vis[N], Max;

vector <int> ins, del;

void dfs(int x, int fa) {
	int o = d[x] - Max; vis[x] = Max;
	while (H[x].size() && H[x].size() > o) {
		auto it = H[x].end(); it--;
		s[x] -= (*it), H[x].erase(it);
	}
	int temp = 0;
	for (pair<int,int> i : G[x]) {
		int v = i.first;
		if (v == fa || d[v] <= Max) continue;
		dfs(v, x);
	}
	ins.clear(), del.clear();
	for (pair<int,int> i : G[x]) {
		int v = i.first, w = i.second;
		if (v == fa || d[v] <= Max) continue;
		int t = dp[v][1] + w - dp[v][0];
		if (t <= 0) {
			temp += dp[v][1] + w, o--;
			continue;
		}
		temp += dp[v][0], del.push_back(t);
		s[x] += t, H[x].insert(t);
	}
	while (H[x].size() && H[x].size() > o) {
		auto it = H[x].end(); it--;
		ins.push_back(*it);
		s[x] -= *it, H[x].erase(it);
	}
	dp[x][0] = temp + s[x];
	while (H[x].size() && H[x].size() > o - 1) {
		auto it = H[x].end(); it--;
		ins.push_back(*it);
		s[x] -= *it, H[x].erase(it);
	}
	dp[x][1] = temp + s[x];
	for (int i : ins) s[x] += i, H[x].insert(i);
	for (int i : del) s[x] -= i, H[x].erase(H[x].find(i));
}

int cmp1(int x, int y) {
	return d[x] < d[y];
}

int cmp2(pair<int,int> x, pair<int,int> y) {
	return d[x.first] > d[y.first];
}

signed main() {
	scanf("%lld", &n);
	for (int i = 1; i < n; i++) {
		int u, v, w; scanf("%lld%lld%lld", &u, &v, &w);
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
		d[u]++, d[v]++;
	}
	for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end(), cmp2);
	for (int i = 1; i <= n; i++) per[i] = i, vis[i] = -1;
	sort (per + 1, per + n + 1, cmp1);
	for (int x = 0, j = 1; x < n; x++) {
		Max = x;
		while (j <= n && d[per[j]] <= x) {
			int p = per[j++];
			for (pair<int,int> i : G[p]) {
				int v = i.first, w = i.second;
				if (d[v] <= Max) continue;
				G[v].pop_back();
				s[v] += w, H[v].insert(w);
			}
		}
		int temp = 0;
		for (int i = j; i <= n; i++) {
			int p = per[i];
			if (vis[p] == Max) continue;
			dfs(p, 0), temp += dp[p][0];
		}
		printf("%lld ", temp);
	}
	puts("");
	return 0;
}