#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;
const int N = 1e5 + 5;

int n, p[N];
vector<vector<int>> cycles;
set<pair<int, int>> edges;

bool visited[N];

void combine(int a, int b) {
	int na = cycles[a].size(), nb = cycles[b].size();
	for (int i = 0, j = 0;; i = (i + 1) % na, j = (j + 1) % nb) {
		if (edges.count(make_pair(cycles[a][i], cycles[b][j]))) {
			break;
		}
		edges.insert(make_pair(cycles[a][i], cycles[b][j]));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i], --p[i];

	if (n == 1) {
		cout << "YES\n";
		return 0;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		vector<int> cycle = {i};

		int ptr = p[i];
		while (ptr != i) {
			visited[ptr] = true;
			cycle.push_back(ptr);
			ptr = p[ptr];
		}
		cycles.push_back(cycle);
	}

	vector<int> cycle_ids(cycles.size());
	iota(cycle_ids.begin(), cycle_ids.end(), 0);

	sort(cycle_ids.begin(), cycle_ids.end(), [&] (int i, int j) {
		return cycles[i].size() < cycles[j].size();
	});

	int root = cycle_ids[0];
	if (cycles[root].size() > 2) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 1; i < cycles.size(); i++) {
		int id = cycle_ids[i];
		if (cycles[id].size() % cycles[root].size() != 0) {
			cout << "NO\n";
			return 0;
		}
		combine(root, id);
	}

	if (cycles[root].size() == 2) {
		edges.emplace(cycles[root][0], cycles[root][1]);
	}

	cout << "YES\n";
	for (auto &[u, v] : edges) {
		cout << u + 1 << ' ' << v + 1 << '\n';
	}
	return 0;
}