// By Qingyu
#include <bits/stdc++.h>

const int N = 3005;

int n, a[N], dp[N][N], pre[N][N];
bool flag;

inline bool upd(int &x, int y)
{
	if (x > y)
	{
		x = y;
		return true;
	}
	else return false;
}

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
	for (int i = 1; i <= n; ++i) a[i] = read();
	if (n % 2 == 0) a[++n] = 0, flag = true;
	else a[++n] = 0, a[++n] = 0, flag = false;
	memset(dp, 0x3f, sizeof dp);
	dp[0][1] = 0;
	for (int i = 1; i * 2 + 1 <= n; ++i)
	{
		for (int j = 1; j <= 2 * i - 1; ++j)
		{
			int A = std::max(a[i << 1], a[i << 1 | 1]), B = std::max(a[i << 1 | 1], a[j]), C = std::max(a[i << 1], a[j]);
			if (upd(dp[i][j], dp[i - 1][j] + A)) pre[i][j] = j;
			if (upd(dp[i][i * 2], dp[i - 1][j] + B)) pre[i][i * 2] = j;
			if (upd(dp[i][i * 2 + 1], dp[i - 1][j] + C)) pre[i][i * 2 + 1] = j;
			// upd(dp[i][j], 		dp[i - 1][j] + std::max(a[i * 2], a[i * 2 + 1]));
			// upd(dp[i][2 * i], 		dp[i - 1][j] + std::max(a[i * 2 + 1], a[j]));
			// upd(dp[i][2 * i + 1],	dp[i - 1][j] + std::max(a[i * 2], a[j])));
		}
	}
	printf("%d\n", dp[n >> 1][n]);
	std::vector<int> plans;
	int x = n;
	for (int i = (n >> 1); i >= 1; --i)
	{
		plans.push_back(x);
		x = pre[i][x];
	}
	std::reverse(plans.begin(), plans.end());
	std::set<int> remain;
	remain.insert(1);
	for (int i = 1; i <= (n >> 1); ++i)
	{
		if (i == (n >> 1) && !flag)
		{
			printf("%d\n", *remain.begin());
			break;
		}
		int v = plans[i - 1];
		if (v != *remain.begin())	
		{
			int t = *remain.begin();
			remain.erase(t);
			if (v == 2 * i)
			{
				printf("%d %d\n", 2 * i + 1, t);
				remain.insert(2 * i);
			}
			else
			{
				printf("%d %d\n", 2 * i, t);
				remain.insert(2 * i + 1);
			}
		}
		else printf("%d %d\n", 2 * i, 2 * i + 1);
	}
}