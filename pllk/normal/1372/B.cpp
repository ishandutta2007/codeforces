#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ok = 0;
        for (int u = 2; u*u <= n; u++) {
            if (n%u == 0) {
                int a = n/u;
                int b = n-a;
                cout << a << " " << b << "\n";
                ok = 1;
                break;
            }
        }
        if (!ok) cout << 1 << " " << n-1 << "\n";
    }
}