#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n;
double r;
double x[1111];
double y[1111];

int main() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int i = 1; i <= n; i++) {
        double z = r;
        for (int j = 1; j < i; j++) {
            double g = fabs(x[j]-x[i]);
            if (g > 2*r) continue;
            z = max(z,y[j]+sqrt(4*r*r-g*g));
        }
        y[i] = z;
        printf("%.12f ", z);
    }
    printf("\n");
}