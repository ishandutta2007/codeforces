#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, R, r;
    cin >> n >> R >> r;

    if (r > R) {
        cout << "NO" << endl;
        return 0;
    }

    if (n == 1) {
        cout << "YES" << endl;
        return 0;
    }

    const double pi = acos(-1);
    double ang = 2 * pi / n;

    double dis = pow(R-r, 2) * (2 - 2 * cos(ang));

    cout << (dis + 1e-12 < pow(2*r, 2) ? "NO" : "YES") << endl;

    return 0;
}