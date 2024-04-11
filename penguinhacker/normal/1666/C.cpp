#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

class Point {
public:
    ll x;
    ll y;
    Point() {}
    Point(ll xn, ll yn) {
        x = xn;
        y = yn;
    }
};

Point p1;
Point p2;
Point p3;

Point closest(Point a, Point b, Point p) {
    ll x, y;
    if ((a.x <= p.x && p.x <= b.x) || (a.x >= p.x && p.x >= b.x)) x = p.x;
    else {
        x = a.x;
        if (abs(p.x-b.x) < abs(p.x-a.x)) x = b.x;
    }
    if ((a.y <= p.y && p.y <= b.y) || (a.y >= p.y && p.y >= b.y)) y = p.y;
    else {
        y = a.y;
        if (abs(p.y-b.y) < abs(p.y-a.y)) y = b.y;
    }
    return Point(x, y);
}

ll dist(Point a, Point b) {
    return abs(b.x-a.x)+abs(b.y-a.y);
}

void draw(Point a, Point b) {
    cout << a.x << " " << a.y << " " << b.x << " " << a.y << "\n";
    cout << b.x << " " << a.y << " " << b.x << " " << b.y << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "6\n";
    ll x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    p1 = Point(x1, y1);
    p2 = Point(x2, y2);
    p3 = Point(x3, y3);
    Point e1;
    Point e2;
    Point e3;
    e1 = closest(p2, p3, p1);
    e2 = closest(p1, p3, p2);
    e3 = closest(p2, p1, p3);
    ll d1, d2, d3;
    d1 = dist(p2, p3) + dist(e1, p1);
    d2 = dist(p1, p3) + dist(e2, p2);
    d3 = dist(p1, p2) + dist(e3, p3);
    if (d1 < d2 && d1 < d3) {
        draw(p2, e1);
        draw(e1, p3);
        draw(e1, p1);
        return 0;
    }
    if (d2 < d1 && d2 < d3) {
        draw(p1, e2);
        draw(e2, p3);
        draw(e2, p2);
        return 0;
    }
    draw(p1, e3);
    draw(e3, p2);
    draw(e3, p3);
    return 0;
}