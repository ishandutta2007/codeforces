#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, p, a[100005];
set<pair<int, int> > s;
multiset<int> m;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> a[i], a[i] += a[i - 1];
	s.emplace(N, 1);
	m.insert(a[N]);
	for (int i = 0; i < N; i++) {
		cin >> p;
		auto it = s.lower_bound(make_pair(p, -1));
		if (it == s.end() || it->second > p) continue;
		m.erase(m.find(a[it->first] - a[it->second - 1]));
		if (it->first > p) {
			//cout << "ADD RANGE " << p + 1 << ' ' << it->first << ' ' << a[it->first] - a[p] << '\n';
			s.emplace(it->first, p + 1);
			m.insert(a[it->first] - a[p]);
		}
		if (p > it->second) {
			s.emplace(p - 1, it->second);
			//cout << "ADD RANGE " << it->second << ' ' << p - 1 << ' ' << a[p - 1] - a[it->second - 1] << '\n';
			m.insert(a[p - 1] - a[it->second - 1]);
		}
		s.erase(it);
		cout << (!m.empty() ? *m.rbegin() : 0) << '\n';
		//for (auto j : s)
		//	cout << j.second << ' ' << j.first << '\n';
		//for (auto j : m) cout << j << '\n';
		//cout << "-----\n";
	}
}