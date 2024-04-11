
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define mp make_pair
#define gl getline
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x.size()))
#define UM unordered_map
#define US unordered_set
#define X first
#define Y second
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pll> vpll;
typedef vector<ll> vl;

template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	return fin;
}

template<typename A, typename B>
istream& operator>> (istream& fin, pair<A, B>& p)
{
	fin >> p.X >> p.Y;
	return fin;
}

template<typename A, typename B>
pair<A, B> operator+ (const pair<A, B>& a, const pair<A, B>& b)
{
	return mp(a.X + b.X, a.Y + b.Y);
}

template<typename A, typename B>
pair<A, B> operator- (const pair<A, B>& a, const pair<A, B>& b)
{
	return mp(a.X - b.X, a.Y - b.Y);
}

template<typename A, typename B>
pair<A, B> operator- (const pair<A, B>& a)
{
	return mp(-a.X, -a.Y);
}

template<typename A>
A operator*(const pair<A, A>& p, const pair<A, A>& q)
{
	return p.X * q.X + p.Y * q.Y;
}

template<typename A>
pair<A, A> operator*(const pair<A, A>& p, const A& q)
{
	return mp(p.X * q, p.Y * q);
}

template<typename A>
A operator%(const pair<A, A>& p, const pair<A, A>& q)
{
	return p.X * q.Y - p.Y * q.X;
}

template<typename A>
A sq_len(const pair<A, A>& p)
{
	return p * p;
}

template<typename A>
A sq_dist(const pair<A, A>& p, const pair<A, A>& q)
{
	return sq_len(p - q);
}

template<typename A>
double len(const pair<A, A>& p)
{
	return sqrt(sq_len(p));
}

template<typename A>
double dist(const pair<A, A>& p, const pair<A, A>& q)
{
	return len(p - q);
}

template<typename A>
bool is_rhombus(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	A x = sq_dist(a, b);
	A y = sq_dist(b, c);
	A z = sq_dist(c, d);
	A t = sq_dist(d, a);
	return ((x == y) && (y == z) && (z == t));
}

template<typename A>
bool is_rectangle(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b,
		y = b - c,
		z = c - d,
		t = d - a;
	return ((x * y == 0) && (y * z == 0) && (z * t == 0) && (t * x == 0));
}

template<typename A>
bool are_parallel(const pair<A, A>& a, const pair<A, A>& b)
{
	return (a % b == 0);
}

template<typename A>
bool are_orthogonal(const pair<A, A>& a, const pair<A, A>& b)
{
	return (a * b == 0);
}

template<typename A>
bool are_codirected(const pair<A, A>& a, const pair<A, A>& b)
{
	return (are_parallel(a, b) && (a * b >= 0));
}

template<typename A>
bool is_parallelogram(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	return ((a - b) == (d - c));
}

template<typename A>
bool is_trapezoid(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b, z = d - c;
	return are_codirected(x, z);
}

template<typename A>
bool is_convex_polygon(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = a - b,
		y = b - c,
		z = c - d,
		t = d - a;
	A p = x % y, q = y % z, r = z % t, s = t % x;
	return (((p >= 0) && (q >= 0) && (r >= 0) && (s >= 0)) ||
		((p <= 0) && (q <= 0) && (r <= 0) && (s <= 0)));
}

template<typename A>
bool npcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return (((b - a) % (b - c)) >= 0);
}

template<typename A>
bool different_sides(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p >= 0) && (q <= 0)) ||
		((p <= 0) && (q >= 0)));
}
template<typename A>
bool sharply_different_sides(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d)
{
	pair<A, A> x = b - a;
	A p = x % (c - b), q = x % (d - b);
	return (((p > 0) && (q < 0)) ||
		((p < 0) && (q > 0)));
}

template<typename A>
pair<A, A> rot_90(const pair<A, A> p)
{
	return mp(-p.Y, p.X);
}

template<typename A>
bool intersecting_segments(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) // true if two segs on one line
{
	return different_sides(a, b, c, d) && different_sides(c, d, a, b);
}
template<typename A>
bool sharply_intersecting_segments(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c, const pair<A, A>& d) // true if two segs on one line
{
	return sharply_different_sides(a, b, c, d) && sharply_different_sides(c, d, a, b);
}

