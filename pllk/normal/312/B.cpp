#include <iostream>

#define E 0.000000001

using namespace std;

double a, b, c, d;
double t;
double p;
double v;

int main() {
    cin >> a >> b >> c >> d;
    t = 0;
    v = t;
    p = 1;
    while (true) {
        t += (a/b)*p;
        if (t-v < E) break;
        v = t;
        p *= (1-a/b)*(1-c/d);
    }
    cout.precision(10);
    cout << t << endl;
}