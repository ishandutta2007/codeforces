#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

long long a, b, c;
long long x, y, xx, yy;

vector<pair<double, double> > get(long long x, long long y) {
    vector<pair<double, double> > res;
    res.push_back({(double)(-c - b * y) / a, y});
    res.push_back({x, (double)(-c - a * x) / b});
    return res;
}

double getDis(double x, double y, double xx, double yy) {
    return abs(x - xx) + abs(y - yy);
}

double getDis2(double x, double y, double xx, double yy) {
    double foo = x - xx;
    double bar = y - yy;
    return sqrt(foo * foo + bar * bar);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    cin >> x >> y >> xx >> yy;
    double res = abs(x - xx) + abs(y - yy);
    if (a == 0 || b == 0) {
        cout << fixed << setprecision(10) << res << endl;
        return 0;
    }
    vector<pair<double, double> > a = get(x, y);
    vector<pair<double, double> > b = get(xx, yy);
    for (auto u : a) {
        for (auto v : b) {
            double foo = getDis(x, y, u.first, u.second) + getDis(xx, yy, v.first, v.second);
            foo += getDis2(u.first, u.second, v.first, v.second);
            res = min(res, foo);
        }
    }
    cout << fixed << setprecision(10) << res << endl;
    return 0;
}