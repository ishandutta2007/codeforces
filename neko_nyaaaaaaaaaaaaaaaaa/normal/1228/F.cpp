#include <bits/stdc++.h>
using namespace std;

int n, pw; 
vector<int> adj[131074];
int trigger = 0;

void dfs1(int now, int prev, vector<int> &answer, vector<int> &level, vector<int> &lf, vector<int> &mx) {
	level[now] = level[prev] + 1;
	int numchild = 0;
	for (int u: adj[now]) {
		if (u != prev) {
			dfs1(u, now, answer, level, lf, mx);
			numchild++;
			mx[now] = max(mx[now], mx[u]);
		}
	}

	if (numchild == 1 || numchild == 3) {
		answer.push_back(now);
		if (numchild == 1) trigger = 1;
	} else if (numchild > 3) {
		cout << 0; exit(0);
	} else if (numchild == 0) {
		lf.push_back(now);
		mx[now] = level[now];
	}
}

void inc(int now, int prev, vector<int> &level) {
	level[now]++;
	for (int u: adj[now]) {
		if (u != prev) inc(u, now, level);
	}
}

void solve1(int root) {
	// removed node is not a child of the root
	// if there is a node with 3 children or 1 child, it has to be the answer
	vector<int> answer;
	vector<int> level(n+1);
	vector<int> mx(n+1);
	vector<int> lf;

	dfs1(root, 0, answer, level, lf, mx);
	int max_lv = *max_element(mx.begin(), mx.end());
	if (answer.size() != 1) {
		cout << 0; exit(0);	
	}
	if (trigger) {
		int ans = answer[0];
		adj[ans].push_back(n+1);
		adj[n+1].push_back(ans);
		level[n+1] = level[ans] + 1;
		lf.push_back(n+1);
	} else {
		int ans = answer[0];
		for (int u: adj[ans]) {
			if (level[u] > level[ans] && mx[u] != max_lv) {
				inc(u, ans, level);
			} 
		}
	}

	for (int i: lf) {
		if (level[i] != max_lv) {
			cout << 0; exit(0);
		}
	}

	cout << "1\n" << answer[0]; exit(0);
}

void check(int now, int prev) {
	int numchild = 0;
	for (int u: adj[now]) {
		if (u != prev) {
			numchild++;
			check(u, now);
		} 
	}
	if (numchild != 0 && numchild != 2) {
		cout << 0; exit(0);
	}
}

void solve2() {
	// removed node is a child of the root
	// might as well say removed node is the root
	vector<int> dist(n+1);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			q.push(i); dist[i] = 1;
		}
	}

	while (q.size()) {
		int now = q.front(); q.pop();
		for (int u: adj[now]) {
			if (dist[u] == 0) {
				dist[u] = dist[now] + 1;
				q.push(u);
			}
		}
	}

	// find two nodes with the maximum BFS distance
	// there should be exactly two nodes
	int mx = *max_element(dist.begin(), dist.end());
	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == mx) {
			ans.push_back(i);
		}
	}
	if (ans.size() != 2) {
		cout << 0; exit(0);
	}

	// now both of them are root, just check if they have exactly two children
	check(ans[0], ans[1]);
	check(ans[1], ans[0]);

	cout << 2 << '\n';
	cout << ans[0] << ' ' << ans[1];
}

int get_cent() {
	vector<int> dist(n+1);
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 1) {
			q.push(i); dist[i] = 1;
		}
	}

	while (q.size()) {
		int now = q.front(); q.pop();
		for (int u: adj[now]) {
			if (dist[u] == 0) {
				dist[u] = dist[now] + 1;
				q.push(u);
			}
		}
	}

	int mx = *max_element(dist.begin(), dist.end());
	for (int i = 1; i <= n; i++) {
		if (dist[i] == mx) {
			return i;
		}
	}
	return -1;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	// if there is a node of degree 2, then answer is 1-root
	// else, answer is 2-nodes that are directly in the middle
	// just check for correctness afterwards

	cin >> n; pw = n;
	n = (1 << n) - 2;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> rt;
	for (int i = 1; i <= n; i++) {
		if (adj[i].size() == 2) {
			rt.push_back(i);
		}
	}
	//	cout << rt.size() << '\n';
	//for (int i: rt) cout << i << ' '; cout << '\n';

	if (rt.size() == 2) {
		solve1(get_cent());
	} else if (rt.size() == 1) {
		solve1(rt[0]);
	} else if (rt.empty()) {
		solve2();
	} else {
		cout << 0;
	}

	return 0;
}