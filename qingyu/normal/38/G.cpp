//By C++17
#pragma GCC optimize(3)
#include<bits/stdc++.h>

const int N = 5e5 + 50;

int ch[N][2], fa[N], siz[N], _val[N], cnt[N], tot, sum[N], min[N], max[N];
int L[N], R[N], ans_min[N], perm[N]; 

inline void maintain(int o) 
{ 
	siz[o] = siz[ch[o][0]] + siz[ch[o][1]] + cnt[o];
	sum[o] = sum[ch[o][0]] + sum[ch[o][1]] +_val[o];
	min[o] = std::min(std::min(min[ch[o][0]], min[ch[o][1]]), _val[o]);
	max[o] = std::max(std::max(max[ch[o][0]], max[ch[o][1]]), _val[o]);
	if (ch[o][0]) L[o] = L[ch[o][0]]; else L[o] = _val[o];
	if (ch[o][1]) R[o] = R[ch[o][1]]; else R[o] = _val[o];
	ans_min[o] = std::min(ans_min[ch[o][0]], ans_min[ch[o][1]]);
	if (ch[o][0]) ans_min[o] = std::min(ans_min[o], abs(_val[o] - R[ch[o][0]]));
	if (ch[o][1]) ans_min[o] = std::min(ans_min[o], abs(_val[o] - L[ch[o][1]]));
	
	assert(cnt[o] <= 1);
	assert(_val[o]);
}
inline int dir(int o) { return o == ch[fa[o]][1]; }
inline int newnode(int v)
{
	int o = ++tot;
	fa[o] = ch[o][0] = ch[o][1] = 0;
	cnt[o] = siz[o] = 1;
	_val[o] = v;
	return o;
}

inline int build(int l, int r, const int *A)
{
	if (l > r) return 0;
	const int mid = l + r >> 1;
	int o = newnode(A[mid]);
	if (ch[o][0] = build(l, mid - 1, A)) fa[ch[o][0]] = o;
	if (ch[o][1] = build(mid + 1, r, A)) fa[ch[o][1]] = o;
	maintain(o);
	return o;
}

struct Splay
{
int root;
inline void rotate(int o)
{
	int y = fa[o], z = fa[y], k = dir(o), w = ch[o][k ^ 1];
	ch[y][k] = w; fa[w] = y;
	ch[z][dir(y)] = o; fa[o] = z;
	ch[o][k ^ 1] = y; fa[y] = o;
	maintain(y); maintain(o);
}

inline void splay(int o, int target = 0)
{
	while (fa[o] != target)
	{
		int y = fa[o], z = fa[y];
		if (z != target)
		{
			if (dir(o) == dir(y)) rotate(y);
			else rotate(o);
		}
		rotate(o);
	}
	if (!target) root = o;
}

inline int kth(int k)
{
	int cur = root;
	while (true)
	{
		if (ch[cur][0] && siz[ch[cur][0]] >= k) cur = ch[cur][0];
		else if (siz[ch[cur][0]] + cnt[cur] < k) k -= siz[ch[cur][0]] + cnt[cur], cur = ch[cur][1];
		else return cur;
	}
}

inline void DEBUG(int o = -1)
{
	if (o < 0) o = root;
	if (ch[o][0]) DEBUG(ch[o][0]);
	printf("%d ", _val[o]);
	if (ch[o][1]) DEBUG(ch[o][1]);
	if (o == root) printf("\n");
}

inline void show(int o = -1)
{
	if (o < 0) o = root;
	if (ch[o][0]) show(ch[o][0]);
	if (_val[o] > (int)(0xcfcfcfcf) && _val[o] < (int)(0x3f3f3f3f)) printf("%d ", perm[_val[o]]);
	if (ch[o][1]) show(ch[o][1]);
}

inline void insert(int x, int y)
{
	if (!root) root = y;
	else
	{
		int u = kth(x + 1), v = kth(x + 2);
		splay(u); splay(v, u);
		ch[v][0] = y; fa[y] = v;
		maintain(v); maintain(u);
	}
}

inline int query(int l, int r, int *s)
{
	int u = kth(l), v = kth(r + 2);
	splay(u); splay(v, u);
	
	return s[ch[v][0]];
}

inline void erase(int x, int c)
{
	int u = kth(x), v = kth(x + c + 1);
	splay(u); splay(v, u);
	int del = ch[v][0];
	fa[del] = _val[del] = min[del] = max[del] = ans_min[del]
	= ch[v][0] = cnt[del] = ch[del][0] = ch[del][1] = 0;
	maintain(v), maintain(u);
}

} T;

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

inline int read_op()
{
	char ch;
	do ch = nc(); while (!isalpha(ch));
	char c2 = nc();
	if (ch == 'i') return 2;
	else if (c2 == 'e') return 1;
	else if (c2 == 'a') return 3;
	else if (c2 == 'i') return 4;
}

int main()
{
	ans_min[0] = min[0] = 0x3f3f3f3f; max[0] = 0xcfcfcfcf;
	int n = read(); static int A[N], B[N], C[N];
	for (int i = 2; i <= n + 1; ++i) 
	{
		A[i] = read(), C[i] = read();
		perm[A[i]] = i - 1;
	}
	A[1] = A[n + 2] = 0xcfcfcfcf;
	T.insert(0, build(1, n + 2, A));
	
	for (int i = 1; i <= n; ++i)
	{
		int l = std::max(1, i - C[i + 1]), r = i, res = 0;
		while (l <= r)
		{
			int mid = l + r >> 1;
			if (T.query(mid, i, max) > A[i + 1])
			{
				l = mid + 1;
			}
			else res = mid, r = mid - 1;
		}
		T.erase(i, 1);
		B[1] = A[i + 1];
		T.insert(res - 1, build(1, 1, B));
	}
	
	T.show();
	
	return 0;
}