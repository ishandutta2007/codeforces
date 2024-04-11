#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, q, t[N], a[N], min[N << 2], tag[N << 2], ans[N];

struct qu_t {
	int l, r, id;
	qu_t (int l, int r, int id) : l(l), r(r), id(id) {
		
	}
	inline bool operator<(const qu_t &rhs) const {
		return r < rhs.r;
	};
};
std::vector<qu_t> queries;

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

void maintain(int o, int v) {
	tag[o] += v;
	min[o] += v;	
}

void push_up(int o) {
	min[o] = std::min(min[lc(o)], min[rc(o)]);
}

void push_down(int o) {
	if (tag[o]) {
		maintain(lc(o), tag[o]);
		maintain(rc(o), tag[o]);
		tag[o] = 0;
	}
}

void build(int o, int l, int r) {
	if (l == r) maintain(o, 1 - l);
	else {
		const int mid = l + r >> 1;
		build(lc(o), l, mid);
		build(rc(o), mid + 1, r);
		push_up(o);
	}
}

void add(int o, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		maintain(o, v);
	}
	else {
		const int mid = l + r >> 1;
		push_down(o);
		if (ql <= mid) add(lc(o), l, mid, ql, qr, v);
		if (qr > mid) add(rc(o), mid + 1, r, ql, qr, v);
		push_up(o);
	}
}

int query(int o, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return min[o];
	}
	push_down(o);
	const int mid = l + r >> 1;
	int min = 1e9;
	if (ql <= mid) min = std::min(min, query(lc(o), l, mid, ql, qr));
	if (qr > mid) min = std::min(min, query(rc(o), mid + 1, r, ql, qr));
	return min;
}

int query(int l, int r) {
	int v = query(1, 1, n, l, r);
	return v;	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] = i - a[i];
	}
	for (int i = 1; i <= q; ++i) {
		int l, r;
		std::cin >> l >> r;
		queries.emplace_back(l + 1, n - r, i);
	}
	std::sort(queries.begin(), queries.end());
	int r = 0;
	auto lower_bound = [&](int l, int r, int v) {
		int ans = 0;
		while (l <= r) {
			const int mid = l + r >> 1;
			if (query(1, mid) >= v) ans = mid, l = mid + 1;
			else r = mid - 1;	
		}
		return ans;
	};
	int p = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= 0) {
			int p = lower_bound(1, i, a[i]);
			if (p) add(1, 1, n, 1, p, 1);
		}
		while (p < queries.size() && queries[p].r == i) {
			int l = queries[p].l, r = queries[p].r, id = queries[p].id;
			ans[id] = query(l, l);
			++p;
		}
	}
	for (int i = 1; i <= q; ++i) std::cout << ans[i] << '\n';
	return 0;
}