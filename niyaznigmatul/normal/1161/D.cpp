/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

struct edge {
	int from, to, c;
};

vector<vector<edge>> edges;
vector<int> colors;

bool dfs(int v, int c) {
	colors[v] = c;
	for (auto &e : edges[v]) {
		if (colors[e.to] < 0) {
			if (!dfs(e.to, c ^ e.c)) {
				return false;
			}
		}
		if (colors[e.to] != (c ^ e.c)) {
			return false;
		}
	}
	return true;
}

int const MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	string s;
	cin >> s;
	int n = (int) s.size();
	int ans = 0;
	for (int lenA = n - 1; lenA >= 1; lenA--) {
		int free = 0;
		edges.clear();
		colors.clear();
		auto addV = [&]() {
			edges.emplace_back();
			colors.push_back(-1);
			return free++;
		};
		auto addE = [&](int i, int j, int c) {
			edges[i].push_back({i, j, c});
			edges[j].push_back({j, i, c});
		};
		int zero = addV();
		int one = addV();
		addE(one, zero, 1);
		vector<int> b(n);
		vector<int> a(lenA);
		for (int i = 0; i < n; i++) b[i] = addV();
		for (int i = 0; i < lenA; i++) a[i] = addV();
		addE(one, a[0], 0);
		addE(one, b[0], 0);
		for (int i = 0; i < n - i - 1; i++) addE(b[i], b[n - i - 1], 0);
		for (int i = 0; i < lenA - i - 1; i++) addE(a[i], a[lenA - i - 1], 0);
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') continue;
			int j = i - (n - lenA);
			if (j >= 0) {
				addE(b[i], a[j], s[i] - '0');
			} else {
				addE(b[i], zero, s[i] - '0');
			}
		}
		if (!dfs(zero, 0)) continue;
		int cur = 1;
		for (int i = 0; i < free; i++) {
			if (colors[i] >= 0) continue;
			if (!dfs(i, 0)) {
				cur = 0;
				break;
			}
			cur = (cur + cur) % MOD;
		}
		ans = (ans + cur) % MOD;
	}
	cout << ans << endl;
}