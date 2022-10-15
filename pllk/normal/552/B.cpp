#include <iostream>

#define ll long long

using namespace std;

ll n;
ll c;

int main() {
    cin >> n;
    ll x = 1;
    int z = 1;
    while (n >= x) {
        ll r = min(x*10-1,n);
        c += (r-x+1)*z;
        x *= 10;
        z++;
    }
    cout << c << "\n";
}