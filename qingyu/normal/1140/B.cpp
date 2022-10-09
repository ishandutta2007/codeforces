// by sqy
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

char s[10005], t[10005];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n; scanf("%d", &n);
		scanf("%s", s + 1);
		int cnt = 0;
		while (s[cnt + 1] == '<') ++cnt;
		int ans = cnt;
		std::reverse(s + 1, s + n + 1);
		cnt = 0;
		while (s[cnt + 1] == '>') ++cnt;
		ans = std::min(ans, cnt);
		printf("%d\n", ans);
	}
	return 0;
}