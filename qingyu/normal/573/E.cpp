#include <bits/stdc++.h>

const int N = 2e5 + 50;

int rt, ch[N][2], siz[N], fa[N], tot = 1;
int64_t a[N], tag[N], val[N], seq[N], cnt;
bool rev[N];

inline int dir(int x) { return x == ch[fa[x]][1]; }
inline void push_up(int o)
{
	siz[o] = siz[ch[o][0]] + siz[ch[o][1]] + 1;
}
inline void push_down(int o)
{
	if (tag[o])
	{
		tag[ch[o][0]] += tag[o]; val[ch[o][0]] += tag[o];
		tag[ch[o][1]] += tag[o]; val[ch[o][1]] += tag[o];
		tag[o] = 0;
	}
}
inline void push_all(int x)
{
	if (fa[x]) push_all(fa[x]);
	push_down(x);
}
inline void rotate(int x)
{
	int y = fa[x], z = fa[y], k = dir(x), w = ch[x][k ^ 1];
	ch[y][k] = w, fa[w] = y;
	ch[z][dir(y)] = x, fa[x] = z;
	ch[x][k ^ 1] = y, fa[y] = x;
	push_up(y), push_up(x);	
}
inline void splay(int x, int tar = 0)
{
	push_all(x);
	while (fa[x] != tar)
	{
		int y = fa[x], z = fa[y];
		if (z != tar)
		{
			if (dir(x) == dir(y)) rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	if (!tar) rt = x;
}
inline int kth(int k)
{
	int x = rt;
	while (true)
	{
		push_down(x);
		if (siz[ch[x][0]] >= k) x = ch[x][0];
		else if (siz[ch[x][0]] + 1 < k)
			k -= siz[ch[x][0]] + 1,
			x = ch[x][1];
		else return x;
	}
}

inline int newnode(int64_t x)
{
	int o = ++tot;
	val[o] = x, ch[o][0] = ch[o][1] = fa[o] = 0, siz[o] = 1;
	return o;
}
inline int binary_search(int64_t a)
{
	int x = rt, s = 0, lst = 0;
	while (true)
	{
		if (!x) return lst;
		push_down(x);
		int id = s + siz[ch[x][0]];
		//printf("x = %d, id = %d, ch[x][0] = %d, ch[x][1] = %d, lsz = %d\n", x, id, ch[x][0], ch[x][1], siz[ch[x][0]]);	
		if (val[x] >= id * a || (x == 1))
		{
			s += siz[ch[x][0]] + 1;
			x = ch[x][1];
		}
		else
		{
			if (x == 1) return lst;
			lst = x;
			x = ch[x][0];
		}
	}
}
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
fast_io<1 << 20> io;
inline int read()
{
	int res = 0, neg = 1;
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
void debug(int x)
{
	push_down(x);
	if (ch[x][0]) debug(ch[x][0]);
	printf("%d[%d] ", val[x], x);
	if (ch[x][1]) debug(ch[x][1]);
	if (x == rt) putchar('\n');
}

void dfs(int x)
{
	push_down(x);
	if (ch[x][0]) dfs(ch[x][0]);
	seq[++cnt] = val[x];
	if (ch[x][1]) dfs(ch[x][1]);
}

int main()
{
	int n = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	rt = 1; push_up(rt); assert(siz[rt] == 1);
	for (int i = 1; i <= n; ++i)
	{
		assert(tot == i);
		int x = binary_search(a[i]);
		if (x)
		{
			splay(x);
			int y = ch[x][0], k = siz[y];
			push_down(y);	
			ch[x][0] = newnode(k * a[i]);
			fa[ch[x][0]] = x;
			ch[ch[x][0]][0] = y; 

			if (y) fa[y] = ch[x][0], push_up(y); 
			assert(x == rt);
			val[x] += a[i]; val[ch[x][1]] += a[i];
			tag[ch[x][1]] += a[i];
			push_up(ch[x][0]);
			push_up(x);
		}
		else
		{
			x = rt;
			while (ch[x][1]) x = ch[x][1];
			splay(x);
			ch[x][1] = newnode(i * a[i]); fa[ch[x][1]] = x;
			push_up(x);
		}
	}
	int64_t ans = 0;
	dfs(rt);
	for (int i = 1; i <= n + 1; ++i)
	{
		seq[i] += seq[i - 1];
		ans = std::max(ans, seq[i]);
	}
	output(ans);
	return 0;
}