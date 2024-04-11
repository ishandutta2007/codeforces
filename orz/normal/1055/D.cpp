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
#include <climits>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<pll> vpll;
typedef vector<ll> vl;
typedef pair<bool, ll> pbl;
typedef vector<pbl> vpbl;
typedef vector<double> vd;
typedef vector<pdd> vpdd;

template<typename A>
istream& operator>>(istream& fin, vector<A>& v)
{
	int n = sz(v);
	for (int i = 0; i < n; ++i)
		fin >> v[i];
	return fin;
}

template<typename A, typename B>
istream& operator>>(istream& fin, pair<A, B>& p)
{
	fin >> p.X >> p.Y;
	return fin;
}

template<typename A, typename B>
pair<A, B> operator+(const pair<A, B>& a, const pair<A, B>& b)
{
	return mp(a.X + b.X, a.Y + b.Y);
}

template<typename A, typename B>
pair<A, B> operator+=(pair<A, B>& a, const pair<A, B>& b)
{
	a.X += b.X;
	a.Y += b.Y;
	return a;
}

template<typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a, const pair<A, B>& b)
{
	return mp(a.X - b.X, a.Y - b.Y);
}

template<typename A, typename B>
pair<A, B> operator-(const pair<A, B>& a)
{
	return mp(-a.X, -a.Y);
}

template<typename A, typename B>
pair<A, B> operator-=(pair<A, B>& a, const pair<A, B>& b)
{
	a.X -= b.X;
	a.Y -= b.Y;
	return a;
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

// nestrogo protiv chasovoj strelki
template<typename A>
bool nprcs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) >= 0);
}

template<typename A>
bool nprcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return nprcs(a - b, a - c);
}

// nestrogo po chasovoj strelke
template<typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) <= 0);
}

template<typename A>
bool npocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return npocs(a - b, a - c);
}

// strogo protiv chasovoj strelki
template<typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) > 0);
}

template<typename A>
bool prcs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return prcs(a - b, a - c);
}

// strogo po chasovoj strelke
template<typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& c)
{
	return ((a % c) < 0);
}

