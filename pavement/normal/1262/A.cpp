#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
		sort(a, a + n);
		set<int> s;
		int l = a[0].second, r = a[n - 1].first;
		for (auto i : a) {
			if (s.upper_bound(i.second) != s.end()) {
				l = min(l, i.second);
				r = max(r, i.first);
			}
			s.insert(i.second);
		}
		cout << max(0, r - l) << '\n';
	}
}