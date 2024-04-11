#include <iostream>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b,a%b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll m, d, w;
        cin >> m >> d >> w;
        ll r = min(m,d);
        ll g = w/gcd(d-1,w);
        ll q = r/g;
        ll u = r*q-g*(q*(q+1))/2;
        cout << u << "\n";
    }
}