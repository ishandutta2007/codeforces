// By Qingyu QAQ
#include <bits/stdc++.h>
 
const double pi = acos(-1.0);
const int N = 10;
 
struct Point 
{
	double x, y;
	Point(double x = 0, double y = 0) :x(x), y(y) 
	{
 
	}
};
typedef Point Vector;
Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }
Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }
Vector operator*(Vector a, double b) { return Vector(a.x*b, a.y*b); }
Vector operator/(Vector a, double b) { return Vector(a.x / b, a.y / b); }
 
const double eps = 1e-8;
int dcmp(double x)
{
	if (fabs(x) < eps) return 0;
	if (x < 0) return -1;
	return 1;
}
bool operator< (const Point &a, const Point &b)
{
	return dcmp(a.x - b.x) == -1 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == -1);
}
bool operator==(const Point &a, const Point &b)
{
	return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0; 
}
double Dot(Vector a, Vector b)
{
	return a.x*b.x + a.y*b.y;
}
double Length(Vector a)
{
	return sqrt(Dot(a, a));
}
double Angle(Vector a, Vector b)
{
	return acos(Dot(a, b) / Length(a) / Length(b));
}
double Cross(Vector a, Vector b)
{
	return a.x*b.y - a.y*b.x;
}
double Area2(Point a, Point b, Point c)
{
	return Cross(b - a, c - a);
}
Vector Rotate(Vector a, double rad)
{
	return Vector(a.x*cos(rad) - a.y*sin(rad), a.x*sin(rad) + a.y*cos(rad));
	
}
Vector Normal(Vector a)
{
	double L = Length(a);
	return Vector(-a.y / L, a.x / L);
}
struct Line {
	Point p;
	Vector v;
	Line(double px, double py, double ex, double ey) :p(px, py), v(ex - px, ey - py) {}
	Line(double px, double py, Point a) :
		p(px, py), v(a.x - px, a.y - py) {}
	Line(Point a, Point b) :
		p(a.x, b.x), v(b.x - a.x, b.y - a.y) {}
	Point point(int x) 
	{
		double t = (x - p.x) / v.x;
		return Point(x, p.y + t*v.y);
	}
};
Point GetLineIntersection(Point p, Vector v, Point q, Vector w)
{
	Vector u = p - q;
	double t = Cross(w, u) / Cross(v, w);
	return p + v*t;
}
double Distancetoline(Point p, Point a, Point b)
{
	Vector v1 = b - a, v2 = p - a;
	return fabs(Cross(v1, v2)) / Length(v1);
	 
}
double Distancetosegment(Point p, Point a, Point b)
{
	if (a == b) return Length(p - a);
	Vector v1 = b - a, v2 = p - a, v3 = p - b;
	if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
	if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
	return  fabs(Cross(v1, v2)) / Length(v1);
}
Point GetLineProjection(Point p, Point a, Point b)
{
	Vector v = b - a;
	return a + v*(Dot(v, p - a) / Dot(v, v));
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
	double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
		c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - a1);
	return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}
bool OnSegment(Point p, Point a1, Point a2)
{
	return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
struct Circle {
	Point c; 
	double r;
	Circle(Point c = Point(), double r = 0.0) :c(c), r(r) {}
	Point point(double rad)
	{
		return Point(c.x + cos(rad)*r, c.y + sin(rad)*r);
	}
} circ[N];
int getLineCircleIntersection(Line L, Circle C, double &t1, double &t2, std::vector<Point>& sol)
{
	double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
	double e = a*a + c*c, f = 2 * (a*b + c*d), g = b*b + d*d - C.r*C.r;
	double delta = f*f - 4 * e*g;
	if (dcmp(delta) < 0) return 0; 
	if (dcmp(delta) == 0)  
	{
		t1 = t2 = -f / (2 * e);
		sol.push_back(L.point(t1));
		return 1;
	}
	t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
	t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
	return 2;
}
double angle(Vector v) { return atan2(v.y, v.x); }
 
int getCircleCircleIntersection(Circle c1, Circle c2, std::vector<Point> &sol)
{
	double d = Length(c1.c - c2.c);
	if (dcmp(d) == 0)
	{
		if (dcmp(c1.r - c2.r) == 0) return -1;
		return 0;
	}
	if (dcmp(c1.r + c2.r - d) < 0) return 0;
	if (dcmp(fabs(c1.r - c2.r) - d) > 0) return 0;
	double a = angle(c2.c - c1.c);
	double da = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2 * c1.r*d));
	Point p1 = c1.point(a - da), p2 = c1.point(a + da);
	sol.push_back(p1);
	if (p1 == p2) return 1;
	sol.push_back(p2);
	return 2;
}
inline bool onCircle(Point P, Circle C)
{
	Point Q = P - C.c;
	return fabs(Length(Q) - C.r) < eps;
}
 
int n, f[N];
 
inline int find(int x)
{
	while (x != f[x]) x = f[x] = f[f[x]];
	return x;
}
 
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0); std::cout.tie(0);
	std::cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		f[i] = i;
		double x, y, r;
		std::cin >> x >> y >> r;
		circ[i].c = Point(x, y), circ[i].r = r;
	}
	int Count = n;
	std::set<Point> set;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j < i; ++j)
		{
			std::vector<Point> v;
			int c = getCircleCircleIntersection(circ[i], circ[j], v);
			for (int t = 0; t < c; ++t)
			{
				//printf("Circle #%d and #%d: (%.6f, %.6f)\n", i, j, v[t].x, v[t].y);
				int fi = find(i), fj = find(j);
				if (fi != fj)
				{
					--Count;
					f[fi] = fj;
				}
				if (set.count(v[t]) == 0) set.insert(v[t]);
			}
		}
	}
	int V = set.size(), E = 0;
	for (int i = 1; i <= n; ++i)
	{
		for (auto v : set)
		{
			if (onCircle(v, circ[i]))
			{
				++E;
			}
		}
	}
	printf("%d", 1 + Count - V + E);
	return 0;
}