#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 2e5;

int n, color[N];
pair<int, int> e[N];

int inc[2 * N][2];
set<int> g[2 * N];

bool visited[2 * N], mark[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0, u, v; i < n; i++) {
		cin >> u >> v;
		--u; --v;
		g[u].insert(i);
		g[v + N].insert(i);
		e[i] = {u, v + N};
	}

	set<int> s;
	for (int x = 0; x < 2 * N; x++) {
		if (g[x].size() % 2 != 0) {
			s.insert(x);
		}
	}

	vector<pair<int, int>> edel;
	while (!s.empty()) {
		int x = *s.begin();
		s.erase(s.begin());
		int i = *g[x].begin();
		g[x].erase(g[x].begin());
		int to = x ^ e[i].first ^ e[i].second;
		g[to].erase(i);
		edel.emplace_back(i, to);
		if (g[to].size() % 2 != 0)
			s.insert(to);
		else s.erase(to);
	}

	map<pair<int, int>, int> mp;
	for (int x = 0; x < 2 * N; x++) {
		for (int i : g[x]) {
			mp[e[i]] = i;
		}
	}

	for (int x = 0; x < 2 * N; x++) {
		if (!visited[x]) {
			vector<int> st, circuit;
			st.push_back(x);

			while (!st.empty()) {
				int y = st.back();
				visited[y] = true;
				if (g[y].size() == 0) {
					circuit.push_back(y);
					st.pop_back();
				} else {
					int i = *g[y].begin();
					g[y].erase(g[y].begin());
					mark[i] = true;
					int to = y ^ e[i].first ^ e[i].second;
					g[to].erase(i);
					st.push_back(to);
				}
			}

			for (int i = 1, col = 0; i < circuit.size(); i++, col ^= 1) {
				int xx = circuit[i - 1], yy = circuit[i];
				if (xx >= N) swap(xx, yy);
				color[mp[make_pair(xx, yy)]] = col;
				inc[xx][col]++;
				inc[yy][col]++;
			}
		}
	}

	reverse(edel.begin(), edel.end());
	for (auto [i, to] : edel) {
		if (inc[to][0] >= inc[to][1])
			color[i] = 1;
		else color[i] = 0;
		int x = to ^ e[i].first ^ e[i].second;
		inc[x][color[i]]++;
		inc[to][color[i]]++;
	}

	for (int i = 0; i < n; i++) cout << (color[i] ? 'r' : 'b'); cout << '\n';
	return 0;
}