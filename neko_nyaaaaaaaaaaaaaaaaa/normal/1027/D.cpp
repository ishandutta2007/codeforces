#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, cnt, t;
vector<int> adj[200001];
vector<int> scc(200001);
vector<int> num(200001);
vector<int> low(200001);
stack<int> s;
vector<int> start(200001, 1);

vector<int> c(200001);

void dfs(int now) {
	t++;
	num[now] = low[now] = t;
	s.push(now);
	for (int u: adj[now]) {
		if (low[u] == 0) dfs(u);
		
		low[now] = min(low[now], low[u]);
	}
	
	if (low[now] == num[now]) {
		cnt++;
		int v;
		do {
			v = s.top();
			num[v] = low[v] = 1000000;
			s.pop();
			scc[v] = cnt;
		} while (now != v);
	}
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		if (i != x) adj[i].push_back(x);
	}
	
	for (int i = 1; i <= n; i++) {
		if (num[i] == 0) {
			dfs(i);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int u: adj[i]) {
			if (scc[i] != scc[u]) {start[scc[i]] = 0;}
		}
	}
	
	vector<int> answer(cnt+1, 1000000);
	for (int i = 1; i <= n; i++) {
		answer[scc[i]] = min(answer[scc[i]], c[i]);
	}
	
	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		if (start[i] == 1) {
			ans += answer[i];
			//cout << answer[i] << " ";
		}
	}
	cout << ans;
	
	return 0;
}