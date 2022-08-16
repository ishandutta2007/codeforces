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

	int n;
	cin >> n;

	vector<pair<char, int>> a(2 * n);
	vector<int> ans(2 * n), pos(n + 1);
	set<int> free;

	for (int i = 0; i < 2 * n; i++) {
		cin >> a[i].first;
		if (a[i].first == '-') {
			cin >> a[i].second;
			pos[a[i].second] = i;
		} else {
			free.insert(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		auto it = free.lower_bound(pos[i]);
		if (it != free.begin()) {
			--it;
			ans[*it] = i;
			free.erase(it);
		} else {
			cout << "NO\n";
			return 0;
		}
	}

	set<int> cur;
	for (int i = 0; i < 2 * n; i++) {
		if (a[i].first == '-') {
			if (cur.empty() or *cur.begin() != a[i].second) {
				cout << "NO\n";
				return 0;
			}
			cur.erase(cur.begin());
		} else {
			cur.insert(ans[i]);
		}
	}

	cout << "YES\n";
	for (int i = 0; i < 2 * n; i++) {
		if (ans[i]) {
			cout << ans[i] << ' ';
		}
	}
	return 0;
}