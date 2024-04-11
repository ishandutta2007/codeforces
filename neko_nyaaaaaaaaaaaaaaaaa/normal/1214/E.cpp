#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<pair<int, int>> d(n);
	for (int i = 0; i < n; i++) {
		cin >> d[i].first;
		d[i].second = i+1;
	}
	sort(d.begin(), d.end(), greater<pair<int, int>>());

	vector<int> chain;
	for (int i = 0; i < n; i++) {
		chain.push_back(d[i].second);
	}

	vector<int> connection(2*n + 1, -1);
	for (int i = 0; i < n; i++) {
		int id_node = d[i].second + n;
		int pos = i + d[i].first - 1;
		if (pos == chain.size() - 1) {
			chain.push_back(id_node);
		} else {
			connection[id_node] = pos;
		}
	}

	vector<int> mapper(2*n+1);
	for (int i = 1, j = 1; j <= n; j++, i += 2) {
		mapper[j] = i;
		mapper[j+n] = i+1;
	}

	for (int i = 1; i < chain.size(); i++) {
		cout << mapper[chain[i]] << ' ' << mapper[chain[i-1]] << '\n';
	}
	for (int i = 1; i <= 2*n; i++) {
		if (connection[i] >= 0) {
			cout << mapper[i] << ' ' << mapper[chain[connection[i]]] << '\n';
		}
	}

	return 0;
}