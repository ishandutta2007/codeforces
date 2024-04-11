#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <complex>

using namespace std;

#define PI 3.141592653589793
#define CD complex<double>

CD u[1000000];

void fft(vector<CD> &a, int d) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int u = 0;
        for (int j = 1; j < n; j *= 2) {
            u *= 2;
            if (i&j) u++;
        }
        if (i < u) swap(a[i], a[u]);
    }
    for (int m = 2; m <= n; m *= 2) {
        CD wm = exp(CD{0,d*2*PI/m});
        for (int k = 0; k < n; k += m) {
            CD w = 1;
            for (int j = 0; j < m/2; j++) {
                CD t = w*a[k+j+m/2];
                CD u = a[k+j];
                a[k+j] = u+t;
                a[k+j+m/2] = u-t;
                w *= wm;
            }
        }
    }
    if (d == -1) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

int n, m, k;
string s;
string t;
string d = "ACGT";
int x[4][202020];
int ok[202020];

int main() {
    cin >> n >> m >> k;
    cin >> s >> t;
    for (int c = 0; c < 4; c++) {
        int v = -999999999;
        for (int i = 0; i < n; i++) {
            if (s[i] == d[c]) v = i;
            if (i-v <= k) x[c][i] = 1;
        }
        v = 999999999;
        for (int i = n-1; i >= 0; i--) {
            if (s[i] == d[c]) v = i;
            if (v-i <= k) x[c][i] = 1;
        }
    }
    int u = 1;
    while (u < n) u *= 2;
    for (int c = 0; c < 4; c++) {
        vector<CD> a(2*u), b(2*u);
        for (int i = 0; i < n; i++) a[i] = x[c][i];
        int q = 0;
        for (int i = 0; i < m; i++) {
            if (t[i] == d[c]) {
                b[m-i-1] = 1;
                q++;
            }
        }
        fft(a, 1);
        fft(b, 1);
        vector<CD> f(2*u);
        for (int i = 0; i < 2*u; i++) f[i] = a[i]*b[i];
        fft(f, -1);
        for (int i = 0; i < n; i++) {
            ok[i] += abs(real(f[i+m-1])-q) < 0.0001;
        }
    }
    int r = 0;
    for (int i = 0; i < n; i++) if (ok[i] == 4) r++;
    cout << r << "\n";
}