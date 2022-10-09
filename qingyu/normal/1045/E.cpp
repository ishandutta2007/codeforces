#include <bits/stdc++.h>

const int N = 1e6 + 50;

int n, f[N];

inline int find(int x)
{
	while (x != f[x])
		x = f[x] = f[f[x]];
	return x;
}


struct point_t
{
	int x, y, c, id;

	point_t() = default;

	point_t(int x, int y, int c = -1, int id = -1) : x(x), y(y), c(c), id(id)
	{}

	inline bool operator<(const point_t &rhs) const
	{
		if (x != rhs.x) return x < rhs.x;
		return y < rhs.y;
	}

	inline bool operator==(const point_t &rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	inline bool operator!=(const point_t &rhs) const
	{
		return !operator==(rhs);
	}
};

inline int dot(const point_t &u, const point_t &v)
{ return u.x * v.x + u.y * v.y; }

inline int cross(const point_t &u, const point_t &v)
{ return u.x * v.y - u.y * v.x; }

inline point_t operator+(const point_t &u, const point_t &v)
{ return point_t(u.x + v.x, u.y + v.y); }

inline point_t operator-(const point_t &u, const point_t &v)
{ return point_t(u.x - v.x, u.y - v.y); }

std::vector<point_t> pts;
std::vector<std::tuple<int, int> > answer;

inline void connect(const point_t &u, const point_t &v)
{
	assert(u.c == v.c);
	int x = find(u.id), y = find(v.id);
	if (x != y)
	{
		answer.emplace_back(u.id, v.id);
		f[x] = y;
	}
}

inline std::vector<point_t> convex_hull(std::vector<point_t> &p)
{
	static int st[N], top;
	static bool vis[N];
	std::sort(p.begin(), p.end());
	st[top = 1] = 0;
	for (int i = 1; i < p.size(); ++i)
	{
		while (top >= 2 && cross(p[st[top]] - p[st[top - 1]], p[i] - p[st[top]]) <= 0)
			vis[st[top--]] = false;
		vis[st[++top] = i] = true;
	}
	int cur = top;
	for (int i = (int) pts.size() - 2; i >= 0; --i)
	{
		if (!vis[i])
		{
			while (top > cur && cross(p[st[top]] - p[st[top - 1]], p[i] - p[st[top]]) <= 0)
				vis[st[top--]] = false;
			vis[st[++top] = i] = true;
		}
	}
	std::vector<point_t> res;
	for (int i = 1; i < top; ++i) res.push_back(p[st[i]]);
	return res;
}

inline bool on_segment(const point_t &P, const point_t &Q1, const point_t &Q2)
{
	return cross(Q1 - P, Q2 - P) == 0 && dot(Q1 - P, Q2 - P) <= 0;
}

inline bool same_color(const std::vector<point_t> &rhs)
{
	if (rhs.size() <= 1) return true;
	int c = rhs.at(0).c;
	for (auto &p : rhs)
		if (c != p.c)
			return false;
	return true;
}

inline const point_t *find_different(const std::vector<point_t> &rhs)
{
	if (rhs.size() <= 1) return nullptr;
	int c = rhs.at(0).c;
	for (auto &p : rhs)
		if (c != p.c)
			return &p;
	return nullptr;
}

inline const point_t *find_color(const std::vector<point_t> &rhs, int target)
{
	for (auto &p : rhs)
		if (p.c == target)
			return &p;
	return nullptr;
}

struct triangle_t
{
	point_t A, B, C;

	triangle_t(const point_t &A, const point_t &B, const point_t &C) : A(A), B(B), C(C)
	{}

	inline bool same_color() const
	{
		return A.c == B.c && A.c == C.c;
	}

