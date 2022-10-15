#include <iostream>
#include <algorithm>

using namespace std;

int n, t;
int a[111];

int d1[333];
int d2[333];
int z;

void lol() {
    for (int i = 0; i < n*t; i++) {
        int p = 0;
        for (int j = 1; j <= a[i%n]; j++) {
            if (d1[j] > p) p = d1[j];
        }
        if (p+1 > d1[a[i%n]]) d1[a[i%n]] = p+1;
        z = max(z,d1[a[i%n]]);
        if (i+1 == n*t) {cout << z << "\n"; exit(0);}
    }
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (t <= 400) {lol(); return 0;}
    for (int i = 0; i < n*200; i++) {
        int p = 0;
        for (int j = 1; j <= a[i%n]; j++) {
            if (d1[j] > p) p = d1[j];
        }
        if (p+1 > d1[a[i%n]]) d1[a[i%n]] = p+1;
    }
    for (int i = t*n-1; i >= t*n-200*n; i--) {
        int p = 0;
        for (int j = a[i%n]; j <= 300; j++) {
            if (d2[j] > p) p = d2[j];
        }
        if (p+1 > d2[a[i%n]]) d2[a[i%n]] = p+1;
    }
    t -= 400;
    int w = 0;
    for (int h = 1; h <= 300; h++) {
        int u = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == h) u++;
        }
        w = max(w, d1[h]+d2[h]+t*u);
    }
    cout << w << "\n";
}