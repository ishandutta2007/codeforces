#include <iostream>
#include <cstdio>

using namespace std;

int n, l;
double a[101010];

double d1(double x) {
    double s = 1;
    int k = 1;
    double p = 0;
    while (true) {
        if (k <= n && (a[k]-p)/s <= x) {
            x -= (a[k]-p)/s;
            p = a[k];
            k++;
            s++;
        } else {
            p += x*s;
            break;
        }
    }
    return p;
}

double d2(double x) {
    double s = 1;
    int k = n;
    double p = l;
    while (true) {
        if (k >= 1 && (p-a[k])/s <= x) {
            x -= (p-a[k])/s;
            p = a[k];
            k--;
            s++;
        } else {
            p -= x*s;
            break;
        }
    }
    return l-p;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> l;
        for (int i = 1; i <= n; i++) cin >> a[i];
        double x = 0;
        double b = 1e9;
        for (int i = 0; i < 200; i++) {
            if (d1(x+b)+d2(x+b) < l) x += b;
            b /= 2;
        }
        printf("%.9f\n",x);
    }
}