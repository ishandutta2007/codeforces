#include <iostream>

using namespace std;

int n, c1, c2;
int a[101010];
int b[101010];
int p,r;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        c1 += a[i];
        c2 += b[i];
    }
    p = abs(c1-c2);
    r = 0;
    for (int i = 1; i <= n; i++) {
        int u1 = c1;
        int u2 = c2;
        u1 -= a[i];
        u2 += a[i];
        u1 += b[i];
        u2 -= b[i];
        int u = abs(u1-u2);
        if (u > p) {
            p = u;
            r = i;
        }
    }
    cout << r << "\n";
}