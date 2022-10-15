#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        ll f = 1;
        ll u = 1;
        ll c = 1;
        int r = 0;
        while (f <= x) {
            r++;
            c *= 4;
            u = 2*u+c;
            f += u;
        }
        cout << r << "\n";
    }
}