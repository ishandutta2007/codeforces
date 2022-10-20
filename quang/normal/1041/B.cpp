#include <bits/stdc++.h>

using namespace std;

long long a, b, x, y;

int main() {
    cin >> a >> b >> x >> y;
    long long foo = __gcd(x, y);
    x /= foo;
    y /= foo;
    long long aa = a / x;
    long long bb = b / y;
    cout << min(aa, bb) << endl;
    return 0;
}