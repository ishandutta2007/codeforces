#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <cctype>
#include <string>

constexpr int N = 1e6 + 50;
typedef long long ll;
namespace sqy
{
	ll x1, y1, x2, y2, n, a[N], dx[N], dy[N];
	char s[N];

	inline ll abs(ll x) { return x > 0 ? x : -x; }

	inline bool Check(ll x)
	{
		//printf("%lld\n", x);
		ll tar_x = x1 + dx[n] * (x / n), tar_y = y1 + dy[n] * (x / n);
		ll pasted = x % n;
		tar_x += dx[pasted], tar_y += dy[pasted];
		//printf("%lld %lld %lld %lld %lld\n", tar_x, tar_y, x2, y2, abs(x2 - tar_x) + abs(y2 - tar_y));
		if (abs(x2 - tar_x) + abs(y2 - tar_y) <= x) return true;
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

	inline void doWork()
	{
		n = read();
		ll max = -100000, cet = -100000, left = 0;
		for (int i = 1; i <= n; ++i)
		{
			a[i] = abs(read());
			max = std::max(max, a[i]);
		}
		for (int i = 1; i <= n; ++i)
		{
			if (a[i] == max) ++left;
			else left = 0;
			if (left > cet) cet = left;
		}
		printf("%lld", cet);
	}
}

int main()
{
	sqy::doWork();
	return 0;
}