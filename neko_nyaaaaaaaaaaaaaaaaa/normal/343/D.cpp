#include <bits/stdc++.h>
using namespace std;

int t = 1;
vector<int> adj[500001];
int in[500001], out[500001], par[500001];

void dfs(int now, int prev) {
	par[now] = prev;
	in[now] = t++;
	for (int u: adj[now]) {
		if (u != prev) dfs(u, now);
	}
	out[now] = t;
}

typedef pair<int, int> pii;

set<pii> is;

set<pii>::iterator addInterval(int L, int R) {
	if (L == R) return is.end();
	auto it = is.lower_bound({L, R}), before = it;
	while (it != is.end() && it->first <= R) {
		R = max(R, it->second);
		before = it = is.erase(it);
	}
	if (it != is.begin() && (--it)->second >= L) {
		L = min(L, it->first);
		R = max(R, it->second);
		is.erase(it);
	}
	return is.insert(before, {L, R});
}

void removeInterval(int L, int R) {
	if (L == R) return;
	auto it = addInterval(L, R);
	auto r2 = it->second;
	if (it->first == L) is.erase(it);
	else (int&)it->second = L;
	if (R != r2) is.emplace(R, r2);
}

int is_covered(int l, int r) {
	auto it = is.upper_bound({l+1, -1});
	if (it == is.begin()) return 0;

	it = prev(it);
	return it->first <= l && it->second >= r;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);

	int q; cin >> q;
	while (q--) {
		int que, v; cin >> que >> v;
		if (que == 1) {
			int l = in[v], r = out[v];
			if (par[v] && !is_covered(l, r)) {
				l = in[par[v]], r = in[par[v]] + 1;
				removeInterval(l, r);
			}

			l = in[v], r = out[v];
			addInterval(l, r);
		} else if (que == 2) {
			int l = in[v], r = in[v] + 1;
			removeInterval(l, r);
		} else {
			int l = in[v], r = out[v];
			cout << is_covered(l, r) << '\n';
		}
	}

	return 0;
}