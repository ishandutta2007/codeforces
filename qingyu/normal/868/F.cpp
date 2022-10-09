#include <bits/stdc++.h>

typedef long long ll;
const int N = 1e5 + 50, M = 20;

int n, m;
int a[N];
ll f[N][M];

int L, R; ll buc[N];

ll ans;
inline void update(ll v, ll p)
{
	ans += buc[v] * (buc[v] - 1) / 2 * p;
}

inline ll cost(int l, int r)
{
	while (L < l) update(a[L], -1), --buc[a[L]], update(a[L], 1), ++L;
	while (L > l) --L, update(a[L], -1), ++buc[a[L]], update(a[L], 1);
	while (R > r) update(a[R], -1), --buc[a[R]], update(a[R], 1), --R;
	while (R < r) ++R, update(a[R], -1), ++buc[a[R]], update(a[R], 1);
	return ans;
}

void dp(int l, int r, int p, int q, int k)
{
	if (l <= r && p <= q)
	{
		const int mid = l + r >> 1;
		int v = p;
		f[mid][k] = 1e14;
		for (int i = p; i <= q && i < mid; ++i)
		{
			ll res = f[i][k - 1] + cost(i + 1, mid);
			if (res < f[mid][k]) f[mid][k] = res, v = i;
		}
		dp(l, mid - 1, p, v, k);
		dp(mid + 1, r, v, q, k);
	}
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
	memset(f, 0x3f, sizeof f);
	n = read(), m = read();
	for (int i = 1; i <= n; ++i) a[i] = read();
	L = R = 1; ++buc[a[1]];
	f[0][0] = 0;
	for (int i = 1; i <= m; ++i) dp(1, n, 0, n - 1, i);
	printf("%lld",f[n][m]);
	return 0;
}