#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int> c;
	set<int> s1;
	set<pair<int, int>> s2;
	for (int i = 0; i < n; ++i) {
		int t; cin >> t;
		if (t == 1) {
			int m; cin >> m;
			s1.insert(c.size());
			s2.emplace(-m, c.size());
			c.push_back(m);
		}
		else if (t == 2 || t == 3) {
			assert(!s1.empty() && !s2.empty());
			int ind = t == 2 ? *s1.begin() : s2.begin()->second;
			s1.erase(ind);
			s2.erase({-c[ind], ind});
			cout << ind + 1 << " ";
		}
		else assert(0);
	}
	return 0;
}