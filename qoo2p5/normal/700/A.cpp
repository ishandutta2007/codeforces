#include <bits/stdc++.h>

using namespace std;

#define ll long long
const double EPS = 1e-9;
const int INF = 1e9;
const ll LINF = 1e18;

const int N = 20;

int n, k;
double l, v1, v2;

bool check(double t) {
    int p = n / k + bool(n % k);
    double t1 = (l - t * v2) / (v1 - v2);
    double t2 = t - t1;
    double tb = t2 * (v2 - v1) / (v1 + v2);
    return p * t2 + (p - 1) * tb <= t;
}

int main() {
    scanf("%d%lf%lf%lf%d", &n, &l, &v1, &v2, &k);
    
    double left = 0;
    double right = l / v1;
    
    for (int i = 0; i < 70; i++) {
        double mid = (left + right) / 2;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    
    printf("%.15f\n", right);
    
    return 0;
}