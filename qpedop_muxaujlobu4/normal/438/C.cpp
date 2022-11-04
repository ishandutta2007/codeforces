#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e18 + 100;
const int mod = 1000000007;
const ld eps = 1e-12, pi = acosl(-1);
const ll maxN = 210, maxT = 2001, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "No solution\n";
	exit(0);
}
struct point {
	ld x, y;
	point(ld X = 0, ld Y = 0) {
		x = X;
		y = Y;
	}
};
point operator +(const point& a, const point& b) {
	return point(a.x + b.x, a.y + b.y);
}
point operator -(const point& a, const point& b) {
	return point(a.x - b.x, a.y - b.y);
}
point operator *(const point& a, const ld& b) {
	return point(a.x * b, a.y * b);
}
point operator /(const point& a, const ld& b) {
	return point(a.x / b, a.y / b);
}
ld cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}
struct line {
	ld a, b, c;
	line(point f, point s) {
		a = f.y - s.y;
		b = s.x - f.x;
		c = f.x * a + f.y * b;
	}
	line(ld A = 0, ld B = 0, ld C = 0) {
		a = A;
		b = B;
		c = C;
	}
};
line operator +(const line& a, const line& b) {
	return line(a.a + b.a, a.b + b.b, a.c + b.c);
}
line operator -(const line& a, const line& b) {
	return line(a.a - b.a, a.b - b.b, a.c - b.c);
}
line operator *(const line& a, const ld& b) {
	return line(a.a * b, a.b * b, a.c * b);
}
line operator /(const line& a, const ld& b) {
	return line(a.a / b, a.b / b, a.c / b);
}
int n;
vector<vector<int>>dp, g;
ll rec(int l, int r) {
	if (dp[l][r] != -1)
		return dp[l][r];
	if (l + 2 >= r)
		return dp[l][r] = 1;
	dp[l][r] = 0;
	for (int i = l + 2; i < r; ++i) {
		if (g[l][i] && (g[i][r] || i + 1 == r)) {
			dp[l][r] = (dp[l][r] + rec(l, i) * rec(i, r) % mod) % mod;
		}
	}
	if (g[l + 1][r]) {
		dp[l][r] = (dp[l][r] + rec(l + 1, r)) % mod;
	}
	return dp[l][r];
}
bool inside(point l, point r, point t) {
	bool f = 1;
	f &= t.x > min(l.x, r.x) - eps;
	f &= t.x < max(l.x, r.x) + eps;

	f &= t.y > min(l.y, r.y) - eps;
	f &= t.y < max(l.y, r.y) + eps;

	return f;
}
point intersect(line f, line s) {
	if (abs(s.a) > abs(f.a))swap(s, f);
	if (abs(f.a) < eps)
		return point(INF, INF);
	s = s - f * (s.a / f.a);
	if (abs(s.b) < eps)
		return point(INF, INF);
	f = f - s * (f.b / s.b);
	return point(f.c / f.a, s.c / s.b);
}
bool inter(point a, point b, point c, point d) {
	point pp = intersect(line(a, b), line(d, c));
	return inside(a, b, pp) && inside(c, d, pp);
}
void solve() {
	cin >> n;
	dp.assign(n, vector<int>(n, -1));
	g.assign(n, vector<int>(n));
	vector<point>a(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		a[i] = point(x, y);
	}
	a.push_back(a[0]);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 2; j < n; ++j) {
			bool f = i != 0 || j != n - 1;
			//f&=cross(a[i]-a[j])
			point tmp = (a[i] * 5 + a[j] * 7) / 12;
			point dd = point(1e7 + 7, -(1e7 + 33));
			int cnt = 0;
			for (int k = 0; k < n; ++k) {
				if (k == i || k == j)
					continue;
				line ln = line(a[i], a[j]);
				f &= !inside(a[i], a[j], a[k]) || abs(ln.a * a[k].x + ln.b * a[k].y - ln.c) > eps;
				if ((k + 1) % n == i || (k + 1) % n == j)
					continue;
				//point pp = intersect(line(a[i], a[j]), line(a[k], a[k + 1]));
				f &= !inter(a[i], a[j], a[k], a[k + 1]);
			}
			for (int k = 0; k < n; ++k) {
				if (inter(tmp, dd, a[k], a[k + 1]))
					++cnt;
			}
			f &= cnt % 2 == 1;
			g[i][j] = g[j][i] = f;
		}
	}
	cout << rec(0, n - 1) << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("commuting.in", "r", stdin); freopen("commuting.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}

/*
5
2 1 3 5 4
simple solve: 1 2 3 1 2
1 2 3 3 3
*/