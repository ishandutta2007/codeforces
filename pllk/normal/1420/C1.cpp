#include <iostream>

using namespace std;

typedef long long ll;

int n, q;
int a[303030];

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll p1 = 0, p2 = 0;
        for (int i = 1; i <= n; i++) {
            ll u1 = max(p1,p2+a[i]);
            ll u2 = max(p2,p1-a[i]);
            p1 = u1; p2 = u2;
        }
        cout << max(p1,p2) << "\n";
    }
}