#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
typedef long double ld;

int n;

struct Point {
    ld x, y;

    Point(ld x = 0, ld y = 0) : x(x), y(y) {}
} a[N];

ld get(ld u) {
    ld res = 0;
    for (int i = 1; i <= n; i++) {
        ld delta = (u - a[i].x) * (u - a[i].x);
        ld foo = delta + a[i].y * a[i].y;
        foo /= a[i].y;
        foo /= 2.;
        res = max(res, foo);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = Point(x, y);
        if (y < 0) {
            flag |= 1;
        } else {
            flag |= 2;
        }
    }
    if (flag == 3) {
        cout << -1 << endl;
        return 0;
    }
    if (flag == 1) {
        for (int i = 1; i <= n; i++) {
            a[i].y = -a[i].y;
        }
    }
    ld low = -2e7, high = 2e7;
    for (int it = 1; it <= 200; it++) {
        ld mid1 = (low * 2 + high) / 3.;
        ld mid2 = (low + high * 2) / 3.;
        ld res1 = get(mid1);
        ld res2 = get(mid2);
        if (res1 < res2) {
            high = mid2;
        } else {
            low = mid1;
        }
    }
    cout << fixed << setprecision(14) << get((low + high) / 2) << endl;
    return 0;
}