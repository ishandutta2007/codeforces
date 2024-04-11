#pragma GCC optimize(3)
#include <bits/stdc++.h>

typedef long long ll;
inline char nc()
{
    static char buf[1000000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
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

struct song
{
	ll t, b;
} songs[500005];
int main()
{
	int n = read();
	ll ans = 1ll << 50ll;
	for (int i = 1; i <= n; ++i)
	{
		//printf("calc %d\n", i);
		ll tans = 0;
		for (int j = i + 1; j < n + i - 1; ++j)
		{
			//printf("calc %d %d %d\n", i, (j - 1) % n + 1, j % n + 1);
			tans += i * ((j - 1) % n + 1) * (j % n + 1);
		}
		ans = std::min(ans, tans);
		//printf("tans = %lld, ans = %lld\n\n", tans, ans);
	}
	printf("%lld", ans);
	return 0;
}