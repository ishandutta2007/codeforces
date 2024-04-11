#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	stack<pair<int, int> > st;
	int a[n]; for (int o = 0; o < n; o++) { cin >> a[o]; }
	for (int i = 0; i < m; ++i) {
		int t; cin >> t;
		int r; cin >> r;
		if (!st.empty()) {
			while ((!st.empty()) && st.top().first <= r) {
				st.pop();
			}
		}
		st.push({r, t});
	}
	std::vector<pair<int, int>> v;
	while (!st.empty()) {
		v.pb(st.top());
		st.pop();
	}
	reverse(v.begin(), v.end());
	if (v.empty()) {
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";
		exit(0);
	}
	multiset<int> mu;
	for (int i = 0; i < v[0].first; ++i) mu.insert(a[i]);
	int in = v[0].first - 1;
	int prev = v[0].second;
	for (int i = 1; i < v.size(); ++i) {
		int en = v[i].first;
		while (in >= en) {
			if (prev == 2) {
				a[in] = *(mu.begin());
				mu.erase(mu.begin());
			} else {
				a[in] = *(mu.rbegin());
				mu.erase(mu.find(a[in]));
			}
			in--;
		}
		prev = v[i].second;
	}
	int en = 0;
	while (in >= en) {
		if (prev == 2) {
			a[in] = *(mu.begin());
			mu.erase(mu.begin());
		} else {
			a[in] = *(mu.rbegin());
			mu.erase(mu.find(a[in]));
		}
		in--;
	}
	for (int i = 0; i < n; ++i) cout << a[i] << " ";
}