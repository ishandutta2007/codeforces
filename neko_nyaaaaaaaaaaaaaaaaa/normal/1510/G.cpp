#include <bits/stdc++.h>
using namespace std;

vector<int> adj[101];
int deep[101];

void dfs1(int now, int d) {
	deep[now] = d;
	for (int u: adj[now]) {
		dfs1(u, d+1);
		deep[now] = max(deep[now], deep[u]);
	}
}

vector<int> eul;

void dfs2(int now, int &k) {
	k--;
	eul.push_back(now);

	int fi = -1;
	for (int u: adj[now]) {
		if (deep[u] == deep[now] && k > 0) {
			dfs2(u, k);
			fi = u;
			eul.push_back(now);
			break;
		}
	}
	for (int u: adj[now]) {
		if (u != fi && k > 0) {
			dfs2(u, k);
			eul.push_back(now);
		}
	}
}

void solve() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		adj[i].clear(); deep[i] = 0;
	}
	for (int i = 2; i <= n; i++) {
		int p; cin >> p;
		adj[p].push_back(i);
	}
	dfs1(1, 0);

	int kc = k;
	eul.clear();
	dfs2(1, kc);

	reverse(eul.begin(), eul.end());
	//for (int i: eul) cout << i << ' ';
		//cout << '\n';

	map<int, int> cnt;
	for (int i: eul) cnt[i]++;

	while (1) {
		int x = eul.back();
		cnt[x]--;
		if (cnt[x] == 0) break;
		eul.pop_back();
	}

	cout << eul.size()-1 << '\n';
	for (int i: eul) cout << i << ' ';
		cout << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}