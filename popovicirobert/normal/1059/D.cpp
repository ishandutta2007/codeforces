#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const double eps = 1e-9;
const double INF = 1e18;
const int MAXN = (int) 1e5;

pair <double, double> pts[MAXN + 1];

inline bool eq(double x, double y) {
    return fabs(x - y) < eps;
}

inline int sign(double x) {
    if(x < 0)
        return -1;
    return 1;
}

inline bool check(double rad, int n) {
    double l = -INF, r = INF;
    for(int i = 1; i <= n; i++) {
        if(sign(2.0 * rad - pts[i].second) * sign(pts[i].second) == 1) {
            double dst = sqrt(fabs(pts[i].second)) * sqrt(fabs(2 * rad - pts[i].second));
            l = max(l, pts[i].first - dst);
            r = min(r, pts[i].first + dst);
        }
        else {
            return 0;
        }
    }
    return r - l > 0;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    double mx = -INF, mn = INF;
    for(i = 1; i <= n; i++) {
        cin >> pts[i].first >> pts[i].second;
        mx = max(mx, pts[i].second);
        mn = min(mn, pts[i].second);
    }
    if(mx > 0 && mn < 0) {
        cout << -1;
        return 0;
    }
    for(i = 1; i <= n; i++) {
        pts[i].second = abs(pts[i].second);
    }
    double l = 0, r = INF;
    for(i = 0; i < 100; i++) {
        double mid = (l + r) * 0.5;
        if(check(mid, n)) {
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << fixed << setprecision(20) << (l + r) * 0.5;
    //cin.close();
    //cout.close();
    return 0;
}