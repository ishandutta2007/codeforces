#include<bits/stdc++.h>

typedef long long ll;
const int N = 5e5 + 50;

struct point_t
{
	int x, y, id;
	inline bool operator<(const point_t &rhs) const
	{
		if (x != rhs.x) return x < rhs.x;
		if (y != rhs.y) return y < rhs.y;
		return id < rhs.id;
	}	
} p[N];

int n, m, o, tot, buc[N], t[N];
bool vis[N], lose[N];
inline int lowbit(int x) { return x & -x; }
inline void add(int p)
{
	for (; p <= tot; p += lowbit(p)) ++t[p];
}
inline int query(int p)
{
	int ans = 0;
	for (; p; p -= lowbit(p)) ans += t[p];
	return ans;
}

template<int T>
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
		if (q1 == q2)
		{
			fwrite(q, 1, T, stdout);
			q1 = q;
		}
		*q1++ = c;
	}

	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<2000000> io;

inline int read()
{
	int r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
}

inline char readchar()
{
	char ch;
	do ch = io.gc(); while (!isalpha(ch));
	return ch;
}

inline void putint(int x)
{
	if (x < 0)
	{
		io.pc('-');
		putint(-x);
		return;
	}
	if (x / 10) putint(x / 10);
	io.pc(48 + x % 10);
}


inline void output(int x, char ch = ' ')
{
	putint(x);
	io.pc(ch);
}
int main()
{
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) p[i].x = read(), p[i].y = read(), buc[++tot] = p[i].y;
	for (int i = 1; i <= m; ++i) p[i + n].x = read(), p[i + n].y = read(), p[i + n].id = i;
	o = n + m;
	std::sort(p + 1, p + o + 1); 
	std::sort(buc + 1, buc + tot + 1);
	tot = std::unique(buc + 1, buc + tot + 1) - (buc + 1);
	int joined = 0, last = -1;
	auto find = [&](int x)
	{
		return std::upper_bound(buc + 1, buc + tot + 1, x) - buc - 1;
	};
	for (int i = 1; i <= o; ++i)
		if (p[i].id)
		{
			if (!p[i - 1].id && p[i].x == p[i - 1].x && p[i].y == p[i - 1].y) lose[p[i].id] = true;
			else if (p[i].x > last)
			{
				int y = find(p[i].y), d = joined - query(y);
				if ((p[i].y != buc[y] || !vis[y]) && p[i].x == p[i].y + d) lose[p[i].id] = true;
			}
		}
		else
		{
			int y= find(p[i].y), d = joined - query(y);
			if (p[i].x < p[i].y + d)
			{
				if (!vis[y])
					vis[y] = true, add(y);
			}
			else if (p[i].x > p[i].y + d && last != p[i].x) last = p[i].x, ++joined;
		}
	for (int i = 1; i <= m; ++i) puts(lose[i] ? "LOSE" : "WIN");
	return 0;
}