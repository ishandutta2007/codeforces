#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	constexpr int N = 2500000;

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	map<int, pair<int, int>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			auto &p = mp[a[i] + a[j]];
			if (p.first == 0 && p.second == 0) {
				p = make_pair(i, j);
			}
			auto [ii, jj] = p;
			if (ii != i && ii != j && jj != i && jj != j) {
				cout << "YES\n";
				cout << ii + 1 << ' ' << jj + 1 << ' ' << i + 1 << ' ' << j + 1 << '\n';
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}