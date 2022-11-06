#include <bits/stdc++.h>
using namespace std;

int N, M, cn, idx, rin[200005];
bool inv, R[100005], inc[200005];
vector<int> D[100005], adj[200005];
stack<int> S;

void dfs(int n) {
	bool ro = 1;
	rin[n] = idx++;
	for (auto u : adj[n]) {
		if (rin[u] == -1) dfs(u);
		if (!inc[u] && rin[u] < rin[n])
			rin[n] = rin[u], ro = 0;
	}
	if (ro) {
		vector<int> v;
		inc[n] = 1;
		v.push_back(n);
		while (!S.empty() && rin[n] <= rin[S.top()]) {
			int w = S.top();
			S.pop();
			rin[w] = cn;
			inc[w] = 1;
			v.push_back(w);
		}
		rin[n] = cn;
		sort(v.begin(), v.end());
		for (int i : v)
			if (i <= M && binary_search(v.begin(), v.end(), i + M))
				inv = 1;
		cn++;
	} else S.push(n);
}

int main() {
	memset(rin, -1, sizeof rin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> R[i];
	for (int i = 1, r, x; i <= M; i++) {
		cin >> x;
		while (x--)
			cin >> r, D[r].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		if (R[i]) {
			adj[D[i][0]].push_back(D[i][1]);
			adj[D[i][1]].push_back(D[i][0]);
			adj[D[i][0] + M].push_back(D[i][1] + M);
			adj[D[i][1] + M].push_back(D[i][0] + M);
		} else {
			adj[D[i][0] + M].push_back(D[i][1]);
			adj[D[i][1] + M].push_back(D[i][0]);
			adj[D[i][0]].push_back(D[i][1] + M);
			adj[D[i][1]].push_back(D[i][0] + M);
		}
	}
	for (int i = 1; i <= 2 * M; i++)
		if (rin[i] == -1) dfs(i);
	cout << (inv ? "NO" : "YES") << '\n';
}