template <typename A>
pair<pair<A, A>, A> line_with_normal_vector_through_point(const pair<A, A>& normal, const pair<A, A>& point)
{
	return mp(normal, -(normal * point));
}

template <typename A>
pair<pair<A, A>, A> serper(const pair<A, A>& a, const pair<A, A>& b)
{
	//pdd q = (a + b) * .5;
	//pdd p = b - a;
	//return line_with_normal_vector_through_point(p, q);
	////////// instead of (p, -(p * q)), we take (p * 2, -(p * (q * 2))
	pdd p = b - a;
	return mp(p + p, -(p * (a + b)));
}

pdd ints(const pdd& p, const double& a,
	const pdd& q, const double& b)
{
	double D = p % q;
	double E = pdd(-a, p.Y) % pdd(-b, q.Y);
	double F = pdd(p.X, -a) % pdd(q.X, -b);
	return pdd(E / D, F / D);
}

pdd circumcenter(const pdd& x, const pdd& y, const pdd& z)
{
	auto p1 = serper(x, y),
		p2 = serper(x, z);
	//cout << p1.X.X << ' ' << p1.X.Y << ' ' << p1.Y << '\n';
	return ints(p1.X, p1.Y, p2.X, p2.Y);
}

template<typename A>
pair <pair<A, A>, A> l_th_2(const pair<A, A>& p, const pair<A, A>& q)
{
	return mp(mp(q.Y - p.Y, p.X - q.X), -p % q);
}

template<typename A>
vector<pdd> circle_intersection(const pair<pair<A, A>, A>& a, const pair<pair<A, A>, A>& b)
{
	pair<A, A> c = b.X - a.X;
	A rr1 = a.Y * a.Y, rr2 = b.Y * b.Y, cc = c * c,
		rrrr1 = rr1 * rr1, rrrr2 = rr2 * rr2, cccc = cc * cc,
		D = 2 * (rr1 * rr2 + rr2 * cc + cc * rr1) - (rrrr1 + rrrr2 + cccc);
	if (D >= 0)
	{
		double E = (((double)(rr1 - rr2)) / cc + 1) / 2;
		pdd baza = pdd(a.X.X, a.X.Y) + pdd(c.X, c.Y) * E;
		if (D)
		{
			double lll = sqrt((double)(D)) / (2 * cc);
			pair<A, A> cr = rot_90(c);
			pdd pmm = pdd(cr.X, cr.Y) * lll;
			return{ baza + pmm, baza - pmm };
		}
		else
			return vector<pdd>(1, baza);
	}
	else
		return vector<pdd>();
}
template<typename A, typename B>
pair<A, B> sopr(const pair<A, B>& p)
{
	return mp(p.X, -p.Y);
}
template<typename A>
bool on_segment(const pair<A, A> a, const pair<A, A> b, const pair<A, A> c)
{
	return are_codirected(b - a, c - b);
}

vi z_function(const string& s)
{
	int n = sz(s);
	vi z(n);
	int l = 0, r = 1;
	for (int i = 1; i < n; ++i)
	{
		z[i] = max(0, min(r - i, z[i - l]));
		while (i + z[i] < n && (s[i + z[i]] == s[z[i]]))
			++z[i];
		if (r < i + z[i])
		{
			l = i;
			r = i + z[i];
		}
	}
	return z;
}
pii euc(const int& m, const int& n)
{
	if (n == 0)
		return pii((m >= 0) ? 1 : -1, 0);
	int t = m / n;
	pii ans1 = euc(n, m - t * n);
	return pii(ans1.Y, ans1.X - ans1.Y * t);
}

int prod(const int& a, const int& b, const int& M)
{
	return ((ll)(a)) * b % M;
}

int sum(const int& a, const int& b, const int& M)
{
	int c = a + b;
	return c >= M ? c - M : c;
}

int raz(const int& a, const int& b, const int& M)
{
	int c = a - b;
	return c < 0 ? c + M : c;
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a = 1, b = 1;
	while (a * b < n)
	{
		if (a == b)
			++a;
		else
			++b;
	}
	for (int i = 0; i < b; ++i)
	{
		// hotim [1 + i * a; (i + 1) * a]
		// mx + i * a <= n
		// mx <= n - i * a
		int mx = min(a, n - i * a);
		for (int j = mx; j >= 1; --j)
			cout << i * a + j << ' ';
	}
	cout << '\n';
	return 0;
}