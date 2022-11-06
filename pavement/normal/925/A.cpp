#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int> st, el;

main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, cl, ce, v, p, q, x1, y1, x2, y2;
	cin >> n >> m >> cl >> ce >> v;
	for (int i = 0; i < cl; i++)
		cin >> p, st.push_back(p);
	for (int i = 0; i < ce; i++)
		cin >> p, el.push_back(p);
	sort(st.begin(), st.end());
	sort(el.begin(), el.end());
	cin >> q;
	while (q--) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2) {
			cout << abs(y1 - y2) << '\n';
			continue;
		}
		if (x1 > x2) swap(x1, x2), swap(y1, y2);
		int ans = 1e18;
		auto it1 = lower_bound(el.begin(), el.end(), y1), it2 = lower_bound(st.begin(), st.end(), y1);
		if (it1 != el.end()) ans = min(ans, abs(*it1 - y1) + abs(y2 - *it1) + ((x2 - x1) / v + ((x2 - x1) % v != 0)));
		if (it2 != st.end()) ans = min(ans, abs(*it2 - y1) + abs(y2 - *it2) + (x2 - x1));
		if (it1 != el.begin()) --it1, ans = min(ans, abs(y1 - *it1) + abs(*it1 - y2) + ((x2 - x1) / v + ((x2 - x1) % v != 0)));
		if (it2 != st.begin()) --it2, ans = min(ans, abs(y1 - *it2) + abs(*it2 - y2) + (x2 - x1));
		cout << ans << '\n';
	}
}