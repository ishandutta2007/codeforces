#include <iostream>

using namespace std;

int a[1010];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int f = 0, g = 0;
        int c1 = 0, c2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] != x) f = 1;
            if (a[i] == x) g = 1;
            if (a[i] < x) c1 += x-a[i];
            else c2 += a[i]-x;
        }
        if (f == 0) {
            cout << 0 << "\n";
        } else if (c1 == c2 || g) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }
}