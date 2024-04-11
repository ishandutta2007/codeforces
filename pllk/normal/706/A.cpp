#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

double a, b;
int n;
double p = 1e9;

int main() {
    cin >> a >> b;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y, v;
        cin >> x >> y >> v;
        double d = sqrt(pow(a-x,2)+pow(b-y,2));
        double u = d/v;
        if (u < p) p = u;
    }
    printf("%.9f\n", p);
}