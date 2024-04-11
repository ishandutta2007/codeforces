#include <iostream>

#define ll long long int

using namespace std;

ll a, b;
ll x = 1;

int main() {
    cin >> a >> b;
    while (b >= 2*x) x *= 2;
    while ((a & x) == (b & x) && x > 0) x /= 2;
    if (x == 0) cout << 0 << endl;
    else cout << 2*x-1 << endl;
}