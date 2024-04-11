#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[2020];

#define D 30000
int x[101010];

double d[101010][5];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int c1 = 0, c2 = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            int s = a[i]-a[j];
            x[s+D]++;
            if (a[i] > a[j]) c1++;
            else c2++;
        }
    }
    for (int i = 0; i < 101010; i++) d[D][0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 0; j < 101010; j++) {
            if (d[j][i-1] == 0) continue;
            int a = -5000;
            int b = 5000;
            if (i <= 2) a = 0;
            else b = 0;
            int c;
            if (i <= 2) c = c1;
            else c = c2;
            for (int k = a; k <= b; k++) {
                d[j+k][i] += d[j][i-1]*x[k+D]/c;
            }
        }
    }
    double r = 0;
    for (int i = 0; i < 101010; i++) {
        if (i >= D) break;
        r += d[i][3];
    }
    printf("%.12lf\n", r);
}