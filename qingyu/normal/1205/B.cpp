#include <bits/stdc++.h>

typedef long long ll;
constexpr int N = 5e5 + 50;

ll __n, n, a[N], b[N], G[200][200], g[200][200];

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

inline int floyd()
{
	ll ans = 0x3f3f3f3f;
    for(int k = 1; k <= n; ++k) 
	{
        for(int i = 1; i < k; ++i)
            for(int j = i + 1; j < k; ++j)
                ans = std::min(ans, G[i][j] + g[i][k] + g[k][j]);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(G[i][j] > G[i][k] + G[k][j])
                    G[i][j] = G[i][k] + G[k][j];
    }
	return ans;
}

int main()
{
	__n = read();
	for (int i = 1; i <= __n; ++i)
	{
		a[i] = read();
		if (a[i]) b[++n] = a[i];
	}
	if (n > 128)
	{
		puts("3");
		return 0;
	}
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			if (i != j and ((b[i] & b[j]) != 0))
				G[i][j] = G[j][i] = g[i][j] = g[j][i] = 1;
			else G[i][j] = G[j][i] = g[i][j] = g[j][i] = 0x3f3f3f3f;
	ll ans = floyd();
	printf("%lld", ans > 128 ? -1 : ans);
	return 0;	
}