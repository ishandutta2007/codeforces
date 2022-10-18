#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef double ld;

const ld eps = 1e-8;
const ld PI = atan2(0, -1);

struct Point
{
    ld x, y;
    Point():
        x(1),
        y(1) {}
    Point(ld x, ld y):
        x(x),
        y(y) {}
    Point operator+(Point a)
    {
        return Point(a.x + x, a.y + y);
    }
    Point operator-(Point a)
    {
        return Point(x - a.x, y - a.y);
    }
    ld operator^(Point a)
    {
        return x * a.y - y * a.x;
    }
    ld operator*(Point a)
    {
        return x * a.x + y * a.y;
    }
    Point operator*(ld a)
    {
        return Point(x * a, y * a);
    }
    Point operator/(ld a)
    {
        return Point(x / a, y / a);
    }
    ld len()
    {
        return sqrtf(x * x + y * y);
    }
    ld dist(Point a)
    {
        return sqrtf((a.x - x) * (a.x - x) + (a.y - y) * (a.y - y));
    }
    bool operator<(Point a)
    {
        return y + eps < a.y || (fabs(y - a.y) < eps && x + eps < a.x);
    }
    bool operator>(Point a)
    {
        return y > a.y + eps || ((y - a.y) < eps && x > a.x + eps);
    }
    bool operator==(Point a)
    {
        return fabs(a.y - y) < eps && fabs(a.x - x) < eps;
    }
    bool operator!=(Point a)
    {
        return fabs(a.y - y) > eps || fabs(a.x - x) > eps;
    }
};

struct Line
{
    ld a, b, c;
    Line():
        a(1),
        b(1),
        c(0) {}
    Line(ll a, ll b, ll c):
        a(a),
        b(b),
        c(c) {}
    Line(Point a, Point b):
        a(a.y - b.y),
        b(b.x - a.x),
        c((b.y - a.y) * a.x + (a.x - b.x) * a.y) {}
    ld len()
    {
        return sqrtf(a * a + b * b);
    }
    ld operator()(Point p)
    {
        return a * p.x + b * p.y + c;
    }
    void norm()
    {
        ld z = sqrtf(a * a + b * b);
        if (z > eps)
        {
            a /= z;
            b /= z;
            c /= z;
        }
    }
    Point cross(Line l)
    {
        return Point(-(b * l.c - l.b * c) / (b * l.a - l.b * a), -(a * l.c - l.a * c) / (a * l.b - l.a * b));
    }
    bool parallel(Line l)
    {
        return fabs(l.a * b - l.b * a) < eps;
    }
    ld dist(Point p)
    {
        return fabs(p.x * a + p.y * b + c) / sqrtf(a * a + b * b);
    }
    ld dir(Point p)
    {
        return p.x * a + p.y * b + c;
    }
    bool lies(Point p)
    {
        return fabs(a * p.x + b * p.y + c) < eps;
    }
    Line perpendicular()
    {
        return Line(-b, a, 0);
    }
    Line perpendicular(Point p)
    {
        return Line(-b, a, p.x * b - p.y * a);
    }
};

struct Circle
{
    Point c;
    ld r;
    Circle():
        c(Point(0, 0)),
        r(1) {}
    Circle(Point c, ld r):
        c(c),
        r(r) {}
    Circle(ld x, ld y, ld r):
        c(Point(x, y)),
        r(r) {}
    ld len()
    {
        return (ld)2 * PI * r;
    }
    ld square()
    {
        return PI * r * r;
    }
};

Point readPoint()
{
    ld x, y;
    cin >> x >> y;
    return Point(x, y);
}

Line readLine()
{
    ld a, b, c;
    cin >> a >> b >> c;
    return Line(a, b, c);
}

Circle readCircle()
{
    ld x, y, r;
    cin >> x >> y >> r;
    return Circle(x, y, r);
}

ld dist(Point a, Point b)
{
    return (a - b).len();
}



Point LinesCross(Line l, Line k)
{
    l.norm();
    k.norm();
    return l.cross(k);
}

bool LinesParallel(Line l, Line k)
{
    l.norm();
    k.norm();
    return l.parallel(k);
}

bool PointOnLine(Point p, Line l)
{
    l.norm();
    return l.lies(p);
}

bool PointOnLine(Line l, Point p)
{
    l.norm();
    return l.lies(p);
}

