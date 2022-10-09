#include <bits/stdc++.h>

typedef long double T;
const T eps = 1e-10;
using namespace std;

struct pt
{
	T x, y;
	pt (T x = 0.0, T y = 0.0) : x(x), y(y) { }
	pt operator+(const pt &z) const { return pt(x + z.x, y + z.y); }
	pt operator-(const pt &z) const { return pt(x - z.x, y - z.y); }
	pt operator*(const T k) const { return pt(x * k, y * k); }
	pt operator/(const T k) const { return pt(x / k, y / k); }
	bool operator==(const pt &z) const
	{
		return x == z.x && y == z.y;
	}
	bool operator!=(const pt &z) const
	{
		return x != z.x || y != z.y;
	}
	bool operator<(const pt &z) const
	{
		return make_pair(x, y) < make_pair(z.x, z.y);
	}
};
typedef std::vector<pt> pl;

pt operator*(const T k, const pt &z) { return pt(z.x * k, z.y * k); }
pt operator/(const T k, const pt &z) { return pt(z.x / k, z.y / k); }

inline int dcmp(const T x)
{
	if (x > eps) return 1;
	if (x < -eps) return -1;
	return 0;
}
std::istream& operator>>(std::istream &inf, pt &p)
{
	return inf >> p.x >> p.y;
}

std::ostream& operator<<(std::ostream &ouf, const pt &p)
{
	return ouf << p.x << " " << p.y;
}

inline T dot(const pt &a, const pt &b) 
{
	return a.x * b.x + a.y * b.y;
}
inline T cross(const pt &a, const pt &b)
{
	return a.x * b.y - a.y * b.x;
}
inline pt midpoint(const pt &a, const pt &b)
{
	return (a + b) / 2.0;
}
inline T sq(const pt &a)
{
	return a.x * a.x + a.y * a.y;
}
inline T abs(const pt &a)
{
	return sqrtl(sq(a));
}
inline pt perp(const pt &p)
{
	return pt(-p.y, p.x);
}

struct ln
{
	pt v; T c;
	ln(pt v, T c) : v(v), c(c) { } // direction vector + offset
	ln(T a, T b, T c) : v({b, -a}), c(c) { } // ax + by = c
	ln(pt p, pt q) : v(q - p), c(cross(v, p)) { } // p, q
	T side(const pt &p) const
	{
		return cross(v, p) - c;
	}
	T dist(const pt &p) const
	{
		return abs(side(p)) / abs(v);
	}
	T sqDist(const pt &p) const
	{
		return side(p) * side(p) / sq(v);
	}
	ln perpThough(const pt &p) const
	{
		return ln(p, p + perp(v));
	}
	pt proj(const pt &p) const
	{
		T k = -side(p) / sq(v);
		return p + k * perp(v);
	}
	pt refl(const pt &p) const
	{
		T k = -2 * side(p) / sq(v);
		return p + k * perp(v);
	}
	bool cmpProj(const pt &p, const pt &q) const
	{
		return dot(v, p) < dot(v, q);
	}
};
inline bool inter(const ln &l1, const ln &l2, pt &out)
{
	T d = cross(l1.v, l2.v);
	if (dcmp(d) == 0) return false;
	out = (l1.c * l2.v - l1.v * l2.c) / d;
	return true;
}

// a, b, c clockwise <=> < 0
// a, b, c counter-clockwise <=> > 0
inline T orient(const pt &a, const pt &b, const pt &c)
{
	return cross(b - a, c - a);
}

inline ln bisector(const ln &l1, const ln &l2, bool interior = true)
{
	double sign = interior ? 1 : -1;
	return { l2.v / abs(l2.v) + l1.v / abs(l1.v) * sign, 
       		l2.c / abs(l2.v) + l1.c / abs(l1.v) * sign};
}

inline bool inDisk(const pt &a, const pt &b, const pt &p)
{
	return dot(a - p, b - p) <= 0;
}

inline bool onSegment(const pt &a, const pt &b, const pt &p)
{
	return dcmp(orient(a, b, p)) == 0 && inDisk(a, b, p);
}

