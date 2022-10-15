#include <iostream>

using namespace std;

int n;
int x[111];
int d[111][5];
int v[111][5];

int min3(int a, int b, int c) {
    return min(a,min(b,c));
}

int laske(int k, int z) {
    if (k == 0) return 0;
    if (v[k][z]) return d[k][z];
    int u = 0;
    if (z == 0) {
        u = min3(laske(k-1,0),laske(k-1,1),laske(k-1,2));
    }
    if (z == 1) {
        u = min(laske(k-1,0),laske(k-1,2));
    }
    if (z == 2) {
        u = min(laske(k-1,0),laske(k-1,1));
    }
    if (z == 0) u++;
    if (z == 1 && (x[k] != 1 && x[k] != 3)) u = 999999999;
    if (z == 2 && (x[k] != 2 && x[k] != 3)) u = 999999999;
    d[k][z] = u;
    v[k][z] = 1;
    return u;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i];
    cout << min3(laske(n,0),laske(n,1),laske(n,2)) << "\n";
}