template<typename A>
bool pocs(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return pocs(a - b, a - c);
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
pair<A, A> rot_90(const pair<A, A>& p)
{
	return mp(-p.Y, p.X);
}

template<typename A>
pair<A, A> rot_90(const pair<A, A>& p, const pair<A, A>& c)
{
	return c + rot_90(p - c);
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
	pair<A, A> p = b - a;
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
	return ints(p1.X, p1.Y, p2.X, p2.Y);
}

template<typename A>
pair<pair<A, A>, A> l_th_2(const pair<A, A>& p, const pair<A, A>& q)
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
bool on_segment(const pair<A, A>& a, const pair<A, A>& b, const pair<A, A>& c)
{
	return are_codirected(b - a, c - b);
}
template<typename A>
pair<pair<A, A>, A> perpendicular(const pair<A, A>& line, const pair<A, A>& point)
{
	return line_with_normal_vector_through_point(rot_90(line), point);
}
pdd projection(const pair<pdd, double>& line, const pdd& point)
{
	pair<pdd, double> temp = perpendicular(line.X, point);
	return ints(line.X, line.Y, temp.X, temp.Y);
}
pdd height(const pdd& a, const pdd& b, const pdd& c)
{
	return projection(l_th_2(a, c), b);
}
template<typename T>
vi z_function(const vector<T>& s)
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

// comparator of {angle, distance}
template<typename A>
bool angdis_cmp(const pair<A, A>& a, const pair<A, A>& b)
{
	A p;
	if (p = a % b)
		return (p > 0);
	else
		return sq_len(a) < sq_len(b);
}

template<typename T>
int find_min_idx(const vector<T>& v)
{
	int ans = 0, n = sz(v);
	for (int i = 1; i < n; ++i)
		if (v[i] < v[ans])
			ans = i;
	return ans;
}



// indices of convex hull vertices in counterclockwise order, starting from the bottom of leftmost
template<typename T>
vi convex_hull(vector<pair<T, T>>& a)
{
	int n = sz(a);
	if (n)
	{
		int mt = find_min_idx(a);
		pair<T, T> d = a[mt];
		for (int i = 0; i < n; ++i)
			a[i] -= d;

		vi idx(n);
		for (int i = 0; i < n; ++i)
			idx[i] = i;
		sort(idx.begin(), idx.end(), [&](const int& l, const int& r) {return angdis_cmp(a[l], a[r]); });

		vi h(1, idx.front());
		for (auto it = idx.begin() + 1; it != idx.end(); ++it)
		{
			auto temp = a.begin() + *it;
			if (sz(h) >= 2)
			{
				if (are_parallel(a[h.back()], *temp))
					h.pop_back();
				while ((sz(h) >= 3) && npocs(a[h[sz(h) - 2]], a[h.back()], *temp))
					h.pop_back();
			}
			h.push_back(*it);
		}

		for (int i = 0; i < n; ++i)
			a[i] += d;
		return h;
	}
	else
		return vi();
}

void dfs(const int& v, const vvi& g, vb& nv)
{
	nv[v] = false;
	for (int i = 0; i < sz(g[v]); ++i)
		if (nv[g[v][i]])
			dfs(g[v][i], g, nv);
}

struct dsu
{
	int n, k;
	vi r, p;
	dsu(const int& n) : n(n) {}
	void init()
	{
		k = n;
		r.resize(n);
		p.resize(n);
		for (int i = 0; i < n; ++i)
			p[i] = i;
	}
	int find_set(const int& a)
	{
		if (a == p[a])
			return a;
		else
			return p[a] = find_set(p[a]);
	}
	void union_sets(int a, int b)
	{
		a = find_set(a), b = find_set(b);
		if (a != b)
		{
			--k;
			if (r[a] < r[b])
				swap(a, b);
			p[b] = a;
			if (r[a] == r[b])
				++r[a];
		}
	}
};

ll gcd(ll a, ll b)
{
	a = abs(a); b = abs(b);
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}
ll inters(const ll& x1, const ll& x2, const ll& y1, const ll& y2)
{
	return max(0ll, min(x2, y2) - max(x1, y1));
}

bool coin(const string& s1, const int& l1, const int& r1,
	const string& s2, const int& l2, const int& r2)
{
	if ((r1 - l1) != (r2 - l2))
		return false;
	for (int i1 = l1, i2 = l2; i1 < r1; ++i1, ++i2)
		if (s1[i1] != s2[i2])
			return false;
	return true;
}

string change(const string& s, const string& ren1, const string& ren2)
{
	int k = sz(ren1);
	int n = sz(s);
	vector<char> summm(k + n);
	for (int i = 0; i < k; ++i)
		summm[i] = ren1[i];
	for (int i = 0; i < n; ++i)
		summm[i + k] = s[i];
	auto z = z_function(summm);
	string ans = s;
	int pos = 0;
	while ((pos < sz(s)) && (z[k + pos] < k))
		++pos;
	if (pos != sz(s))
		for (int i = 0; i < k; ++i)
			ans[pos + i] = ren2[i];
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int n;
	cin >> n;
	vector<string> w(n), x(n);
	vpii nes(n, pii(-1, -1));
	vi li;
	cin >> w >> x;
	for (int i = 0; i < n; ++i)
	{
		int f = 0;
		while ((f < sz(w[i])) && (w[i][f] == x[i][f]))
			++f;
		if (f < sz(w[i]))
		{
			li.pb(i);
			int s = sz(w[i]) - 1;
			while ((s >= 0) && (w[i][s] == x[i][s]))
				--s;
			nes[i].X = f;
			nes[i].Y = s + 1;
		}
	}
	int l = sz(li);
	for (int i = 1; i < l; ++i)
		if (!coin(w[li[i]], nes[li[i]].X, nes[li[i]].Y,
			w[li[i - 1]], nes[li[i - 1]].X, nes[li[i - 1]].Y))
		{
			cout << "NO\n";
			return 0;
		}
	for (int i = 1; i < l; ++i)
		if (!coin(x[li[i]], nes[li[i]].X, nes[li[i]].Y,
			x[li[i - 1]], nes[li[i - 1]].X, nes[li[i - 1]].Y))
		{
			cout << "NO\n";
			return 0;
		}
	bool ok = true;
	while (ok)
	{
		if (nes[li[0]].X == 0)
			ok = false;
		for (int i = 1; i < l; ++i)
			if ((nes[li[i]].X == 0) || (nes[li[i - 1]].X == 0) ||
				(w[li[i]][nes[li[i]].X - 1] != w[li[i - 1]][nes[li[i - 1]].X - 1]))
				ok = false;
		if (ok)
			for (int i = 0; i < l; ++i)
				--nes[li[i]].X;
	}
	ok = true;
	while (ok)
	{
		if (nes[li[0]].Y == sz(w[li[0]]))
			ok = false;
		for (int i = 1; i < l; ++i)
			if ((nes[li[i]].Y == sz(w[li[i]])) || (nes[li[i - 1]].Y == sz(w[li[i - 1]])) ||
				(w[li[i]][nes[li[i]].Y] != w[li[i - 1]][nes[li[i - 1]].Y]))
				ok = false;
		if (ok)
			for (int i = 0; i < l; ++i)
				++nes[li[i]].Y;
	}
	string ren1, ren2;
	for (int i = nes[li[0]].X; i < nes[li[0]].Y; ++i)
	{
		ren1.pb(w[li[0]][i]);
		ren2.pb(x[li[0]][i]);
	}
	for (int i = 0; i < n; ++i)
		if (change(w[i], ren1, ren2) != x[i])
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";
	cout << ren1 << '\n' << ren2 << '\n';
	return 0;
}