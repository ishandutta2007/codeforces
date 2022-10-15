#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
double t;

double ncr[1111][1111];

int main() {
    cin >> n >> m;
    for (int j = 1; j <= n; j++) ncr[0][j] = 0;
    ncr[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        ncr[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            ncr[i][j] = ncr[i-1][j]+ncr[i-1][j-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        int k = m*n-1;
        int h = m-1;
        if (i-1 > h) continue;
        double u = (double)i/n;
        int c = 0;
        for (int j = 2; j <= n; j++) {
            if (c < i-1) {
                u *= (double)h/k;
                h--;
                k--;
                c++;
            } else {
                u *= (double)(k-h)/k;
                k--;
            }
        }
        u *= ncr[n-1][i-1];
        t += u;
    }
    printf("%.12lf\n", t);
}