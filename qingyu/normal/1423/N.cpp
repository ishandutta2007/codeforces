#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, m, w[N], c[N], s[N];
bool vis[N];
std::vector<std::pair<int, int> > G[N];

template<int T>
struct fast_io
{
	char p[T], q[T], *p1, *p2, *q1, *q2;

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

fast_io<1 << 20> io;

inline int64_t read()
{
	int64_t res = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

inline void put(int64_t x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int64_t x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}


int main()
{
	n = read(), m = read();
	for (int i = 1; i <= m; ++i)
	{
		int u = read(), v = read();
		if (u < v) std::swap(u, v);
		G[u].emplace_back(v, i);
		w[i] = 1;
		++s[u], ++s[v];
	}
	for (int x = 1; x <= n; ++x)
	{
		for (auto &[y, i] : G[x])
		{
			if (!c[y])
			{
				++c[y];
				--w[i];
				--s[x];
			}
			vis[s[y]] = true;
		}
		int &cur = s[x];
		for (auto &[y, i] : G[x])
		{
			if (!vis[cur]) break;
			--c[y];
			++w[i];
			++cur;
		}
		for (auto &[y, i] : G[x]) vis[s[y]] = false;
	}
	std::vector<int> res;
	for (int i = 1; i <= n; ++i) if (c[i]) res.push_back(i);
	printf("%d\n", res.size());
	for (int x : res) printf("%d ", x);
	putchar('\n');
	for (int x = 1; x <= n; ++x)
		for (auto &[y, i] : G[x])
			printf("%d %d %d\n", x, y, w[i]);
	return 0;
}