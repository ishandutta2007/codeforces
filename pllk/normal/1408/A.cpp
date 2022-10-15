#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n], c[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        int p[n];
        p[0] = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] != p[i-1]) p[i] = a[i];
            else p[i] = b[i];
        }
        if (a[n-1] != p[n-2] && a[n-1] != p[0]) p[n-1] = a[n-1];
        if (b[n-1] != p[n-2] && b[n-1] != p[0]) p[n-1] = b[n-1];
        if (c[n-1] != p[n-2] && c[n-1] != p[0]) p[n-1] = c[n-1];
        for (int i = 0; i < n; i++) cout << p[i] << " ";
        cout << "\n";
    }
}