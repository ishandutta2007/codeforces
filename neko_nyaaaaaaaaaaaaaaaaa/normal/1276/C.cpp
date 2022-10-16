#include <bits/stdc++.h>
using namespace std;

map<int, int> cnt;

bool cmp(int a, int b) {
	if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
	return a < b;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	vector<int> occ(n+1);
	for (auto [u, v]: cnt) {
		occ[v]++;
	}
	for (int i = 1; i <= n; i++) {
		occ[i] += occ[i-1];
	}

	int max_x = 0, max_p = 0, max_q, has = 0;
	for (int p = 1; p <= n; p++) {
		// at least p occurences
		has += occ[n] - occ[p-1];

		int q = (has/p);
		if (q < p) continue;

		int area = q*p;
		if (max_x < area) {
			max_x = area;
			max_p = p;
			max_q = q;
		}
	}

	int area = max_x, p = max_p, q = max_q;

	cout << area << '\n';
	cout << p << ' ' << q << '\n';
	
	vector<pair<int, int>> takers;
	for (auto [u, v]: cnt) {
		takers.emplace_back(min(v, p), u);
	}	
	sort(takers.begin(), takers.end(), greater<pair<int, int>>());

	vector<int> takes;
	for (auto [v, u]: takers) {
		while (v--) {
			takes.push_back(u);
		}
	}

	int petr = 0;
	vector<vector<int>> ans(p, vector<int>(q));
	for (int i = 0; i < q; i++) {
		for (int j = 0; j < p; j++) {
			ans[j][i] = takes[petr++];
		}
	}

	for (int i = 0; i < p; i++) {
		if (i) rotate(ans[i].begin(), ans[i].begin() + (q - i), ans[i].end());

		for (int j: ans[i]) cout << j << ' ';
			cout << '\n';
	}

	return 0;
}