#include <bits/stdc++.h>

const int N = 1e5 + 50;
std::mt19937 s(0);

int n, q, a[N], pri[N], nxt[N], tot, jump[N][19];
bool np[N];
std::vector<int> pd[N], b[N];

inline void init(int n)
{
	np[1] = true;
	for (int i = 2; i <= n; ++i)
	{
		if (!np[i])
		{
			pri[++tot] = i;
		}
		for (int j = 1; j <= tot && i * pri[j] <= n; ++j)
		{
			np[i * pri[j]] = true;
			if (i % pri[j] == 0) break;
		}
	}
	for (int i = 1; i <= tot; ++i)
	{
		int x = pri[i];
		for (int j = x; j <= n; j += x)
			pd[j].push_back(i);
	}
}

template <long long T>
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
fast_io<1 << 20> io;
inline long long read()
{
	long long res = 0, neg = 1;
	char ch;
	do 
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	}	while (ch < 48 || ch > 57);
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
	init(1e5);
	n = read(), q = read();
	for (int i = 1; i <= n; ++i) 
	{
		a[i] = read(), nxt[i] = n + 1;
		for (int x : pd[a[i]])
			b[x].push_back(i);
	}
	nxt[n + 1] = n + 1;
	for (int i = 1; i <= tot; ++i)
		for (int j = 0; j + 1 < b[i].size(); ++j)
			nxt[b[i][j]] = std::min(nxt[b[i][j]], b[i][j + 1]);
	for (int i = n - 1; i >= 1; --i) nxt[i] = std::min(nxt[i], nxt[i + 1]);
	for (int i = 0; i < 18; ++i) jump[n + 1][i] = n + 1;
	for (int i = n; i >= 1; --i)
	{
		jump[i][0] = nxt[i];
		for (int j = 0; j < 17; ++j)
			jump[i][j + 1] = jump[jump[i][j]][j];
	}
	while (q--)
	{
		int l = read(), r = read(), ans = 0;
		for (int k = 16; k >= 0; --k)
			if (jump[l][k] <= r)
			{
				ans += 1 << k;
				l = jump[l][k];
			}
		output(ans + 1, '\n');
	}

}