#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[10000];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int sum = accumulate(a, a + n, 0);
	if (sum % n > 0) {
		cout << "-1\n";
		return;
	}
	int avg = sum / n;
	vector<ar<int, 3>> ans;
	auto stuff = [&](int i, int j, int k) {
		ans.push_back({i, j, k});
		a[i] -= k * (i + 1);
		a[j] += k * (i + 1);
		assert(a[i] >= 0 && a[j] >= 0);
	};
	set<pair<int, int>> todo;
	for (int i = 1; i < n; ++i) {
		int need = ((i + 1) - a[i] % (i + 1)) % (i + 1);
		if (need != 0 && a[0] > need) {
			stuff(0, i, need);
		}
		if (a[i] % (i + 1) == 0) {
			stuff(i, 0, a[i] / (i + 1));
		}
		else {
			todo.insert({i + 1 - a[i], i});
		}
	}
	while(!todo.empty()) {
		auto it = todo.lower_bound({0, -1});
		if (it == todo.end() || a[0] < it->first) {
			it = todo.begin();
			if (a[0] < it->first) {
				break;
			}
			int ind = it->second;
			stuff(ind, 0, a[ind] / (ind + 1));
			todo.erase(it);
			assert(a[ind] < (ind + 1) && a[ind] != 0);
			todo.insert({ind + 1 - a[ind], ind});
		}
		else {
			int need = it->first;
			int ind = it->second;
			todo.erase(it);
			if (a[0] < need) {
				break;
			}
			else {
				stuff(0, ind, need);
				stuff(ind, 0, 1);
			}
		}
	}
	for (int i = 1; i < n; ++i) {
		if (a[i] > avg || a[0] < avg - a[i]) {
			cout << "-1\n";
			return;
		}
		if (a[i] != avg)
		stuff(0, i, avg - a[i]);
	}
	if (ans.size() > 3 * n) {
		cout << "-1\n";
		return;
	}
	cout << ans.size() << "\n";
	for (ar<int, 3> x : ans) {
		cout << x[0] + 1 << " " << x[1] + 1 << " " << x[2] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}