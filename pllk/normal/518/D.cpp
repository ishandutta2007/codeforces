#include <iostream>
#include <cstdio>

using namespace std;

int n, t;
double p;
double d[2222][2222];

int main() {
    cin >> n >> p >> t;
    d[0][n] = 1;
    for (int i = 0; i < t; i++) {
        d[i+1][0] = d[i][0];
        for (int j = 1; j <= n; j++) {
            d[i+1][j-1] += p*d[i][j];
            d[i+1][j] += (1-p)*d[i][j];
        }
    }
    double s = 0;
    for (int i = 0; i <= n; i++) {
        s += i*d[t][i];
    }
    printf("%.12f\n", n-s);
}