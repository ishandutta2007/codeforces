#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<int> mn, mx;
	int a = 0, na = 0;
	for (int i = 0; i < n; i++) {
		int k; cin >> k;

		int min_so_far = 1000006;
		int max_so_far = 0;
		int ascent = 0;
		while (k--) {
			int x; cin >> x;

			if (x > min_so_far) {
				ascent = 1;
			}
			min_so_far = min(min_so_far, x);
			max_so_far = max(max_so_far, x);
		}

		if (ascent) {
			a++;
		} else {
			na++;
			mn.push_back(min_so_far);
			mx.push_back(max_so_far);
		}
	}
	sort(mn.begin(), mn.end());

	long long ans = 1LL*a*a;
	for (int i: mx) {
		ans += (lower_bound(mn.begin(), mn.end(), i) - mn.begin());
		
		ans += 2*a;
	}
	cout << ans << '\n';


	return 0;
}