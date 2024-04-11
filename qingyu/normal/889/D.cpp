#include <bits/stdc++.h>


typedef long long ll;
const int N = 5005;

int n;
ll f[N];
bool vis[N];
std::map<std::pair<int, int>, bool> map;
inline ll gcd(ll x, ll y)
{
	return y ? gcd(y, x % y) : x;
}

inline bool work()
{
	int l = 1, r = n;
	while (l <= r && f[l] + f[r] == 0) ++l, --r;
	return l > r;
}

struct Point
{
	ll x, y;
	Point (ll x = 0, ll y = 0) : x(x), y(y){}
} P[N], Q[N], G;

inline Point operator+(const Point &u, const Point &v) { return Point(u.x + v.x, u.y + v.y); }
inline Point operator-(const Point &u, const Point &v) { return Point(u.x - v.x, u.y - v.y); }
inline Point operator*(const ll k, const Point &v) { return Point(k * v.x, k * v.y); }
inline bool operator==(const Point &a, const Point &b) { return a.x == b.x && a.y == b.y; }

inline bool ref(Point A, Point B, Point M)
{
	return 2 * M == A + B;
}

inline char nc()
{
	static char buf[1000000], *p1 = buf,*p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1000000, stdin), p1 == p2) ? EOF : *p1++;
}

inline ll read()
{
	ll res = 0, neg = 1;
	char ch;
	do 
	{
		ch = nc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = nc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

int main(int, char**)
{
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		P[i].x = read() * n, P[i].y = read() * n;
		G = G + P[i];
	}
	G.x /= n, G.y /= n;
	for (int i = 1; i <= n; ++i) P[i] = P[i] - G;
	Point O(0, 0);
	for (int i = 1; i <= n; ++i)
	{
		if (P[i] == Point(0, 0)) vis[i] = true;
		else
		{
			for (int j = 1; j < i; ++j)
			{
				if (P[i] + P[j] == O)
				{
					vis[i] = vis[j] = true;
					break;
				}
			}
		}
	}
	int m = n;
	n = 0;
	for (int i = 1; i <= m; ++i) if (!vis[i]) Q[++n] = P[i];
	if (n <= 2) return printf("-1"), 0;
	int ans = 0;
	for (int i = 1; i <= n; ++i)
	{
		Point R = Q[1] + Q[i];
		ll x = R.x, y = R.y, g = gcd(x, y);
		x /= g, y /= g;
		
		if (!map.count(std::make_pair(x, y)))
		{
			for (int j = 1; j <= n; ++j) f[j] = x * Q[j].y - Q[j].x * y;
			std::sort(f + 1, f + n + 1);
			if (work())
			{
				++ans;
				map[std::make_pair(x, y)] = true;
			}
		}
	}
	printf("%d", ans);
	return 0;
}