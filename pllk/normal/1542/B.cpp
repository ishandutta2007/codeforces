#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll x = 1;
        bool f = false;
        while (x <= n) {
            if (x%b == n%b) f = true;
            x *= a;
            if (a == 1) break;
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
}