inline bool properInter(const pt &a, const pt &b, const pt &c, const pt &d, pt &out)
{
	T oa = orient(c, d, a), ob = orient(c, d, b), oc = orient(a, b, c), od = orient(a, b, d);
	if (oa * ob < 0 && oc * od < 0)
	{
		out = (a * ob - b * oa) / (ob - oa);
		return true;
	}
	return false;
}

inline T segPoint(const pt &a, const pt &b, const pt &p)
{
	if (a != b)
	{
		ln l(a, b);
		if (l.cmpProj(a, p) && l.cmpProj(p, b))
			return l.dist(p);
	}
	return std::min(abs(p - a), abs(p - b));
}

inline T segSeg(const pt &a, const pt &b, const pt &c, const pt &d)
{
	pt dummy;
	if (properInter(a, b, c, d, dummy)) return 0;
	return std::min({ segPoint(a, b, c), segPoint(a, b, d), segPoint(c, d, a), segPoint(c, d, b) });
}

inline pt incenter(const pt &p1, const pt &p2, const pt &p3)
{
	ln l1(p1, p2), l2(p1, p3), l3(p3, p2);
	ln a = bisector(l1, l2), b = bisector(l1, l3);
	pt bar;
	assert(inter(a, b, bar));
	return bar;
}

inline pt circumcenter(const pt &p1, const pt &p2, const pt &p3)
{
	const ln &l1 = ln(p1, p2).perpThough(midpoint(p1, p2));
	const ln &l2 = ln(p1, p3).perpThough(midpoint(p1, p3));
	pt bar; assert(inter(l1, l2, bar));
	return bar;
}

inline T areaPolygon(pl p)
{
	T area = 0.0;
	for (int i = 0, n = p.size(); i < n; ++i)
	{
		area += cross(p[i], p[(i + 1) % n]);
	}
	return abs(area) / 2.0;
}

inline bool above(const pt &a, const pt &b)
{
	return a.y >= b.y;
}

inline bool crossesRay(const pt &a, const pt &p, const pt &q)
{
	return (above(a, q) - above(a, p)) * orient(a, p, q) > 0;
}

inline bool inPolygon(pl p, const pt &a, bool strict = true)
{
	int c = 0;
	for (int i = 0, n = p.size(); i < n; ++i)
	{
		if (onSegment(p[i], p[(i + 1) % n], a))
			return !strict;
		c ^= crossesRay(a, p[i], p[(i + 1) % n]);
	}
	return c & 1;
}

inline std::vector<pt> convexHull(pl p)
{
	if (p.size() <= 2) return p;
	std::sort(p.begin(), p.end(), [&](const pt &x, const pt &y) { return x.x == y.x ? x.y < y.y : x.x < y.x; });
	std::vector<int> st, vis(p.size());
	st.push_back(0);	
	for (int i = 1; i < p.size(); ++i)
	{
		
		while (st.size() > 1 && orient(p[st[st.size() - 2]], p[st[st.size() - 1]], p[i]) < 0) vis[st.back()] = false, st.pop_back();
		st.push_back(i); vis[i] = true;
	}
	int cur = st.size();
	for (int i = p.size() - 2; i >= 0; --i)
	{
		if (!vis[i])
		{
			while (st.size() > cur && orient(p[st[st.size() - 2]], p[st[st.size() - 1]], p[i]) < 0) vis[st.back()] = false, st.pop_back();
			st.push_back(i); vis[i] = true;
		}
	}
	std::vector<pt> res;
	for (int i = 0; i < st.size() - 1; ++i) res.push_back(p[st[i]]);
	return res;
}

inline T convexDiameter(pl p)
{
	if (p.size() <= 1) return 0;
	int i0 = 0, j0 = 0, n = p.size();
	auto cmp = [&](const pt &a, const pt &b) 
	{
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	};
	for (int i = 1; i < n; ++i)
	{
		if (cmp(p[i0], p[i])) i0 = i;
		if (cmp(p[i], p[j0])) j0 = i;
	}
	int i = i0, j = j0; T d = 0.0;
	do
	{
		d = std::max(d, abs(p[i] - p[j]));
		if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0) i = (i + 1) % n;
		else j = (j + 1) % n;
	} while (i != i0 || j != j0);
	return d;
}

