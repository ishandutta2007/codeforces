#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const double pi = acos(-1.0);
const int inf = INT_MAX;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int N = 200000;

	int n, k;
	cin >> n >> k;

	vector<int> l(n), r(n);
	vector<vector<int>> add(N), rem(N);

	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		add[--l[i]].push_back(i);
		rem[--r[i]].push_back(i);
	}

	vector<bool> removed(n);
	set<pair<int, int>, greater<>> active;

	for (int x = 0; x < N; x++) {
		for (int i : add[x]) {
			active.emplace(r[i], i);
		}

		while (active.size() > k) {
			int i = active.begin()->second;
			active.erase(active.begin());
			removed[i] = true;
		}

		for (int i : rem[x]) {
			if (!removed[i]) {
				active.erase(make_pair(r[i], i));
			}
		}
	}

	cout << count(removed.begin(), removed.end(), true) << '\n';
	for (int i = 0; i < n; i++) {
		if (removed[i]) {
			cout << i + 1 << ' ';
		}
	}
	cout << '\n';
	return 0;
}