#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1 << 20;
ll n, a[N], sum[N];

struct node_t {
	ll pre, suf, ans;
	node_t() : pre(0), suf(0), ans(0) {}
	node_t(ll pre, ll suf, ll ans) : pre(pre), suf(suf), ans(ans) {}
};
ll sa(int l, int r) { return sum[r] - (l ? sum[l - 1] : 0); }
node_t merge(const node_t &l, const node_t &r, ll ls, ll rs) {
	return node_t(max(l.pre, ls + r.pre), max(r.suf, rs + l.suf), max(max(l.ans, r.ans), l.suf + r.pre));
}
vector<node_t> solve(int l, int r, int s) {
	if (l == r) {
		ll v = max(0ll, a[l]);
		return { node_t(v, v, v) };
	}
	int mid = l + r >> 1, t = 1 << s - 1;
	auto left = solve(l, mid, s - 1), right = solve(mid + 1, r, s - 1);
	ll l_sum = sa(l, mid), r_sum = sa(mid + 1, r);
	vector<node_t> ret(1 << s);
	for (int i = 0; i < t; ++i) {
		ret[i] = merge(left[i], right[i], l_sum, r_sum);
		ret[i + t] = merge(right[i], left[i], r_sum, l_sum);
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	int len = 1 << n;
	for (int i = 0; i < len; ++i) {
		cin >> a[i];
		sum[i] = a[i] + (i ? sum[i - 1] : 0);
	}	
	auto vec = solve(0, len - 1, n);
	int s = 0, q, k;
	cin >> q;
	while (q--) {
		cin >> k;
		s ^= 1 << k;
		cout << vec[s].ans << '\n';
	}
}