/*
 * sto RainAir orz
 */
#include <bits/stdc++.h>

typedef long long ll;
constexpr ll N = 5e5 + 50;

ll n, co[N][5], head[N], nxt[N], ver[N], dg[N], cnt, lf, lg, ced[N], ansss[N];
bool vis[N];

inline void add(int u, int v)
{
	nxt[++cnt] = head[u];
	ver[cnt] = v;
	head[u] = cnt;
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
	do ch = nc(); while (ch < 48 or ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 and ch <= 57);
	return res;
}

inline ll read_bit()
{
	char ch;
	do ch = nc(); while (ch < 48 or ch > 57);
	return ch - 48;
}

int main()
{
	n = read();
	for (int i = 1; i <= 3; ++i)
		for (int j = 1; j <= n; ++j) co[j][i] = read();
	if (n == 1)
	{
		int g = std::min(std::min(co[1][1], co[1][2]), co[1][3]);
		printf("%d\n", g);
		if (co[1][1] == g) printf("1");
		else if (co[1][2] == g) printf("2");
		else printf("3");
		return 0;
	}
	for (int i = 1; i < n; ++i)
	{
		int u = read(), v = read();
		++dg[u];
		++dg[v];
		add(u, v);
		add(v, u);
		if (dg[u] > 2 or dg[v] > 2)
		{
			printf("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; ++i)
		if (dg[i] == 1)
		{
			if (!lf) lf = i;
			else lg = i;
		}
	int u = lf, v = -1;
	ll answer = 1ll << 60;
	int g[6][3] = 
	{
		{1, 2, 3},
		{1, 3, 2},
		{2, 1, 3},
		{2, 3, 1},
		{3, 1, 2},
		{3, 2, 1}
	};
	int ty = 0;
	for (int c = 0; c <= 5; ++c)
	{
		memset(vis,0,sizeof vis);
		u = lf, v = -1;
		int d = 0;
		ll ans = 0;
		while (true)
		{
			ans += co[u][g[c][(d) % 3]];
			ced[u] = g[c][d % 3];
			for (int i = head[u]; i; i = nxt[i])
			{
				vis[u] = true;
				int y = ver[i];
				if (!vis[y])
				{
					v = u, u = y;
					goto fggg;
				}
			}
			fggg:
			++d;
			if (u == lg) 
			{
				ans += co[u][g[c][(d)%3]];
				ced[u] = g[c][d % 3];
				goto next_one;
			}
		}
		
		next_one:
		if (ans < answer)
		{
			answer = ans;
			ty = c;
			memcpy(ansss, ced, sizeof ced);
		}
	}
	printf("%lld\n", answer);
	for (int i = 1; i <= n; ++i) printf("%lld ", ansss[i]);
	return 0;	
}