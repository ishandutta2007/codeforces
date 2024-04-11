#include <bits/stdc++.h>
using namespace std;

long double x0, _y0, r0, x1, _y1, r1;

int main() {
    cin >> x0 >> _y0 >> r0 >> x1 >> _y1 >> r1;
    if (abs(x0 - x1) < 1e-12 && abs(_y0 - _y1) < 1e-12) {
        cout << setprecision(15) << fixed << (long double)asin(1) * 2 * min(r0, r1) * min(r0, r1) << endl;
        return 0;
    }
    long double c = hypot(x0 - x1, _y0 - _y1);
    if (r0 < r1) {
        if (c + r0 <= r1) {
            cout << setprecision(15) << fixed << (long double)asin(1) * 2 * min(r0, r1) * min(r0, r1) << endl;
            return 0;
        }
    } if (r1 < r0) {
        if (c + r1 <= r0) {
            cout << setprecision(15) << fixed << (long double)asin(1) * 2 * min(r0, r1) * min(r0, r1) << endl;
            return 0;
        }
    }
    long double cba = acos((r1 * r1 + c * c - r0 * r0) / (r1 * c * 2));
    if (abs((r1 * r1 + c * c - r0 * r0) / (r1 * c * 2)) > 1) {
        printf("0.0000000000\n");
        return 0;
    }
    long double cbd = cba * 2;
    long double cab = acos((r0 * r0 + c * c - r1 * r1) / (r0 * c * 2));
    if (abs((r0 * r0 + c * c - r1 * r1) / (r0 * c * 2)) > 1) {
        printf("0.0000000000\n");
        return 0;
    }
    long double cad = cab * 2;
    long double area = cbd * r1 * r1 * 0.5 - r1 * r1 * sin(cbd) * 0.5 + r0 * r0 * cad * 0.5 - r0 * r0 * sin(cad) * 0.5;
    cout << setprecision(15) << fixed << area << endl;
}