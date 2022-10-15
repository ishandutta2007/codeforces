#include <iostream>

using namespace std;

int n, l, r, x;
int c[20];
int z;

int main() {
    cin >> n >> l >> r >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int b = 0; b < (1<<n); b++) {
        int s = 0;
        int x1 = -1, x2 = -1;
        for (int i = 0; i < n; i++) {
            if (b&(1<<i)) {
                s += c[i];
                if (x1 == -1 || c[i] < x1) x1 = c[i];
                if (x2 == -1 || c[i] > x2) x2 = c[i];
            }
        }
        if (s < l || s > r) continue;
        if (x2-x1 < x) continue;
        z++;
    }
    cout << z << "\n";
}