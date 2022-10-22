#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, ns, nb, k, h, d[100][100];
ar<int, 3> s[1000];
ar<int, 2> b[1000];

//Edmonds-Karp Algorithm
//Idea: Augment paths greedily
//Complexity: O(V*E^2)
//Reference: https://cp-algorithms.com/graph/edmonds_karp.html
//Can be extended to return flow values for edges: check reference
template<class T> struct flow_graph { //usually int
	const T INF=2e9; //CHANGE IF LONG LONG
	int n;
	vector<int> par;
	vector<vector<int>> adj;
	vector<vector<T>> cap;
	flow_graph(int _n) : n(_n) {
		par.resize(n);
		adj.resize(n);
		cap.assign(n, vector<T>(n, 0));
	}

	void add(int a, int b, T c) {
		adj[a].push_back(b);
		adj[b].push_back(a);
		cap[a][b] += c;
	}

	T bfs(int s, int t) {
		fill(par.begin(), par.end(), -1);

		queue<pair<int, T>> q;
		q.emplace(s, INF);
		while(!q.empty()) {
			int u = q.front().first;
			T flow = q.front().second;
			q.pop();
			for (int v: adj[u]) {
				if (par[v] == -1 && cap[u][v] > 0) {
					par[v] = u;
					T new_flow = min(flow, cap[u][v]);
					if (v == t) return new_flow;
					q.emplace(v, new_flow);
				}
			}
		}
		return 0; //impossible to improve
	}

	T max_flow(int s, int t) {
		T flow=0;

		T new_flow;
		while(new_flow = bfs(s, t)) {
			assert(new_flow > 0);
			flow += new_flow;
			int cur = t;
			while(cur != s) {
				int last = par[cur];
				assert(last >= 0);
				cap[last][cur] -= new_flow;
				cap[cur][last] += new_flow;
				cur = last;
			}
		}
		return flow;
	}
	T max_flow() {
		return max_flow(0, n - 1);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		memset(d[i], 0x3f, sizeof(d[i]));
		d[i][i] = 0;
	}
	for (int i = 0; i < m; ++i) {
		int a, b; cin >> a >> b, --a, --b;
		d[a][b] = d[b][a] = 1;
	}
	for (int x = 0; x < n; ++x) for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) d[i][j] = min(d[i][j], d[i][x] + d[x][j]);
	cin >> ns >> nb >> k >> h;
	flow_graph<int> fg(2 + ns + nb);
	for (int i = 0; i < ns; ++i) cin >> s[i][0] >> s[i][1] >> s[i][2], --s[i][0], fg.add(0, i + 1, 1);
	for (int i = 0; i < nb; ++i) cin >> b[i][0] >> b[i][1], --b[i][0], fg.add(ns + i + 1, ns + nb + 1, 1);
	for (int i = 0; i < ns; ++i) for (int j = 0; j < nb; ++j) if (d[s[i][0]][b[j][0]] <= s[i][2] && s[i][1] >= b[j][1]) fg.add(i + 1, ns + j + 1, 1);
	cout << min((ll)fg.max_flow() * k, (ll)ns * h);
	return 0;
}