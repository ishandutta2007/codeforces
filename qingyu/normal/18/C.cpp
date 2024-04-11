#include <bits/stdc++.h>

int n, s[100005];

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

int main()
{
	int ans = 0; n = read();
	for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + read();
	for (int j = 1; j < n; ++j)
		if (s[j] == s[n] - s[j])
			++ans;
	printf("%d", ans);
	return 0;
}