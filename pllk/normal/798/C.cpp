#include <iostream>

using namespace std;

int n;
int a[101010];

int gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int g = a[1];
    for (int i = 2; i <= n; i++) g = gcd(g,a[i]);
    if (g > 1) {
        cout << "YES\n0\n";
        return 0;
    }
    int c = 0;
    int u = 0;
    for (int i = 1; i <= n+1; i++) {
        if (a[i]%2 == 0) {
            if (c%2 == 0) {
                u += c/2;
            } else {
                u += c/2+2;
            }
            c = 0;
        } else {
            c++;
        }
    }
    cout << "YES\n";
    cout << u << "\n";
}