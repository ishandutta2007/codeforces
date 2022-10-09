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
	int n = read(), K = read();
	for (int i = 1; i <= n; ++i)
	{
		songs[i].t = read(), songs[i].b = read();
	}
	std::sort(songs + 1, songs + n + 1, [](song a, song y)
	{
		return a.b > y.b;
	});
	std::priority_queue<ll> q;
	ll len = 0, ans = -1;
	for (int i = 1; i <= K; ++i)
	{
		q.push(-songs[i].t);
		len += songs[i].t;
		ans = std::max(ans, len * songs[i].b);
	}
	for (int i = K + 1; i <= n; ++i)
	{
		int x = -q.top();
		if (x < songs[i].t)
		{
			q.pop();
			q.push(-songs[i].t);
			len -= x;
			len += songs[i].t;
			ans = std::max(ans, len * songs[i].b);
		}
	}
	printf("%lld", ans);
	return 0;
}