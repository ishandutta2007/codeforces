#include <bits/stdc++.h>

const int N = 1e6 + 50;
int n, q;

long long a[N], b[N], mn[N], mx[N];

inline int lc(int o) { return o << 1; }
inline int rc(int o) { return o << 1 | 1; }

inline void push_up(int o)
{
	mn[o] = std::min(mn[lc(o)], mn[rc(o)]);
	mx[o] = std::max(mx[lc(o)], mx[rc(o)]);
}

void build(int o, int l, int r)
{
	if (l == r) mn[o] = mx[o] = a[l];
	else
	{
		const int mid = l + r >> 1;
		build(lc(o), l, mid), build(rc(o), mid + 1, r);
		push_up(o);
	}
}

long long query_max(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr) return mx[o];
	const int mid = l + r >> 1;
	long long ans = -(1ll << 60);
	if (ql <= mid) ans = std::max(ans, query_max(lc(o), l, mid, ql, qr));
	if (qr > mid) ans = std::max(ans, query_max(rc(o), mid + 1, r, ql, qr));
	return ans;
}

long long query_min(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr) return mn[o];
	const int mid = l + r >> 1;
	long long ans = 1ll << 60;
	if (ql <= mid) ans = std::min(ans, query_min(lc(o), l, mid, ql, qr));
	if (qr > mid) ans = std::min(ans, query_min(rc(o), mid + 1, r, ql, qr));
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::cin >> n >> q;
	for (int i = 1; i <= n; ++i) std::cin >> a[i];
	for (int i = 1; i <= n; ++i) std::cin >> b[i], a[i] -= b[i];
	for (int i = 1; i <= n; ++i) a[i] += a[i - 1];
	build(1, 1, n);	
	while (q--)
	{
		int l, r;
		std::cin >> l >> r;
		if (a[r] - a[l - 1] != 0) std::cout << -1 << '\n';
		else if (query_max(1, 1, n, l, r) - a[l - 1] > 0) std::cout << -1 << '\n';
		else std::cout << -(query_min(1, 1, n, l, r) - a[l - 1]) << '\n';		
		
	}
}