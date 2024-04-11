#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T>
	using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first != b.first) return a.first > b.first;
	return a.second < b.second;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	vector<pair<int, int>> a(n);
	vector<int> b;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		b.push_back(a[i].first);
		a[i].second = i;
	}
	sort(a.begin(), a.end(), cmp);

	int m; cin >> m;
	vector<int> ans(m);
	vector<tuple<int, int, int>> que;
	for (int i = 0; i < m; i++) {
		int k, pos; cin >> k >> pos;
		que.emplace_back(k, pos, i);
	}
	sort(que.begin(), que.end());

	indexed_set<int> st;
	int petr = 0;
	for (auto [k, pos, i]: que) {
		while (petr < k) {
			st.insert(a[petr].second);
			petr++;
		} 

		// find the pos-th element
		int p = *st.find_by_order(pos-1);
		ans[i] = b[p];
	}

	for (int i: ans) cout << i << '\n';

	return 0;
}