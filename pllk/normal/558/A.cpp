#include <iostream>

using namespace std;

int n;
int x[111];
int a[111];
int c[111];
int p;

void simu(int s) {
    int k = 0;
    int z = 0;
    while (true) {
        int j = -1, u;
        if (s == 1) u = 999999999;
        else u = -999999999;
        for (int i = 0; i < n; i++) {
            if (c[i]) continue;
            if (s == 1 && x[i] > k && x[i] < u) {
                u = x[i];
                j = i;
            }
            if (s == -1 && x[i] < k && x[i] > u) {
                u = x[i];
                j = i;
            }
        }
        if (j == -1) break;
        z += a[j];
        c[j] = 1;
        s = -s;
    }
    if (z > p) p = z;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i] >> a[i];
    for (int i = 0; i < n; i++) c[i] = 0;
    simu(1);
    for (int i = 0; i < n; i++) c[i] = 0;
    simu(-1);
    cout << p << "\n";
}