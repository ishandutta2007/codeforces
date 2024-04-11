#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        int a = 0, b = 0, c = 0;
        if (x == y && y == z) {
            a = b = c = x;
        } else if (x == y && x > z) {
            a = x;
            b = c = z;
        } else if (x == z && x > y) {
            b = x;
            a = c = y;
        } else if (y == z && y > x) {
            c = y;
            a = b = x;
        }
        if (a != 0) {
            cout << "YES\n";
            cout << a << " " << b << " " << c << "\n";
        } else {
            cout << "NO\n";
        }
    }
}