#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

void solve() {
	int n;
	cin >> n;
	vector<ar<int, 3>> v;
	for (int i=0; i<n; ++i) {
		int c, l, r;
		cin >> c >> l >> r;
		v.push_back({l, r, c});
	}
	sort(v.begin(), v.end());
	int ans=n;
	multiset<int> s[2];
	for (auto [l, r, c] : v) {
		for (int i : {0, 1})
			while(s[i].size()&&*s[i].begin()<l)
				s[i].erase(s[i].begin());
		s[c].insert(r);
		if (s[c^1].size()) {
			--ans;
			while(s[c^1].size()>1) {
				s[c^1].erase(s[c^1].begin());
				--ans;
			}
			assert(s[c].size()<=2);
			if (s[c].size()==2)
				s[c].erase(s[c].begin());
		}
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}