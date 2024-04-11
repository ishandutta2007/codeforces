#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <map>
#include <cctype>
#include <queue>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cassert>
#include <bits/stdc++.h>

typedef long long ll;
const int N = 5e5 + 50;
ll L, n, p, t, left[N], right[N];

struct nimber
{
	ll x, y;
	nimber(ll x = 0, ll y = 0) : x(x), y(y) {}
} dp[N];

inline nimber operator+(const nimber &x, const nimber &y) { return nimber(x.x + y.x, x.y + y.y); }
inline nimber operator-(const nimber &x, const nimber &y) { return nimber(x.x + y.x, x.y + y.y); }
inline nimber operator*(const ll k, const nimber &x) { return nimber(k * x.x, k * x.y); }
inline bool operator<(const nimber &x, const nimber &y)
{
	if (x.x != y.x) return x.x < y.x;
	return x.y > y.y;
}
inline nimber operator==(const nimber &x, const nimber &y) { return x.x == y.x && x.y == y.y; }
template <typename T>
inline T max(T x, T y)
{
	return x < y ? y : x;
}

inline char nc()
{
	static char buf[1000000], *p1 = buf,*p2 = buf;
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
	L = read(), n = read(), p = read(), t = read();
	for (int i = 1; i <= n; ++i)
	{
		left[i] = read(), right[i] = read();
	}
	dp[0] = nimber(0, -t);
	int j = 0;
	for (int i = 1; i <= n; ++i)
	{

		dp[i] = dp[i - 1];
		if (j > 0)
		{
			int k = max<ll>(left[i], dp[j - 1].y + t);
			dp[i] = max<nimber>(dp[i], nimber(dp[j - 1].x, k) + ((right[i] - k) / p) * nimber(1, p));
		}
		while (j < i && dp[j].y + t <= left[i]) dp[i] = max<nimber>(dp[i], nimber(dp[j].x, left[i]) + ((right[i] - left[i]) / p) * nimber(1, p)), ++j;
		while (j < i && dp[j].y + t <= right[i]) dp[i] = max<nimber>(dp[i], nimber(dp[j].x, dp[j].y + t) + ((right[i] - dp[j].y - t) / p) * nimber(1, p)), ++j;

		/*
		for (int j = 0; j < i; ++j)
		{
			int k = max<ll>(left[i], dp[j].y + t);
			dp[i] = max<nimber>(dp[i], nimber(dp[j].x, k) + ((right[i] - k) / p) * nimber(1, p));
		}
		*/
	}
	printf("%lld", dp[n].x);
	return 0;
}