struct cr
{
	T r; pt o;
	cr(pt o, T r) : r(r), o(o) {}
};


inline int circleLine(const cr &C, const ln &l, std::pair<pt, pt> &out)
{
	T h2 = C.r * C.r - l.sqDist(C.o);
	if (dcmp(h2) >= 0)
	{
		pt p = l.proj(C.o), h = l.v / abs(l.v) * sqrt(h2);
		out = std::make_pair(p - h, p + h);
	}
	return 1 + dcmp(h2);
}

inline int circleCircle(const cr &C1, const cr &C2, std::pair<pt, pt> &out)
{
	pt d = C2.o - C1.o; T d2 = sq(d);
	if (dcmp(d2) == 0)
	{
		assert(dcmp(C1.r - C2.r) != 0);
		return 0;
	}
	T pd = (d2 + C1.r * C1.r - C2.r * C2.r) / 2, h2 = C1.r * C1.r - pd * pd / d2;
	if (h2 >= 0)
	{
		pt p = C1.o + d * pd / d2, h = perp(d) * sqrt(h2 / d2);
		out = std::make_pair(p - h , p + h);
	}
	return 1 + dcmp(h2);
}

inline int tangents(cr C1, cr C2, bool inner, std::vector<std::pair<pt, pt>> &out)
{
	if (inner) C2.r = -C2.r;
	pt d = C2.o - C1.o;
	T dr = C1.r - C2.r, d2 = sq(d), h2 = d2 - dr * dr;
	if (dcmp(d2) == 0 || dcmp(h2) == -1)
	{
		assert(dcmp(h2) != 0);
		return 0;
	}
	for (double k : {-1, 1})
	{
		pt v = (d * dr + perp(d) * sqrtl(h2) * k) / d2;
		out.emplace_back(C1.o + v * C1.r, C2.o + v * C2.r);
	}
	return 1 + (dcmp(h2) > 0);
}

inline pl convexCut(const pl &P, const pt &p1, const pt &p2)
{
	pl res;
	for (int i = 0, n = P.size(); i < n; ++i)
	{
		const pt &x = P[i], &y = P[(i + 1) % n];
		T a = orient(x, p1, p2), b = orient(y, p1, p2);
		if (dcmp(a) >= 0) // lies in a line or counter-clockwise
		{
			res.push_back(x);
		}
		if (dcmp(a * b) < 0)
		{
			pt dummy; 
			inter(ln(x, y), ln(p1, p2), dummy);
			res.emplace_back(dummy);
		}
	}
	return res;
}

