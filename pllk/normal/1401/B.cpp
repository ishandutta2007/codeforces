#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x1, y1, z1;
        cin >> x1 >> y1 >> z1;
        ll x2, y2, z2;
        cin >> x2 >> y2 >> z2;
        ll s = 0;
        ll u = min(z1,y2); // 21
        s += 2*u;
        z1 -= u; y2 -= u;
        u = min(y1,x2); // 10
        y1 -= u; x2 -= u;
        u = min(y1,y2); // 11
        y1 -= u; y2 -= u;
        u = min(y1,z2); // 12
        s -= 2*u;
        cout << s << "\n";
    }
}