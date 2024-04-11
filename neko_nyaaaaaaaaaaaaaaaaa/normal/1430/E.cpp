#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<class T>
	using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	string s; cin >> s; s = " " + s;
	vector<vector<int>> p(26);
	for (int i = n; i; i--) {
		int d = s[i] - 'a';
		p[d].push_back(i);
	}

	vector<int> gs;
	for (int i = 1, j = n; i <= n; i++, j--) {
		int d = s[j] - 'a';
		int pos = p[d].back(); p[d].pop_back();
		gs.push_back(pos);
	}
	
	long long ans = 1LL*n*(n-1)/2;
	indexed_set<int> st;
	for (int i: gs) {
		ans -= st.order_of_key(i);
		st.insert(i);
	}
	cout << ans << '\n';

	return 0;
}