#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 217
// 44

using namespace std;

const double eps = 1e-9;

inline double squ(double x) {
    return 1.0 * x * x;
}

inline double getDist(double x1, double y1, double x2, double y2) {
    return sqrt(squ(x1 - x2) + squ(y1 - y2));
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    //int ;
    double R, x1, y1, x2, y2;
    ios::sync_with_stdio(false);
    cin >> R >> x1 >> y1 >> x2 >> y2;
    if(squ(R) < squ(x1 - x2) + squ(y1 - y2)) {
        cout << setprecision(20) << x1 << " " << y1 << " " << R;
    }
    else {
        double dst = getDist(x1, y1, x2, y2);
        if(eps - dst > 0) {
            cout << x1 << " " << y1 - R / 2.0 << " " << R / 2.0;
            return 0;
        }
        double x = ((x2 - x1) * R + x1 * dst) / dst;
        double y = ((y2 - y1) * R + y1 * dst) / dst;
        cout << setprecision(20) << (x2 + 2 * x1 - x) / 2.0 << " " << (y2 + 2 * y1 - y) / 2.0 << " " << (dst + R) / 2.0;
    }
    //cin.close();
    //cout.close();
    return 0;
}