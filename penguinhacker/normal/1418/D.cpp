#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	set<int> pos;
	multiset<int> gap;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		pos.insert(x);
	}
	for (auto it = next(pos.begin()); it != pos.end(); ++it) {
		gap.insert(*it - *prev(it));
	}
	auto cmp = [&]() {
		if (pos.size() <= 2) {
			cout << "0\n";
			return;
		}
		int ans = *pos.rbegin() - *pos.begin();
		ans -= *gap.rbegin();
		cout << ans << "\n";
	};
	cmp();
	for (int i = 0; i < q; ++i) {
		int t, x;
		cin >> t >> x;
		if (t == 0) {
			auto it = pos.find(x);
			assert(it != pos.end());
			if (pos.size() >= 2) {
				if (it == pos.begin()) {
					gap.erase(gap.find(*next(it) - *it));
				}
				else if (next(it) == pos.end()) {
					gap.erase(gap.find(*it - *prev(it)));
				}
				else {
					gap.erase(gap.find(*next(it) - *it));
					gap.erase(gap.find(*it - *prev(it)));
					gap.insert(*next(it) - *prev(it));
				}
			}
			pos.erase(it);
		}
		else {
			pos.insert(x);
			auto it = pos.find(x);
			if (pos.size() >= 2) {
				if (it == pos.begin()) {
					gap.insert(*next(it) - *it);
				}
				else if (next(it) == pos.end()) {
					gap.insert(*it - *prev(it));
				}
				else {
					gap.insert(*next(it) - *it);
					gap.insert(*it - *prev(it));
					gap.erase(gap.find(*next(it) - *prev(it)));
				}
			}
		}
		cmp();
	}
	return 0;
}