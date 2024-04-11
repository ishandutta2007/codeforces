#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

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

		long long add = 0;
		ordered_set<pair<long long, int>> s;

		long long ans = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) {
				while (!s.empty() && a[i] + s.begin()->first + add < 0) {
					s.erase(s.begin());
				}
				s.insert(make_pair(-add, i));
				add += a[i];
				auto ub = s.lower_bound(make_pair(-add + 1, 0));
				if (ub != s.end()) {
					ans += s.order_of_key(*ub);
				} else {
					ans += s.size();
				}
			} else {
				while (!s.empty() && -a[i] + s.rbegin()->first + add > 0) {
					s.erase(*s.rbegin());
				}
				s.insert(make_pair(-add, i));
				add -= a[i];
				auto lb = s.lower_bound(make_pair(-add, 0));
				if (lb != s.end()) {
					ans += (int) s.size() - s.order_of_key(*lb);
				}
			}
		}
		cout << ans << '\n';
	}
	return 0;
}