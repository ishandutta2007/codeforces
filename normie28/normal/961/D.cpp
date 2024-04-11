#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
struct Point {
    ll x, y;
};
 
ll n;
vector<Point> points;
 
bool isCollinear(Point &a, Point &b, Point &c) {
    return ((a.x * b.y + b.x * c.y + c.x * a.y) - (a.x * c.y + b.x * a.y + c.x * b.y)) ==
           0;
}
 
bool test(Point &a, Point &b) {
    vector<Point> points2;
    for (ll i = 0; i < n; i++) {
        if (!(isCollinear(a, b, points[i])))
            points2.push_back(points[i]);
    }
 
    for (ll i = 2; i < points2.size(); i++) {
        if (!(isCollinear(points2[0], points2[1], points2[i])))
            return false;
    }
 
    return true;
}
 #define  endl "\n"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        points.push_back(Point{x, y});
    }
 
    if (n <= 2)
        cout << "YES" << endl;
    else if (test(points[0], points[1]) || test(points[0], points[2]) ||
             test(points[1], points[2]))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}