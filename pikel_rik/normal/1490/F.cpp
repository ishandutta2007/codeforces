#include <bits/stdc++.h>
using namespace std;

int compress(vector<int> &a) {
	vector<int> temp = a;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (auto &x : a) x = lower_bound(temp.begin(), temp.end(), x) - temp.begin();
	return int(temp.size());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);
		for (auto &x : a) cin >> x;

		int sz = compress(a);

		vector<int> cnt(sz);
		for (auto &x : a) cnt[x] += 1;

		sort(cnt.begin(), cnt.end());

		vector<int> pref = cnt;
		partial_sum(pref.begin(), pref.end(), pref.begin());

		int below = 0, ans = n;
		for (int i = 0; i < sz; i++) {
			if (i == 0 || cnt[i] != cnt[i - 1]) {
				ans = min(ans, below + pref[sz - 1] - pref[i] - (sz - i - 1) * cnt[i]);
			}	
			below += cnt[i];
		}
		cout << ans << '\n';
	}
	return 0;
}