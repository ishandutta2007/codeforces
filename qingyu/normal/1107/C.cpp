//qwq
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <map>
#include <cctype>
#include <iostream>

constexpr int N = 2e5 + 50;

int n, a[N];
char s[N];

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

inline int read_hex()
{
	int res = 0;
	char ch;
	do ch = nc(); while (!isdigit(ch) && !isalpha(ch));
	res = res * 10;
	if (isdigit(ch)) res += ch - '0';
	if (isalpha(ch)) res += ch - 'A' + 10;
	return res;
}

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", a + i);
	}
	long long ans = 0;
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i)
	{
		std::priority_queue<int> pq;
		int j;
		for (j = i; j <= n; ++j)
		{
			if (s[i] != s[j]) break;
			pq.push(a[j]);
		}
		i = j - 1;
		for (int g = 1; g <= k; ++g)
		{
			if (pq.empty()) break;
			ans += pq.top();
			pq.pop();
		}
	}
	printf("%lld", ans);
	return 0;
}