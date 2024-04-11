#include <bits/stdc++.h>
int n;
long long cnt, sum;

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0;
	char ch;
	do ch = nc(); while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res;	
}

int main()
{
    n = read();
    for(int i = 1; i <= n; ++i)
    {
        if (read()) ++cnt;
        else sum += cnt;
    }
    printf("%lld", sum);
    return 0;
}