#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[5000];

void solve() {
	map<int, vector<int>> mp;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]].push_back(i);
	}
	if (mp.size() == 1) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	int first = (mp.begin()->second)[0];
	for (auto it = next(mp.begin()); it != mp.end(); ++it) {
		vector<int> v = it->second;
		for (int i : v) {
			cout << first + 1 << " " << i + 1 << "\n";
		}
	}
	first = (next(mp.begin())->second)[0];
	vector<int> v = mp.begin()->second;
	v = vector<int>(v.begin() + 1, v.end());
	for (int i : v) {
		cout << first + 1 << " " << i + 1 << "\n";
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