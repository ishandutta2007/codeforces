#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	map<int, int> cntt;
	for (int &i: a) {
		cin >> i;
		cntt[i]++;
	}
	for (auto [u, v]: cntt) {
		if (v > (n+1)/2) {
			cout << "-1\n"; return;
		}
	}

	// if anything appears more than twice, impossible
	// split into segments
	// cost is at least that much
	// 1 x | x | x 1 | 1 x 1 x 1
	// 1xyz1 | 1x1x1 
	// need one more splitting
	// how to tell how much extra splitting needed?
	// 1 x
	// x x
	// x 1
	// 1 1
	int ans = 0;

	vector<pair<int, int>> ep;
	int prv = 0;
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i-1]) {
			ans++;
			ep.emplace_back(a[prv], a[i-1]);

			prv = i;
		}
	}
	if (prv == 0) {
		cout << ans << '\n';
		return;
	}
	ep.emplace_back(a[prv], a[n-1]);

	// if two endpoints are different, get a free link
	vector<int> points;
	vector<pair<int, int>> fr;
	for (auto [vl, vr]: ep) {
		if (vl == vr) {
			points.push_back(vl);
			//cout << "Point: " << vl << '\n';
		} else {
			fr.emplace_back(vl, vr);
			//cout << "Link: " << vl << ' ' << vr << '\n';
		}
	}
	// if there are no points, endgame
	if (points.empty()) {
		cout << ans << '\n'; return;
	}

	// after matching the "points", we end up with some parts completely the same to each other
	map<int, int> mp;
	for (int i: points) mp[i]++;

	vector<pair<int, int>> vr;
	int sum = 0;
	for (auto [u, v]: mp) {
		vr.emplace_back(v, u);
		sum += v;
	}
	sort(vr.begin(), vr.end(), greater<pair<int, int>>());
	int cnt = 1;
	if (vr[0].first <= (sum+1)/2) {
		cout << ans << '\n'; return;
	} else {
		int non_fi = sum - vr[0].first;
		cnt = vr[0].first - non_fi;
	}

	if (cnt <= 1) {
		cout << ans << '\n'; return;
	}
	int lst = vr[0].second;

	// there are "cnt" points with the exact same thing
	// match with fr

	// how to match?
	// place one at first
	// if one endpoint == lst, save nothing
	// if two endpoints != lst, save one link
	// ans += cnt

	cnt--;
	for (auto [u, v]: fr) {
		if (u == lst || v == lst) {
			continue;
		} else {
			cnt--;
		}
	}
	ans += max(0, cnt);

	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}