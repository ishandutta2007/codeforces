#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        int f1 = 0, f2 = 0;
        int m = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > 0) f1 = 1;
            if (a[i] < 0) f2 = 1;
            m = max(m,abs(a[i]));
        }
        if (f2) {
            cout << "NO\n";
            continue;
        }
        int g = a[0];
        for (int i = 1; i < n; i++) g = gcd(g,a[i]);
        g = abs(g);
        cout << "YES\n";
        cout << (m/g+1) << "\n";
        for (int i = 0; i <= m; i += g) {
            if (f1) cout << i << " ";
            else cout << -i << " ";
        }
        cout << "\n";
    }
}