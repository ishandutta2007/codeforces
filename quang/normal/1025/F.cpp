#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int n;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    const Point operator - (const Point &u) const {
        return Point(x - u.x, y - u.y);
    }

    const long long operator ^ (const Point &u) const {
        return 1ll * x * u.y - 1ll * u.x * y;
    }
    
    const bool operator != (const Point &u) const {
        return x != u.x || y != u.y;
    }
};

Point a[N];

bool cmp(const Point &u, const Point &v) {
    if ((u.y >= 0) ^ (v.y < 0) == 0) {
        return u.y > v.y;
    }
    return (u ^ v) >= 0;
}

long long f(int u) {
    return 1ll * u * (u - 1) / 2;
}

long long go(int root) {
    long long res = 0;
    vector<Point> ls;
    for (int i = 1; i <= n; i++) {
        if (i != root) {
            ls.push_back(a[i] - a[root]);
        }
    }
    sort(ls.begin(), ls.end(), cmp);
    // cout << root << endl;
    // for (Point u : ls) {
    //     cout << u.x << " " << u.y << endl;
    // }
    int sz = ls.size();
    for (int i = 0; i < sz; i++) {
        ls.push_back(ls[i]);
    }
    int cur = 0;
    int cnt = 0;
    for (int i = 0; i < sz; i++) {
        if (cur < i) {
            cur = i;
        }
        while (cur + 1 < ls.size() && ls[cur + 1] != ls[i] && (ls[i] ^ ls[cur + 1]) > 0) {
            cur++;
            cnt++;
        }
        res += f(cnt) * f(n - 2 - cnt);
        // cout << "current " << i << " " << cur << " " << cnt << endl;
        if (cnt) {
            cnt--;
        }
    }
    // cout << res << endl;
    // cout << endl;
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        res += go(i);
    }
    res /= 2ll;
    cout << res << endl;
    return 0;
}