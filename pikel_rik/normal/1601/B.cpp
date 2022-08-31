#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> a(n + 1), b(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	vector<int> lvl(n + 1, -1);
	vector<pair<int, int>> p(n + 1, make_pair(-1, -1));

	queue<int> q;
	q.push(n), lvl[n] = 0;

	int l = n;
	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (lvl[x + b[x]] == -1) {
			lvl[x + b[x]] = 1 + lvl[x];
			p[x + b[x]] = make_pair(x, x);
			q.push(x + b[x]);
		}

		if (x - a[x] < l) {
			for (int i = l - 1; i >= x - a[x]; i--) {
				if (lvl[i + b[i]] == -1) {
					lvl[i + b[i]] = 1 + lvl[x];
					p[i + b[i]] = make_pair(x, i);
					q.push(i + b[i]);
				}
			}
			l = x - a[x];
		}
	}

	if (lvl[0] == -1) {
		cout << "-1\n";
		return 0;
	}

	vector<int> path;
	for (int i = 0; i != n;) {
		path.push_back(i - b[p[i].second]);
		i = p[i].first;
	}

	cout << (int) path.size() << '\n';
	reverse(path.begin(), path.end());
	for (auto d : path) {
		cout << d << ' ';
	}
	cout << '\n';
	return 0;
}