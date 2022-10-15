#include <iostream>

#define ll long long int

using namespace std;

ll x, y, m;

int main() {
    cin >> x >> y >> m;
    if (x >= m || y >= m) {
        cout << 0 << endl;
        return 0;
    }
    ll v = 0;
    if (x < 0 && y > 0) {
        ll b = (y-x)/y;
        v += b;
        x += y*b;
    }
    if (y < 0 && x > 0) {
        ll b = (x-y)/x;
        v += b;
        y += x*b;
    }
    for (int i = 0; i < 10000; i++) {
        v++;
        ll s = x+y;
        if (x < y) x = s;
        else y = s;
        if (x >= m || y >= m) {
            cout << v << endl;
            return 0;
        }
        if (x < 0 && y < 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}