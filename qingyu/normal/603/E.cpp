#include <bits/stdc++.h>

const int N = 2e6 + 50;

int n, m;
int fa[N], ch[N][2], siz[N], img_siz[N], tag[N], tot, val[N];
int bu[N], bv[N], bw[N];
int max[N], max_v[N];
int odd_cnt;
bool del[N];

inline int isRoot(int x) { return x != ch[fa[x]][0] && x != ch[fa[x]][1]; }
inline int dir(int x) { return ch[fa[x]][1] == x; }
inline void push_up(int x) 
{ 
	max[x] = x; max_v[x] = val[x];
	if (ch[x][0] && max_v[ch[x][0]] > max_v[x]) max_v[x] = max_v[ch[x][0]], max[x] = max[ch[x][0]];
	if (ch[x][1] && max_v[ch[x][1]] > max_v[x]) max_v[x] = max_v[ch[x][1]], max[x] = max[ch[x][1]];
	siz[x] = siz[ch[x][0]] + siz[ch[x][1]] + (x <= n) + img_siz[x];
}
inline void push_rev(int x) { std::swap(ch[x][0], ch[x][1]); tag[x] ^= 1; } 
inline void push_down(int x) 
{ 
	if (tag[x]) 
	{ 
		if (ch[x][0]) push_rev(ch[x][0]); 
		if (ch[x][1]) push_rev(ch[x][1]); 
		tag[x] = 0; 
	}
}

inline void rotate(int x)
{
	int y = fa[x], z = fa[y], k = dir(x), w = ch[x][k ^ 1];
	ch[y][k] = w; fa[w] = y;
	if (!isRoot(y)) ch[z][dir(y)] = x; fa[x] = z;
	ch[x][k ^ 1] = y; fa[y] = x;
	push_up(y); push_up(x);
}

inline void splay(int x)
{
	static int stack[N], top;
	
	int y = x; stack[top = 1] = y;
	while (!isRoot(y)) stack[++top] = y = fa[y];
	while (top) push_down(stack[top--]);
	
	while (!isRoot(x))
	{
		int y = fa[x];
		if (!isRoot(y))
		{
			if (dir(x) == dir(y)) rotate(y);
			else rotate(x);
		}
		rotate(x);
	}
	push_up(x);
}

inline void access(int x)
{
	for (int y = 0; x; x = fa[y = x])
		splay(x), img_siz[x] += siz[ch[x][1]], ch[x][1] = y, img_siz[x] -= siz[y], push_up(x);
}

inline void makeroot(int x)
{
	access(x), splay(x), push_rev(x);
}

inline int findroot(int x)
{
	access(x), splay(x); while (ch[x][0]) push_down(x), x = ch[x][0];
	return splay(x), x;
}

inline void split(int x, int y)
{
	makeroot(x), access(y), splay(y);
}

inline void link(int x, int y)
{
	split(x, y); odd_cnt -= (siz[x] & 1) + (siz[y] & 1);
	img_siz[fa[x] = y] += siz[x];
	push_up(y);
	odd_cnt += (siz[y] & 1);
}

inline void cut(int x, int y)
{
	split(x, y); odd_cnt -= siz[y] & 1;
	fa[x] = ch[y][0] = 0;
	push_up(y);
	odd_cnt += (siz[x] & 1) + (siz[y] & 1);
}

std::priority_queue<std::pair<int, int> > Q;
inline void add(int id)
{
	int x = bu[id], y = bv[id], z = bw[id];
	bool ok = true;
	if (findroot(x) == findroot(y))
	{
		split(x, y);
		int o = max[y];
		if (val[o] > z) cut(bu[o], o), cut(o, bv[o]), del[o] = true;
		else ok = false;
	}
	if (ok)
	{
		push_up(id);
		link(x, id); link(id, y);
		Q.push(std::make_pair(z, id));
	}
	if (odd_cnt > 0) return printf("-1\n"), void();
	while (Q.empty() == false)
	{
		int o = Q.top().second; Q.pop();
		if (!del[o])
		{
			cut(bu[o], o); cut(bv[o], o);
			if (odd_cnt > 0)
			{
				link(bu[o], o); link(bv[o], o);
				return printf("%d\n", bw[o]), Q.push(std::make_pair(bw[o], o)), void();
			}
		}
	}
	printf("0\n");
}

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2)? EOF : *p1++;
}

inline int read()
{
	int neg = 1, res = 0;
	char ch;
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int main()
{
	n = read(), m = read(), odd_cnt = n;
	for (int i = 1; i <= n; ++i) push_up(i);
	for (int i = 1; i <= m; ++i)
	{
		bu[i + n] = read(), bv[i + n] = read(), bw[i + n] = read();
		val[i + n] = bw[i + n];
		add(i + n);
		assert(odd_cnt >= 0);
	}
	return 0;
}