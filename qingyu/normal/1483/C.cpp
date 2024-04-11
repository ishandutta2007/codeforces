#include <bits/stdc++.h>

const int N = 3e5 + 50;

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

int n, h[N], b[N], pre[N], t[N];
long long dp[N], max[N << 2];

inline int lowbit(int x) { return x & -x; }

inline void add(int p, int v) {
	for (; p <= n; p += lowbit(p))
		t[p] = std::max(t[p], v);
}

inline int qry(int p) {
	int ans = 0;
	for (; p; p -= lowbit(p))
		ans = std::max(ans, t[p]);
	return ans;
}

inline void push_up(int o) {
	max[o] = std::max(max[lc(o)], max[rc(o)]);
}

long long query(int o, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) return max[o];
	long long ans = -1e18;
	const int mid = l + r >> 1;
	if (ql <= mid) ans = std::max(ans, query(lc(o), l, mid, ql, qr));
	if (qr > mid) ans = std::max(ans, query(rc(o), mid + 1, r, ql, qr));
	return ans;
}

void modify(int o, int l, int r, int p, long long v) {
	if (l == r) max[o] = v;
	else {
		const int mid = l + r >> 1;
		if (p <= mid) modify(lc(o), l, mid, p, v);
		else modify(rc(o), mid + 1, r, p, v);
		push_up(o);
	}
}

long long query(int l, int r) {
	return query(1, 0, n, l, r);
}

int main() {
	memset(max, 0xcf, sizeof max);
	memset(dp, 0, sizeof dp);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n;
	std::deque<std::pair<int, long long>> que;
	for (int i = 1; i <= n; ++i) {
		std::cin >> h[i];
		pre[i] = qry(h[i]);
		add(h[i], i);
	}
	for (int i = 1; i <= n; ++i) std::cin >> b[i];
	dp[0] = 0;
	auto ins = [&](int x, long long y) {
		if (que.empty() || que.back().second < y) {
			que.emplace_back(x, y);
		}
	};
	modify(1, 0, n, 0, dp[0]);
	for (int i = 1; i <= n; ++i) {
		int t = pre[i];
		while (!que.empty() && que.back().first > t) que.pop_back();
		long long w = query(t, i - 1) + b[i];
		ins(t + 1, w);
		assert(!que.empty());
		dp[i] = que.back().second;
		modify(1, 0, n, i, dp[i]);
	}
	std::cout << dp[n] << '\n';
	return 0;
}