#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, k;
int p[100];
int q[100];
int z;

void haku(int c) {
    if (c == 0) {
        int t = 0;
        for (int a = 0; a < n; a++) {
            for (int b = a+1; b < n; b++) {
                if (p[a] > p[b]) t++;
            }
        }
        q[t]++;
        z++;
        return;
    }
    for (int a = 0; a < n; a++) {
        for (int b = a+1; b <= n; b++) {
            reverse(p+a, p+b);
            haku(c-1);
            reverse(p+a, p+b);
        }
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> p[i];
    haku(k);
    double e = 0;
    for (int i = 0; i < 100; i++) {
        e += i*(double)q[i]/z;
    }
    printf("%.12lf\n", e);
}