#include <bits/stdc++.h>

using std::cin;
using std::cout;
using std::abs;

const int N = 2e5 + 50;
const int M = 1e7 + 50;
const int mod = 1e9 + 7;

int n, q, a[N], pri[N], tot, rtot, rt[N], lc[M], rc[M], min[M], tag[M];
int powers[N];
int ans = 1;
std::vector<int> v[N];
bool np[N];

void init(int n)
{
	np[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		if (!np[i])
		{
			pri[++tot] = i;
		}
		for (int j = 1; j <= tot && i *pri[j] <= n; ++j)
		{
			np[i * pri[j]] = true;
			if (i % pri[j] == 0) break;
		}
	}
	for (int i = 1; i <= tot; ++i)
		for (int j = pri[i]; j <= n; j += pri[i])
			v[j].push_back(pri[i]);
}

void maintain(int o, int v)
{
	tag[o] += v, min[o] += v;
}

void push_up(int o)
{
	min[o] = std::min(min[lc[o]], min[rc[o]]);
}

void push_down(int o)
{
	if (tag[o])
	{
		if (lc[o]) maintain(lc[o], tag[o]);
		if (rc[o]) maintain(rc[o], tag[o]);
		tag[o] = 0;
	}
}

void add(int &o, int l, int r, int p, int v)
{
	if (!o) o = ++rtot;
	if (l == r)
	{
		maintain(o, v);
	}
	else
	{
		push_down(o);
		const int mid = l + r >> 1;
		if (p <= mid) add(lc[o], l, mid, p, v);
		else add(rc[o], mid + 1, r, p, v);
		push_up(o);
	}
}

void multiply(int p, int x)
{
	int _x = x;
	for (int d : v[x])
	{
		int r = 0;
		while (_x % d == 0)
		{
			++r, _x /= d;
		}
		add(rt[d], 1, n, p, r);
		while (powers[d] < min[rt[d]])
		{
			ans = 1ll * ans * d % mod;
			++powers[d];
		}
	}
}

int main()
{
	init(2e5);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr); std::cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) 
	{
		cin >> a[i];
		multiply(i, a[i]);
	}
	for (int i = 1; i <= q; ++i)
	{
		int x, y;
		cin >> x  >> y;
		multiply(x, y);
		cout << ans << '\n';
	}
}