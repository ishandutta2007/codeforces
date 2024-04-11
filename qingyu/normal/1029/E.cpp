#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n;
std::vector<int> G[N];
std::priority_queue<std::pair<int, int>> q;
typedef long long ll;

template <int T>
struct fast_io
{
	char p[T], q[T], * p1, * p2, * q1, * q2;
	fast_io()
	{
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}
	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}
	inline void pc(char c)
	{
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}
	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};
fast_io<1 << 18> io;
inline ll read()
{
	ll res = 0;
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res;
}
inline void read(char *s)
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	do *s++ = ch, ch = io.gc(); while (isalpha(ch));
	*s = 0;
}
inline int rb()
{
	char ch;
	do ch = io.gc(); while (ch < 48 || ch > 57);
	return ch - 48;
}
inline void put(ll x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}
inline void output(ll x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}
int main()
{
	n = read();
	for (int i = 1; i < n; ++i)
	{
		int x = read(), y = read();
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	std::vector<int> dep(n + 1, 0), vis(n + 1, 0), fa(n + 1, 0);
	std::function<void(int, int)> dfs = [&](int x, int f)
	{
		dep[x] = dep[f] + 1; fa[x] = f;
		for (int y : G[x])
			if (y != f)
				dfs(y, x);
	};
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) if (dep[i] > 3) q.emplace(std::make_pair(dep[i], i));	
	int ans = 0;
	while (!q.empty())
	{
		auto [_, x] = q.top(); q.pop();
		if (!vis[x])
		{
			++ans;
			x = fa[x];
			vis[x] = true;
			for (int y : G[x])
				vis[y] = true;
		}
	}
	output(ans);
	return 0;
}