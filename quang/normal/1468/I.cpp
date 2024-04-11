#include <bits/stdc++.h>

using namespace std;

// #define int long long

const int N = 100010;
const int INF = 2.01e6;

template<typename T = int>
struct Point {
    T x, y;
    Point() { x = y = 0; }
    Point(T x, T y) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator / (T k) const { return Point(x/k, y/k); }

    long long operator % (const Point& a) const { return 1ll * x*a.y - 1ll * y*a.x; } // cross product

    bool operator < (const Point<T> &o) const {
        if (y != o.y) return y < o.y;
        return x < o.x;
    }
};

long long ccw(Point<int> x, Point<int> y, Point<int> z) {
    return (y - x) % (z - x);
}

int n;
Point<int> A, B;
vector<Point<int>> ls;

bool inside(Point<int> now) {
    int sum = 0;
    for (int i = 0; i + 1 < ls.size(); i++) {
        long long foo = ccw(now, ls[i], ls[i + 1]);
        if (foo == 0) return false;
        else if (foo > 0) sum++;
        else sum--;
    }
    long long foo = ccw(now, ls[3], ls[0]);
    if (foo == 0) return false;
    else if (foo > 0) sum++;
    else sum--;
    return abs(sum) == 4;
};

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
    if (A % B == 0) return cout << "NO\n", 0;
    Point<int> cur(0, 0);
    ls.push_back(cur);
    ls.push_back(cur + A);
    ls.push_back(cur + A + B);
    ls.push_back(cur + B);
    Point<int> minPoint = *min_element(ls.begin(), ls.end());
    Point<int> maxPoint = *max_element(ls.begin(), ls.end());
    vector<Point<int>> res;
    res.reserve(n + 1);

    bool found = 0;
    for (int i = minPoint.y + 1; i < maxPoint.y; i++) {
        // if (i % 100000 == 0) cout << i << endl;
        int low = -INF, high = INF;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            Point<int> now(mid, i);
            if (inside(now) || ccw(minPoint, maxPoint, now) < 0) high = mid;
            else low = mid;
        }
        Point<int> now(high, i);
        while (inside(now)) {
            res.push_back(now);
            if (res.size() > n) {
                found = 1;
                break;
            }
            now.x++;
        }
        if (found) break;
    }
    int g = __gcd(abs(A.x), abs(A.y));
    if (res.size() + g > n) {
        cout << "NO\n";
        return 0;
    }
    cur = Point<int>(0, 0);
    Point<int> delta = A / g;
    for (int i = 0; i < g; i++) {
        res.push_back(cur);
        cur = cur + delta;
    }

    g = __gcd(abs(B.x), abs(B.y));
    if (res.size() + g - 1 > n) {
        cout << "NO\n";
        return 0;
    }
    cur = Point<int>(0, 0);
    delta = B / g;
    for (int i = 1; i < g; i++) {
        cur = cur + delta;
        res.push_back(cur);
    }

    if (res.size() != n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto u : res) cout << u.x << ' ' << u.y << '\n';
    return 0;
}