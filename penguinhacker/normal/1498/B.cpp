#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, w;
map<int, int> mp;

void solve() {
	cin >> n >> w;
	for (int i = 0; i < n; ++i) {
		int x; cin >> x;
		++mp[x];
	}
	int ans = 1, cur = w;
	while(mp.size()) {
		if (mp.begin()->first > cur) {
			++ans;
			cur = w;
		}
		auto it = prev(mp.upper_bound(cur));
		assert(it->first <= cur);
		cur -= it->first;
		if (--(it->second) == 0)
			mp.erase(it);
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--)
		solve();
	return 0;
}