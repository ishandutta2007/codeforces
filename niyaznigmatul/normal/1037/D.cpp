#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > edges(n);
	vector<int> r(n), order(n), was(n), q(n);
	for (int i = 0; i + 1 < n; i++) {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			edges[x].push_back(y);
			edges[y].push_back(x);
	}
	for (int i = 0; i < n; i++) {
		cin >> order[i];
		--order[i];
		r[order[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		sort(edges[i].begin(), edges[i].end(), [&](int x, int y) {
			return r[x] < r[y];
		});
	}
	int head = 0;
	int tail = 0;
	if (order[0] != 0) {
		cout << "No\n";
		return 0;
	}
	q[tail++] = order[0];
	was[order[0]] = true;
	while (head < tail) {
		int v = q[head++];
		for (int to : edges[v]) {
			if (!was[to]) {
				was[to] = true;
				q[tail++] = to;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (q[i] != order[i]) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}