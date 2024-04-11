#include <bits/stdc++.h>

using namespace std;

const int N = 2510;

int n;

struct Point {
    long long x, y;
    Point() { x = y = 0; }
    Point(long long x, long long y) : x(x), y(y) {}

    Point operator + (const Point& a) const { return Point(x+a.x, y+a.y); }
    Point operator - (const Point& a) const { return Point(x-a.x, y-a.y); }
    Point operator * (long long k) const { return Point(x*k, y*k); }
    Point operator / (long long k) const { return Point(x/k, y/k); }

    long long operator * (const Point& a) const { return x*a.x + y*a.y; } // dot product
    long long operator % (const Point& a) const { return x*a.y - y*a.x; } // cross product
    long long norm() { return x*x + y*y; }
    long long len() { return sqrt(norm()); } // hypot(x, y);};
    bool isUpper() const {
        return y > 0 || (y == 0 && x > 0);
    }
};

Point a[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    long long res = 0;
    long long tot4 = 1ll * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 24;
    for (int i = 1; i <= n; i++) {
        vector<Point> ls;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            ls.push_back(a[j] - a[i]);
        }
        sort(ls.begin(), ls.end(), [&](const Point &u, const Point &v) {
            if (u.isUpper() != v.isUpper()) return u.isUpper();
            return (u % v) > 0;
        });
        long long num3 = 0, num4 = 0;
        int sz = ls.size();
        for (int j = 0; j < sz; j++) {
            ls.push_back(ls[j]);
        }
        // cout << "Start " << i << endl;
        for (int s = 0, t = 0; s < sz; s++) {
            if (t <= s) t = s + 1;
            while ((ls[s] % ls[t]) > 0) t++;
            int num = t - s;
            // num3 += 1ll * num * (num - 1) * (num - 2) / 6;
            num4 += 1ll * (num - 1) * (num - 2) * (num - 3) / 6;
        }
        // cout << tot4 << ' ' << num4 << endl;
        res += (tot4 - num4);
    }
    cout << res << endl;
    return 0;
}