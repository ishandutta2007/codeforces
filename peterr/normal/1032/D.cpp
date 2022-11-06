#include <bits/stdc++.h>

using namespace std;

struct Point
{
    long double x, y;

    Point operator-(Point &p)
    {
        return {x - p.x, y - p.y};
    }
    long double cross(Point &p)
    {
        return (x * p.y) - (y * p.x);
    }
    long double abs()
    {
        return sqrt(x * x + y * y);
    }
};

Point inter(int a, int b, int c, int d, int e, int f)
{
    long double y = (f - ((long double) d * c) / a) / (e - ((long double) d * b) / a);
    long double x = (c - (long double) b * y) / a;
    return {x, y};
}

ostream& operator<<(ostream &os, Point &p)
{
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

vector<Point> points1;
vector<Point> points2;

int main()
{
    int a, b, c, x1, y1, x2, y2;
    cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
    c = -c;
    long double ans = (long double) abs(x1 - x2) + abs(y1 - y2);
    if (a != 0 && b != 0)
    {
        points1.push_back(inter(a, b, c, 0, 1, y1));
        points1.push_back(inter(a, b, c, 1, 0, x1));
        points2.push_back(inter(a, b, c, 0, 1, y2));
        points2.push_back(inter(a, b, c, 1, 0, x2));
        Point A = {(long double) x1, (long double) y1};
        Point B = {(long double) x2, (long double) y2};
        for (Point p1 : points1)
        {
            for (Point p2 : points2)
            {
                long double dist = (A - p1).abs() + (p1 - p2).abs() + (p2 - B).abs();
                //cout << p1 << " " << p2 << " " << dist << endl;
                ans = min(ans, dist);
            }
        }
    }
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}