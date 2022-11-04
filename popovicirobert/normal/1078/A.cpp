#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

inline double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

pair <double, double> pts1[100], pts2[100];
double coef1[100], coef2[100];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    ll a, b, c;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> a >> b >> c;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double ans = 1.0 * abs(x1 - x2) + 1.0 * abs(y1 - y2);
    if(a == 0 || b == 0) {
        cout << fixed << setprecision(20) << ans;
        return 0;
    }
    int sz1 = 0, sz2 = 0;
    if(b != 0) {
        double y = 1.0 * (-c - a * x1) / b;
        pts1[++sz1] = {x1, y};
        coef1[sz1] = fabs(y1 - y);
    }
    if(a != 0) {
        double x = 1.0 * (-c - b * y1) / a;
        pts1[++sz1] = {x, y1};
        coef1[sz1] = fabs(x1 - x);
    }
    if(b != 0) {
        double y = 1.0 * (-c - a * x2) / b;
        pts2[++sz2] = {x2, y};
        coef2[sz2] = fabs(y2 - y);
    }
    if(a != 0) {
        double x = 1.0 * (-c - b * y2) / a;
        pts2[++sz2] = {x, y2};
        coef2[sz2] = fabs(x2 - x);
    }
    int i, j;
    for(i = 1; i <= sz1; i++) {
        for(j = 1; j <= sz2; j++) {
            ans = min(ans, dist(pts1[i].first, pts1[i].second, pts2[j].first, pts2[j].second) + coef1[i] + coef2[j]);
        }
    }
    cout << fixed << setprecision(20) << ans;
    //cin.close();
    //cout.close();
    return 0;
}