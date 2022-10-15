#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool ok = true;
        if (min(a,b) > max(c,d)) ok = false;
        if (min(c,d) > max(a,b)) ok = false;
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
}