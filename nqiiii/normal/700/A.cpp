#include <bits/stdc++.h>
using namespace std;
int n, l, v1, v2, k;
double ls, rs;

double Check(double v) {
    double nowL = v / v2 * v1, nowR = v, pos = v;
    for (int i = 1; i < n; ++i) {
        double tm = (pos - nowL) / (v1 + v2);
        nowL += v1 * tm; nowR += v1 * tm;
        pos -= v2 * tm;
        tm = (nowR - pos) / (v2 - v1);
        nowL += v1 * tm; nowR += v1 * tm; pos += v2 * tm;
    }
    return nowR;
}

int main() {
    scanf("%d%d%d%d%d", &n, &l, &v1, &v2, &k);
    n = (n - 1) / k + 1;
    rs = l;
    while (rs - ls > 1e-6) {
        double mid = (ls + rs) / 2;
        if (Check(mid) <= l) ls = mid; else rs = mid;
    }
    printf("%.10lf", ls / v2 + (l - ls) / v1);
}