#include <bits/stdc++.h>
using namespace std;

long double a, b, c, d;
int main() {
    cin >> a >> b >> c >> d;
    long double lo, hi;
    lo = 0;
    hi = 1e9;
    int steps = 0;
    while (hi - lo > 1e-10 && steps < 1000000) {
        ++steps;
        long double m = (lo + hi) / 2.0;
        long double x = m;
        long double mia = a - x;
        long double mib = b - x;
        long double maa = a + x;
        long double mab = b + x;
        long double mic = c - x;
        long double mid = d - x;
        long double mac = c + x;
        long double mad = d + x;
        long double miad = min(min(mia * mid, mia * mad), min(maa * mid, maa * mad));
        long double maad = max(max(mia * mid, mia * mad), max(maa * mid, maa * mad));
        long double mibc = min(min(mib * mic, mib * mac), min(mab * mic, mab * mac));
        long double mabc = max(max(mib * mic, mib * mac), max(mab * mic, mab * mac));
        if (maad - mibc >= 0 && 0 >= miad - mabc) {
            hi = m;
        } else {
            lo = m;
        }
    }
    double haha = lo;
    printf("%.10lf\n", haha);
}