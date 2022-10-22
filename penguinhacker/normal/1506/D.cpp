#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	map<int, int> mp;
	multiset<int> s;
	int n; cin >> n;
	while(n--) {
		int x; cin >> x;
		++mp[x];
	}
	vector<int> v;
	for (auto& x : mp)
		s.insert(x.second);
	while(s.size() >= 2) {
		int x = *s.rbegin(); s.erase(--s.end());
		int y = *s.rbegin(); s.erase(--s.end());
		if (x > 1)
			s.insert(x - 1);
		if (y > 1)
			s.insert(y - 1);
	}
	cout << (s.empty() ? 0 : *s.begin()) << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}