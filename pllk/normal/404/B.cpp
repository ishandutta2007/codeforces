#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define ll long long

double a, d;
int n;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> a >> d;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll k = (ll)floor(i*d/a);
        double y = i*d-k*a;
        if (k%4 == 0) printf("%.10lf %.10lf\n", y, 0.0);
        if (k%4 == 1) printf("%.10lf %.10lf\n", a, y);
        if (k%4 == 2) printf("%.10lf %.10lf\n", a-y, a);
        if (k%4 == 3) printf("%.10lf %.10lf\n", 0.0, a-y);
    }
}