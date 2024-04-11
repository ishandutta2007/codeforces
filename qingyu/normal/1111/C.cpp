#include <bits/stdc++.h>

const int N = 2e6 + 50;

typedef long long ll;
ll n, k, A, B;
ll S[N], lc[N], rc[N], ans[N], ncnt = 1;

inline void push_up(int o, int len)
{
	S[o] = S[lc[o]] + S[rc[o]];
	ans[o] = std::min(ans[lc[o]] + ans[rc[o]], B * S[o] * len);	
}

int insert(int o, int l, int r, ll p)
{
	if (!o) o = ++ncnt;
	if (l == r)
	{
		++S[o];
		ans[o] = B * S[o];
	}
	else
	{
		const int mid = l + r >> 1;
		if (p <= mid) lc[o] = insert(lc[o], l, mid, p);
		if (p > mid) rc[o] = insert(rc[o], mid + 1, r, p);
		push_up(o, r - l + 1);
	}
	return o;	
}

inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
    ll res = 0;
    char ch;
    do ch = nc(); while (ch < 48 || ch > 57);
    do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
    return res;
}

int main()
{
	n = read(), k = read(), A = read(), B = read();
	ans[0] = A;
	while (k--)
	{
		int p = read();
		insert(1, 1, 1 << n, p);	
	}
	printf("%lld", ans[1]);
	return 0;	
}