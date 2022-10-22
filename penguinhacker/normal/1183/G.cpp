#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000], f[200000];
pair<int, int> cnt[200000];

void solve() {
	cin >> n;
	fill(cnt, cnt + n, pair<int, int>(0, 0));
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> f[i], --a[i];
		++cnt[a[i]].first;
		cnt[a[i]].second += f[i];
	}
	sort(cnt, cnt + n, greater<>());
	int cur = 69696969;
	int ans1 = 0, ans2 = 0;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cur = min(cur, cnt[i].first);
		if (cur == 0) break;
		ans1 += cur;
		v.push_back(cur--);
	}
	multiset<int> cand;
	cur = 0;
	for (int i : v) {
		while(cur < n && cnt[cur].first >= i) cand.insert(cnt[cur++].second);
		ans2 += min(i, *cand.rbegin());
		cand.erase(--cand.end());
	}
	cout << ans1 << " " << ans2 << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}