	inline bool inside(const point_t &P) const
	{
		point_t PA = A - P, PB = B - P, PC = C - P;
		int t1 = cross(PA, PB), t2 = cross(PB, PC), t3 = cross(PC, PA);
		return (t1 >= 0 && t2 >= 0 && t3 >= 0) || (t1 <= 0 && t2 <= 0 && t3 <= 0);
	}
};

void solve_triangle(const std::vector<point_t> &, const triangle_t &);

void reconstruct(const point_t *p, const std::vector<point_t> pts, const triangle_t &r)
{
	triangle_t C1{r.A, r.B, *p}, C2{r.A, r.C, *p}, C3{r.B, r.C, *p};
	std::vector<point_t> V1, V2, V3;
	for (auto &pz : pts)
	{
		if (pz != *p && pz != r.A && pz != r.B && pz != r.C)
		{
			int x1 = C1.inside(pz), x2 = C2.inside(pz), x3 = C3.inside(pz);
			assert(x1 + x2 + x3 == 1);
			if (x1) V1.push_back(pz);
			if (x2) V2.push_back(pz);
			if (x3) V3.push_back(pz);
		}
	}
	solve_triangle(V1, C1);
	solve_triangle(V2, C2);
	solve_triangle(V3, C3);
}


void solve_triangle(const std::vector<point_t> &pts, const triangle_t &r)
{
	if (pts.empty())
	{
		if (r.same_color())
		{
			connect(r.A, r.B);
			connect(r.A, r.C);
		}
		else
		{
			if (r.A.c == r.B.c) connect(r.A, r.B);
			else if (r.A.c == r.C.c) connect(r.A, r.C);
			else connect(r.B, r.C);
		}
	}
	else if (r.same_color())
	{
		int t = !r.A.c;
		const point_t *p = find_color(pts, t);
		if (p == nullptr)
		{
			connect(r.A, r.B);
			connect(r.A, r.C);
			for (auto &p : pts) connect(p, r.A);
		}
		else
		{
			reconstruct(p, pts, r);
		}
	}
	else
	{
		int t = r.A.c ^ r.B.c ^ r.C.c;
		const point_t *p = find_color(pts, t);
		if (p == nullptr)
		{
			if (r.A.c == r.B.c) connect(r.A, r.B);
			else if (r.A.c == r.C.c) connect(r.A, r.C);
			else connect(r.B, r.C);
			const point_t &p0 = pts.at(0);
			point_t q;
			if (r.A.c == p0.c) q = r.A;
			else if (r.B.c == p0.c) q = r.B;
			else q = r.C;
			assert(q.c == p0.c);
			for (auto &p : pts)
			{
				connect(p, q);
			}
		}
		else
		{
			reconstruct(p, pts, r);
		}
	}
}

bool solve(const std::vector<point_t> &P)
{
	if (P.empty()) return true;
	int diff = 0;
	for (int i = 0; i < P.size(); ++i)
	{
		auto &p = P[i], &q = P[(i + 1) % P.size()];
		if (p.c != q.c) ++diff;
	}
	if (diff > 2) return false;
	if (P.size() == 3)
	{
		std::vector<point_t> src;
		for (auto &q : pts)
		{
			if (q != P[0] && q != P[1] && q != P[2])
			{
				src.push_back(q);
			}
		}
		solve_triangle(src, {P[0], P[1], P[2]});
	}
	else if (same_color(P))
	{
		static bool vis[N];
		memset(vis, 0, sizeof vis);
		std::vector<triangle_t> vec;
		std::vector<std::vector<point_t>> vp;
		const point_t *p = find_color(pts, !P[0].c);
		if (p == nullptr)
		{
			for (int i = 1; i < pts.size(); ++i) connect(pts[0], pts[i]);
		}
		else
		{
			vis[p->id] = true;
			for (int i = 0; i < P.size(); ++i)
			{
				vis[P[i].id] = true;
				vec.emplace_back(P[i], P[(i + 1) % P.size()], *p);
			}
			vp.resize(vec.size());
			for (auto &p : pts)
			{
				if (!vis[p.id])
				{
					for (int i = 0; i < vec.size(); ++i)
					{
						if (vec[i].inside(p))
						{
							vp[i].push_back(p);
							break;
						}
					}
				}
			}
			for (int i = 0; i < vec.size(); ++i)
			{
				solve_triangle(vp[i], vec[i]);
			}
		}
	}
	else
	{
		static bool vis[N];
		memset(vis, 0, sizeof vis);
		std::vector<triangle_t> vec;
		std::vector<std::vector<point_t>> vp;
		std::vector<int> breakpoints(2);
		int cnt = 0;
		for (int i = 0; i < P.size(); ++i)
		{
			vis[P[i].id] = true;
			if (P[i].c != P[(i + 1) % P.size()].c)
			{
				breakpoints[P[i].c] = i;
			}
		}
		for (int i = 0; i < P.size(); ++i)
		{
			int x = i, y = (i + 1) % P.size();
			if (P[x].c == P[y].c)
			{
				auto A = P[x], B = P[y], C = P[breakpoints[!P[x].c]];
//				printf("New Triangle (%d, %d) - (%d, %d) - (%d, %d)\n", A.x, A.y, B.x, B.y, C.x, C.y);
				vec.emplace_back(A, B, C);
			}
		}
		vp.resize(vec.size());
		for (auto &p : pts)
		{
			if (!vis[p.id])
			{
				for (int i = 0; i < vec.size(); ++i)
				{
					if (vec[i].inside(p))
					{
						vp[i].push_back(p);
						break;
					}
				}
			}
		}
		for (int i = 0; i < vec.size(); ++i)
		{
			solve_triangle(vp[i], vec[i]);
		}
	}
	std::sort(answer.begin(), answer.end());
	answer.erase(std::unique(answer.begin(), answer.end()), answer.end());
	return true;
}

template<int T>
struct fast_io
{
	char p[T], q[T], *p1, *p2, *q1, *q2;

	fast_io()
	{
		p1 = p2 = p;
		q1 = q, q2 = q + T;
	}

	inline char gc()
	{
		return p1 == p2 && (p2 = (p1 = p) + fread(p, 1, T, stdin), p1 == p2) ? EOF : *p1++;
	}

	inline void pc(char c)
	{
		if (q1 == q2) q2 = (q1 = q) + fwrite(q, 1, T, stdout);
		*q1++ = c;
	}

	~fast_io()
	{
		fwrite(q, 1, q1 - q, stdout);
	}
};

fast_io<1 << 20> io;

inline int64_t read()
{
	int64_t res = 0, neg = 1;
	char ch;
	do
	{
		ch = io.gc();
		if (ch == '-') neg = -1;
	} while (ch < 48 || ch > 57);
	do res = res * 10 + ch - 48, ch = io.gc(); while (ch >= 48 && ch <= 57);
	return res * neg;
}

inline void put(int64_t x)
{
	if (x < 0) io.pc('-'), x = -x;
	if (x >= 10) put(x / 10);
	io.pc(48 + x % 10);
}

inline void output(int64_t x, char ch = ' ')
{
	put(x);
	io.pc(ch);
}

int main()
{
	n = read();
	for (int i = 1; i <= n; ++i)
	{
		int x = read(), y = read(), c = read();
		pts.emplace_back(x, y, c, i);
		f[i] = i;
	}
	auto r = convex_hull(pts);
	bool t = solve(r);
	if (t == 0)
	{
		puts("Impossible");
	}
	else
	{
		output(answer.size(), '\n');
		for (auto &[x, y] : answer)
		{
			output(x - 1);
			output(y - 1, '\n');
		}
	}
	return 0;
}