#include <iostream>
#include <cstdio>

using namespace std;

double a, b, c, d;

bool ok(double x) {
    double a1 = a-x, a2 = a-(-x);
    double b1 = b-x, b2 = b-(-x);
    double c1 = c-x, c2 = c-(-x);
    double d1 = d-x, d2 = d-(-x);
    double ad1 = max(max(a1*d1, a1*d2), max(a2*d1, a2*d2));
    double ad2 = min(min(a1*d1, a1*d2), min(a2*d1, a2*d2));
    double bc1 = max(max(b1*c1, b1*c2), max(b2*c1, b2*c2));
    double bc2 = min(min(b1*c1, b1*c2), min(b2*c1, b2*c2));
    double z1 = ad1-bc2;
    double z2 = ad2-bc1;
    return z1 >= 0 && z2 <= 0;
}

int main() {
    cin >> a >> b >> c >> d;
    double t = 0;
    double x = 10e9;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 10; j++) {
            if (!ok(t+x)) t += x;
            else break;
        }
        x /= 2;
    }
    printf("%.9lf\n", t);
}