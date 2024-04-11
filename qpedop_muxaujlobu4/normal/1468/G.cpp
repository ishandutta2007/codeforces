#pragma comment(linker, "/STACK:9759095000")
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
//#define double long double
typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
ll __builtin_popcount(ll x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
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
const ll INF = 1e18;
const int mod = 1000000007, mod1 = 1000000009;
const ld eps = 1e-9, pi = acos(-1);
const int maxN = 500100, maxT = 1601;
struct Point {
	ld x, y;
	Point(ld X = 0, ld Y = 0) {
		x = X;
		y = Y;
	}
};
Point operator +(Point a, Point b) {
	return Point(a.x + b.x, a.y + b.y);
}
Point operator -(Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}
Point operator *(Point a, ld b) {
	return Point(a.x * b, a.y * b);
}
Point operator /(Point a, ld b) {
	return Point(a.x / b, a.y / b);
}
ld len2(Point a) {
	return a.x * a.x + a.y * a.y;
}
ld len(Point a) {
	return sqrt(len2(a));
}
ld vec_cross(Point a, Point b) {
	return a.x * b.y - b.x * a.y;
}
struct line {
	ld a, b, c;
	line(ld A = 0,ld B = 0,ld C = 0) {
		a = A;
		b = B;
		c = C;
	}
	line(Point A, Point B) {
		a = B.y - A.y;
		b = -(B.x - A.x);
		c = a * A.x + b * A.y;
		c = -c;
	}
};
Point cross(line a, line b) {
	a.c = -a.c;
	b.c = -b.c;
	if (abs(b.a) > abs(a.a))swap(a, b);
	ld d = b.a / a.a;
	b.a -= d * a.a;
	b.b -= d * a.b;
	b.c -= d * a.c;
	d = a.b / b.b;
	a.b -= d * a.a;
	a.c -= d * b.c;
	return Point(a.c / a.a, b.c / b.b);
}
void solve() {
	int n = getint<int>();
	ll h = getint<int>();
	vector<Point>a(n);
	for (auto& x : a) {
		x.x = getint<int>();
		x.y = getint<int>();
	}
	Point en = a.back();
	en.y += h;
	ld s = 0;
	line our = line(a.back(), en);
	int id = n - 1;
	for (int i = n - 2; i >= 0; --i) {
		if (vec_cross(a[i] - a[id], en - a[id]) < eps) {
			if (vec_cross(a[i + 1] - a[id], en - a[id]) < eps) {
				s += len(a[i + 1] - a[i]);
			}
			else {
				s += len(cross(line(a[i + 1], a[i]), our) - a[i]);
			}
			our = line(a[i], en);
			id = i;
		}
	}
	cout << fixed << s << "\n";
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("epic.in", "r", stdin); freopen("epic.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}