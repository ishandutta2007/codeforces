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
		ll pasted = x - n * (x / n);
		tar_x += dx[pasted], tar_y += dy[pasted];
		//printf("%lld %lld %lld %lld %lld\n", tar_x, tar_y, x2, y2, abs(x2 - tar_x) + abs(y2 - tar_y));
		if (abs(x2 - tar_x) + abs(y2 - tar_y) <= x) return true;
		else return false;
	}
	inline void doWork()
	{
		scanf("%lld%lld%lld%lld%lld%s", &x1, &y1, &x2, &y2, &n, s + 1);
		for (int i = 1; i <= n; ++i)
		{
			dx[i] = dx[i - 1], dy[i] = dy[i - 1];
			if (s[i] == 'U') ++dy[i];
			else if (s[i] == 'D') --dy[i];
			else if (s[i] == 'L') --dx[i];
			else ++dx[i];
		}
		ll l = 0, r = 1e15;
		if (Check(r) == false)
		{
			printf("-1");
			return;
		}
		while (r - l > 0)
		{
			const ll mid = l + r >> 1;
			if (Check(mid)) r = mid;
			else l = mid + 1;
		}
		printf("%lld", l);
	}
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
	sqy::doWork();
	return 0;
}