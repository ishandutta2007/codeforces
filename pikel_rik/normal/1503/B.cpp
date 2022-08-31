#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> a(n, vector<int>(n));

	array<vector<pair<int, int>>, 2> v;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[(i + j) % 2].emplace_back(i, j);
		}
	}

	int alice, bob;
	while (!v[0].empty() && !v[1].empty()) {
		cin >> alice;
		bob = (alice == 1 ? 2 : 1);

		auto p = v[bob % 2].back();
		v[bob % 2].pop_back();
		cout << bob << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
	}

	array<int, 2> cols = {3};
	if (v[0].empty()) {
		cols[1] = 1;
	} else {
		cols[1] = 2;
	}

	v[0].insert(v[0].begin(), v[1].begin(), v[1].end());
	while (!v[0].empty()) {
		auto p = v[0].back();
		v[0].pop_back();

		cin >> alice;
		bob = (alice == cols[0] ? cols[1] : cols[0]);
		cout << bob << ' ' << p.first + 1 << ' ' << p.second + 1 << endl;
	}
	return 0;
}