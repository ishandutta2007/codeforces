#include <iostream>

using namespace std;

int n;
int c[1010101];
int p[1010101];
int z[1010101];

void lisaa(int k, int r, int i) {
    while (k < 1000000) {
        if (z[k] != i) {
            z[k] = i;
            c[k]++;
            p[k] += r;
        }
        k *= 2;
        r++;
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        int c = 0;
        while (a >= 1) {
            lisaa(a,c,i);
            a /= 2;
            c++;
        }
    }
    int u = 999999999;
    for (int i = 1; i <= 1000000; i++) {
        if (c[i] != n) continue;
        u = min(u,p[i]);
    }
    cout << u << "\n";
}