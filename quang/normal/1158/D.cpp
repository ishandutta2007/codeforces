#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

struct Point {
    int x, y, id;
    bool operator < (const Point &u) const {
        if (x != u.x) return x < u.x;
        return y < u.y;
    }
    Point operator - (const Point &u) const {
        return {x - u.x, y - u.y, -1};
    }
};

long long ccw(Point u, Point v, Point w) {
    u = v - u;
    v = w - v;
    return 1ll * u.x * v.y - 1ll * u.y * v.x;   
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Point> a;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y, i});
    }
    string s;
    cin >> s;
    sort(a.begin(), a.end());
    vector<Point> res;
    res.push_back(a[0]);
    a.erase(a.begin());

    for (char u : s) {
        Point cur = res.back();
        int best = 0;
        if (u == 'L') {
            for (int i = 1; i < a.size(); i++) {
                if (ccw(cur, a[best], a[i]) < 0) {
                    best = i;
                } 
            }
        } else {
            for (int i = 1; i < a.size(); i++) {
                if (ccw(cur, a[best], a[i]) > 0) {
                    best = i;
                } 
            }
        }
        res.push_back(a[best]);
        a.erase(a.begin() + best);
    }
    assert(a.size() == 1);
    res.push_back(a[0]);
    for (auto u : res) {
        cout << u.id << ' ';
    }
    cout << endl;
    return 0;
}