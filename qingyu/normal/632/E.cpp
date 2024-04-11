#include <bits/stdc++.h>

const int N = 1e6 + 50;
int n, k, a[N], dp[N];

inline char nc()
{
	static char buf[1000000], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline int read()
{
	int res = 0, ng = 1;
	char ch;
	do 
	{
		ch = nc();
		if (ch == '-') ng = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * ng;
}

int main()
{
	n = read(), k = read(); memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= n; ++i) a[i] = read(); std::sort(a + 1, a + n + 1);
	for (int i = 2; i <= n; ++i) a[i] -= a[1];
	int S = a[n] * k;
	dp[0] = 0;
	for (int i = 2; i <= n; ++i) for (int j = a[i]; j <= S; ++j) dp[j] = std::min(dp[j], dp[j - a[i]] + 1);
	for (int i = 0; i <= S; ++i) if (dp[i] <= k) printf("%d ", i + k * a[1]);
}


// By Qingyu