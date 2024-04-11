/**
 * Niyaz Nigmatullin
 */

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	int const N = 1234567;

	vector<int> mpos(N, -1);
	vector<int> cnt(N, 0);	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mpos[a[i]] = max(mpos[a[i]], i);
		cnt[a[i]]++;
	}
	int cur = 0;
	int ans = 0;
	while (cur < n) {
		int left = cur;
		int right = cur;
		int best = 0;
		while (cur <= right) {
			right = max(right, mpos[a[cur]]);
			best = max(best, cnt[a[cur]]);
			++cur;
		}
		ans += (cur - left) - best;
	}
	cout << ans << endl;
}