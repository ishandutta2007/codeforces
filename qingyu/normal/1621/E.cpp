#include <bits/stdc++.h>

const int N = 5e5 + 50;
const int V = 1e5 + 50;
const int mod = 998244353;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); } 
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

long long max[N << 2], tag[N << 2];

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

void maintain(int o, int v) {
	tag[o] += v;
	max[o] += v;
}

void push_down(int o, int l, int r) {
	if (tag[o]) {
		maintain(lc(o), tag[o]);
		maintain(rc(o), tag[o]);
		tag[o] = 0;
	}
}

void push_up(int o) {
	max[o] = std::max(max[lc(o)], max[rc(o)]);
}

void add(int o, int l, int r, int ql, int qr, int v) {
	if (ql <= l && r <= qr) {
		maintain(o, v);
	}
	else {
		const int mid = l + r >> 1;
		push_down(o, l, r);
		if (ql <= mid)
			add(lc(o), l, mid, ql, qr, v);
		if (qr > mid)
			add(rc(o), mid + 1, r, ql, qr, v);
		push_up(o);
	}
}

int query(int o, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return max[o];
	}
	const int mid = l + r >> 1;
	push_down(o, l, r);
	int ans = 0xcfcfcfcf;
	if (ql <= mid) ans = std::max(ans, query(lc(o), l, mid, ql, qr));
	if (qr > mid) ans = std::max(ans, query(rc(o), mid + 1, r, ql, qr));
	push_up(o);
	return ans;
}

int query(int l, int r) {
	int x = query(1, 1, V, l, r);
	return x;
}
void add(int ql, int qr, int v) {
	add(1, 1, V, ql, qr, v);
}


long long n, m, a[N], sum[N];
std::vector<long long> b[N];

void solve() {
	std::cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		add(1, a[i], -1);
	}
	for (int i = 1; i <= m; ++i) {
		int k;
		std::cin >> k;
		sum[i] = 0;
		for (int j = 0; j < k; ++j) {
			long long x;
			std::cin >> x;
			b[i].push_back(x);
			sum[i] += x;
		}
	}
	for (int i = 1; i <= m; ++i) {
		add(1, (sum[i] + b[i].size() - 1) / b[i].size(), 1);
	}
	for (int i = 1; i <= m; ++i) {	
		add(1, (sum[i] + b[i].size() - 1) / b[i].size(), -1);
		assert(b[i].size() >= 2);
		for (int j = 0; j < b[i].size(); ++j) {
			long long v = ((sum[i] - b[i][j] + b[i].size() - 2) / (b[i].size() - 1));
			add(1, v, 1);
			int qr = query(1, V);

			if (qr > 0) {
				putchar('0');
			}
			else {
				putchar('1');
			}
			add(1, v, -1);
		}
		add(1, (sum[i] + b[i].size() - 1) / b[i].size(), 1);
	}
	for (int i = 1; i <= m; ++i) {
		add(1, (sum[i] + b[i].size() - 1) / b[i].size(), -1);
		sum[i] = 0;
		b[i].clear();
	}
	for (int i = 1; i <= n; ++i) {
		add(1, a[i], 1);
	}
	putchar('\n');
}

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int t;
	std::cin >> t;
	while (t--) {
		solve();
	}
}