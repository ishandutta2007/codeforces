#include <bits/stdc++.h>

const int N = 2e5 + 50;
const int mod = 1e9 + 7;

inline int inc(int x, int y) { x += y - mod; return x + (x >> 31 & mod); }
inline int dec(int x, int y) { x -= y; return x + (x >> 31 & mod); }
inline int mul(int x, int y) { return 1ll * x * y % mod; }
inline void upd(int &x, int y) { x = inc(x, y); }
inline void dpu(int &x, int y) { x = dec(x, y); }
inline void pud(int &x, int y) { x = mul(x, y); }

int n, head[N], nxt[N], ver[N], sons[N], cnt;
int f[N][2], c[N][2];

inline void add(int x, int y)
{
	nxt[++cnt] = head[x];
	ver[cnt] = y;
	head[x] = cnt;	
}

void dfs(int x)
{
	int allzero_special_case = 1, allchange_special_case_count0 = 1,
	   allchange_special_case_count1 = 0, 
	    only_one_son_special_case = 0, special_status = 0;
	f[x][0] = 0, f[x][1] = 1;
	for (int i = head[x]; i; i = nxt[i])
	{	
		int y = ver[i];
		dfs(y);
		int c0 = c[x][0], c1 = c[x][1], f0 = f[x][0], f1 = f[x][1];
		upd(f[x][1], mul(f0, f[y][1])); upd(f[x][1], mul(f1, f[y][0]));
		upd(f[x][0], mul(f0, f[y][0])); upd(f[x][0], mul(f1, f[y][1]));
		pud(allzero_special_case, 1 + f[y][0]);
		int ac0 = allchange_special_case_count0, ac1 = allchange_special_case_count1;
		upd(allchange_special_case_count0, (mul(f[y][1], ac1)));
		upd(allchange_special_case_count1, (mul(f[y][1], ac0)));
	}
	if (sons[x] > 1)
	{
		pud(f[x][0], 2); pud(f[x][1], 2);
		dpu(f[x][1], allzero_special_case);
		dpu(f[x][0], allchange_special_case_count1);
	}
}

template<int T>
struct fast_io
{
	char ib[T], ob[T], *p1, *p2, *q1, *q2;

	fast_io()
	{
		p1 = p2 = ib;
		q1 = ob;
		q2 = ob + T;
	}

	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = ib) + fread(ib, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}

	inline void pc(char ch)
	{
		if (q1 == q2) q2 = (q1 = ob) + fwrite(ob, 1, T, stdout);
		*q1++ = ch;
	}

	~fast_io()
	{
		fwrite(ob, 1, q1 - ob, stdout);
	}
};

fast_io<1000000> io;

inline int64_t read()
{
	int64_t r = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do r = r * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return r * neg;
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

inline void outputs(const char *s)
{
	while (*s) io.pc(*s++);
	io.pc('\n');
}
int main()
{ 
	int T = 1;
	while (T--)
	{
		n = read();
		memset(head, 0, n + 1 << 2); cnt = 1;
		for (int i = 2; i <= n; ++i)
		{
			int x = read(); ++sons[x];
			add(x, i);
		}
		dfs(1);
		output(inc(f[1][0], f[1][1]), '\n');
	}
	return 0;
}