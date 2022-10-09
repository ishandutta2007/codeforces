#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 3050;
ll n, g[N][N], f[N];
bool vis[N];

inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	#ifdef dbg
	int x; scanf("%d", &x); return x;
	#endif
    int res = 0, neg = 1;
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
	ll min = 0x3f3f3f3f;
	n = read();
	for (int i = 1; i <= n; ++i)
		for (int j = i + 1; j <= n; ++j)
		{
			g[j][i] = g[i][j] = read();
			min = std::min(min, g[i][j]);
		}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j < i; ++j)
		{
			g[i][j] -= min, g[j][i] -= min;
			f[i] = std::min(f[i], 2 * g[i][j]);
			f[j] = std::min(f[j], 2 * g[i][j]);
			// std::cerr << f[i] << std::endl;
		}
	for (int i = 1; i <= n; ++i)
	{
		int temp = 0;
		for (int j = 1; j <= n; ++j)
			if (f[temp] > f[j] && !vis[j])
				temp = j;
		// std::cerr << temp << std::endl;
		vis[temp] = true;
		for (int j = 1; j <= n; ++j)
			f[j] = std::min(f[j], f[temp] + g[temp][j]);
	}
	ll delta = (n - 1) * min;
	for (int i = 1; i <= n; ++i)
		printf("%lld\n", f[i] + delta);
	return 0;
}