bool PointsOnLine(Point a, Point b, Point c)
{
    return fabs((a - b) ^ (b - c)) < eps;
}

Line perpendicular(Point p, Line l)
{
    l.norm();
    return l.perpendicular(p);
}

Line perpendicular(Line l, Point p)
{
    l.norm();
    return l.perpendicular(p);
}

ld distToLine(Point p, Line l)
{
    l.norm();
    return l.dist(p);
}

ld distToRay(Point p, Point a, Point b)
{
    if ((b - a) * (p - a) > eps)
        return distToLine(p, Line(a, b));
    return p.dist(a);
}

ld distToSegment(Point p, Point a, Point b)
{
    return fmax(distToRay(p, a, b), distToRay(p, b, a));
}

ld polygonSquare(vector<Point> p)
{
    ld s = 0;
    int n = p.size();
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        s += (p[i].x - p[j].x) * (p[i].y + p[j].y);
    }
    return s / (ld)2;
}

bool PointOnCircle(Point P, Circle w)
{
    return fabs(dist(P, w.c) - w.r) < eps;
}

bool PointInCircle(Point P, Circle w)
{
    return dist(P, w.c) < w.r + eps;
}

vector<Point> LineCircleCross(Line l, Circle w)
{
    l.norm();
    vector<Point> v;
    ld d = distToLine(w.c, l);
    if (d - eps > w.r)
        return v;
    Point h = w.c - Point(l.a, l.b) * (w.c.x * l.a + w.c.y * l.b + l.c) / (l.a * l.a + l.b * l.b);
    if (abs(d - w.r) < eps)
    {
        v.push_back(h);
        return v;
    }
    Point vect = Point(-l.b, l.a);
    ld go = d / l.len();
    Point q = vect * go;
    v.push_back(h + q);
    v.push_back(h - q);
    return v;
}

vector<Point> CirclesCross(Circle w, Circle u)
{
    ld T = (ld)2;
    return LineCircleCross(Line(T * (w.c.x - u.c.x), T * (w.c.y - u.c.y), u.r * u.r - w.r * w.r), w);
}

Point down;

bool cmp(Point a, Point b)
{
    a = a - down;
    b = b - down;
    return ((a ^ b) > 0 || ((a ^ b) == 0 && a.len() < b.len()));
}
 
vector<Point> graham_convex_hull(vector<Point> a)
{
    int n = a.size();
    if (n < 3)
        return a;
    down = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] < down)
            down = a[i];
    sort(a.begin(), a.end(), cmp);
    vector<Point> v;
    for (int i = 0; i < n; i++)
    {
        while (v.size() > 1 && ((a[i] - v.back()) ^ (v.back() - v[v.size() - 2])) > -eps)
            v.pop_back();
        v.push_back(a[i]);
    }
    return v;
}

vector<Point> jarvis_convex_hull(vector<Point> a)
{
    int n = a.size();
    if (n < 3)
        return a;
    down = a[0]; 
    int k = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < down)
            k = i, down = a[i];
    vector<Point> v;
    v.push_back(down);
    int cur = k;
    while (true)
    {
        int next = -1;
        for (int i = 0; i < n; i++)
            if (i != cur && (next == -1 || ((a[i] - a[cur]) ^ (a[next] - a[cur])) > eps || 
            (abs((a[i] - a[cur]) ^ (a[next] - a[cur])) < eps && (a[i] - a[cur]).len() > (a[next] - a[cur]).len())))
                next = i;
        if (next == k)
            break;
        v.push_back(a[next]);
        cur = next;
    }
    return v;
}
vector<Point> q;

int main()
{
    //freopen("in.txt", "r", stdin);
    //ios::sync_with_stdio(0);
    cout.precision(100);
    int n, r;
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
    	Point p;
    	cin >> p.x;
    	p.y = 0;
    	ld y = r;
    	ld t = (ld)(2 * r);
    	for (int j = 0; j < i; j++)
    	{
    		ld xx = abs(q[j].x - p.x);
    		if (xx < t + eps)
    		{
    			ld f = sqrtf(t * t - xx * xx);
    			//cout << f << endl;
    			y = max(y, f + q[j].y);
    		}
    	}
    	p.y = y;
    	cout << y << " ";
    	q.push_back(p);
    }
    return 0;
}