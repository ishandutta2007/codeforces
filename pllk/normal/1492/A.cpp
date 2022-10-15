#include <iostream>

using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll p, a, b, c;
        cin >> p >> a >> b >> c;
        ll ta = p%a == 0 ? 0 : a-p%a;
        ll tb = p%b == 0 ? 0 : b-p%b;
        ll tc = p%c == 0 ? 0 : c-p%c;
        cout << min(ta,min(tb,tc)) << "\n";
    }
}