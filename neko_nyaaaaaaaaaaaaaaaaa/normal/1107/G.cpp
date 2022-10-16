/*
    Indentation sucks

    CBFEAST or GSS1 or cses 1190 (array updates)?
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
typedef tuple<int, int, int, int, int, int> dat;

int n, ans;

dat combine(dat a, dat b) {
	auto [l1, r1, sum1, pre1, suf1, ans1] = a;
	auto [l2, r2, sum2, pre2, suf2, ans2] = b;

	int sum = sum1 + sum2;
	int pre = max(pre1, sum1 + pre2);
	int suf = max(suf2, sum2 + suf1);
	int res = max(max(ans1, ans2), suf1 + pre2);

	return make_tuple(l1, r2, sum, pre, suf, res);
}

void solve(set<dat> &st, int d, int l, int r) {
	auto i2 = st.lower_bound(make_tuple(r, 0, 0, 0, 0, 0));
	auto i1 = i2; i1--;

	dat k = combine(*i1, *i2);
	st.erase(i1);
	st.erase(i2);
	st.insert(k);

	ans = max(ans, get<5>(k) - d*d);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int m; cin >> n >> m;
	vector<int> d(300001);
	vector<int> a(300001);
	for (int i = 1; i <= n; i++) {
		cin >> d[i] >> a[i];
		a[i] = m - a[i];
		ans = max(ans, a[i]);
	}

	set<dat> st;
	for (int i = 1; i <= n; i++) {
		st.insert(make_tuple(i, i, a[i], max(0LL, a[i]), max(0LL, a[i]), max(0LL, a[i])));
	}

	vector<tuple<int, int, int>> df;
	for (int i = 2; i <= n; i++) {
		df.emplace_back(d[i] - d[i-1], i-1, i);
	}
	sort(df.begin(), df.end());

	for (auto [diff, l, r]: df) {
		solve(st, diff, l, r);
	}

	cout << ans;

	return 0;
}