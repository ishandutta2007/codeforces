#include <iostream>
#include <algorithm>

using namespace std;

int a[101010];
int b[101010];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b,b+n);
        int g = b[0];
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (gcd(g,a[i]) == g) continue;
            if (a[i] != b[i]) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}