const int N = 1e6 + 50;
int n, k, a[N], b[N];
pt p[N];

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cout << std::fixed << std::setprecision(15);
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{	
		cin >> a[i] >> b[i];
		p[i] = pt(a[i], b[i]);
	}
	if (n == 3)
	{
		pt x(a[1], b[1]);
		pt y(a[2], b[2]);
		pt z(a[3], b[3]);
		T ans = 1e18;
		if (k == 1)
		{
			ans = min(abs(x - y) + abs(y - z), abs(x - z) + abs(z - y));
		}
		else if (k == 2)
		{
			ans = min(abs(y - x) + abs(x - z), abs(y - z) + abs(z - x));
		}
		else if (k == 3)
		{
			ans = min(abs(z - x) + abs(x - y), abs(z - y) + abs(y - x));
		}
		else throw;
		cout << ans;
		return 0;
	}
	int x1 = -1, x2 = -1, x3 = -1;
	for (int i = 1; i <= 4; ++i)
		for (int j = i + 1; j <= 4; ++j)
			for (int k = j + 1; k <= 4; ++k)
				if (dcmp(cross(p[j] - p[i], p[k] - p[i])) == 0)
				{
					x1 = i, x2 = j, x3 = k;
				}
	if (x1 == -1) throw "WTF?";
	ln l(p[x1], p[x2]);
	int op = -1;
	vector<pt> pol;
	for (int i = 1; i <= n; ++i)
		if (dcmp(cross(p[i] - p[x1], p[i] - p[x2])) != 0)
		{
			assert(op == -1);
			op = i;
		}
		else pol.push_back(p[i]);
	sort(pol.begin(), pol.end(), [&](const pt &x, const pt &y)
	{
		return make_pair(x.x, x.y) < make_pair(y.x, y.y);
	});
	pt L = *pol.begin(), R = pol.back();
	
	if (k == op)
	{
		T ans = 1e18;
		ans = min(abs(p[k] - L) + abs(L - R), abs(p[k] - R) + abs(L - R));
		cout << ans << endl;
	}
	else
	{
		pt start = p[k];
		auto it = lower_bound(pol.begin(), pol.end(), start);
		T ans = 1e18;	
		auto outp = p[op];
		if (it == pol.begin())
		{
			auto it2 = it; ++it2;
			ans = min(ans, abs(outp - start) + abs(*it2 - outp) + abs(R - *it2));
			ans = min(ans, abs(outp - start) + abs(R - outp) + abs(R - *it2));
			ans = min(ans, abs(R - start) + abs(outp - R));
			for (int i = 0; i + 1 < pol.size(); ++i)
			{
				ans = min(ans, abs(pol[i] - start) + abs(outp - pol[i]) + abs(outp - pol[i + 1]) + abs(R - pol[i + 1]));
				ans = min(ans, abs(pol[i] - start) + abs(outp - pol[i]) + abs(outp - R) + abs(R - pol[i + 1]));
			}
		}
		else if (*it == R)
		{	
			auto it2 = it; --it2;
			ans = min(ans, abs(outp - start) + abs(*it2 - outp) + abs(L - *it2));
			ans = min(ans, abs(outp - start) + abs(L - outp) + abs(L - *it2));
			ans = min(ans, abs(L - start) + abs(outp - L));
			for (int i = pol.size() - 1; i > 0; --i)
			{
				ans = min(ans, abs(pol[i] - start) + abs(outp - pol[i]) + abs(outp - pol[i - 1]) + abs(L - pol[i - 1]));
				ans = min(ans, abs(pol[i] - start) + abs(outp - pol[i]) + abs(outp - L) + abs(L - pol[i - 1]));
			}
		}
		else
		{
			auto pred = it, succ = it;
			--pred; ++succ;
			ans = min(ans, abs(outp - start) + abs(L - outp) + abs(L - R));
			ans = min(ans, abs(outp - start) + abs(R - outp) + abs(L - R));
			ans = min(ans, abs(L - start) + abs(L - outp) + abs(outp - *succ) + abs(*succ - R));
			ans = min(ans, abs(L - start) + abs(L - outp) + abs(outp - R) + abs(*succ - R));
			ans = min(ans, abs(R - start) + abs(R - outp) + abs(outp - *pred) + abs(*pred - L));
			ans = min(ans, abs(R - start) + abs(R - outp) + abs(outp - L) + abs(*pred - L));
			ans = min(ans, abs(L - start) + abs(L - R) + abs(R - outp));
			ans = min(ans, abs(R - start) + abs(L - R) + abs(L - outp));
			for (auto _it = it; *_it != R; ++_it)
			{
				auto s_it = _it; ++s_it;
				assert(s_it != pol.end());
				ans = min(ans, abs(L - start) + abs(L - *_it) + abs(*_it - outp) + abs(outp - *s_it) + abs(*s_it - R));
				ans = min(ans, abs(L - start) + abs(L - *_it) + abs(*_it - outp) + abs(outp - R) + abs(*s_it - R));
			}
			for (auto _it = it; _it != pol.begin(); --_it)
			{
				auto p_it = _it; --p_it;
				ans = min(ans, abs(R - start) + abs(R - *_it) + abs(*_it - outp) + abs(outp - *p_it) + abs(*p_it - L));
				ans = min(ans, abs(R - start) + abs(R - *_it) + abs(*_it - outp) + abs(outp - L) + abs(*p_it - L));
			}
		}
		cout << ans << endl;
	}

	//cout << "k = " << op << endl;
	//cout << L.x << " " << L.y << " | " << R.x << " " << R.y << endl;

	return 0;
}