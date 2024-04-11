#include <iostream>

using namespace std;

typedef long long ll;

#define M 1000000007

ll pot(ll a, ll b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u = (u*u)%M;
    if (b%2 == 1) u *= a;
    u %= M;
    return u;
}

ll inv(ll x) {
    return pot(x,M-2);
}

int k;

int main() {
    cin >> k;
    ll u = 1, w = 1;
    int z = 0;
    ll h = 1;
    for (int i = 0; i < k; i++) {
        ll a;
        cin >> a;
        if (a%2 == 0) z = 1;
        a %= (M-1);
        h *= a;
        h %= (M-1);
    }
    u *= pot(2,h);
    u %= M;
    w *= pot(2,h);
    w %= M;
    if (z == 0) u++;
    else u--;
    if (u < 0) u += M;
    u %= M;
    u *= inv(3);
    u %= M;
    if (z == 0) u--;
    else u++;
    if (u < 0) u += M;
    u %= M;
    u *= inv(2);
    w *= inv(2);
    u %= M;
    w %= M;
    cout << u << "/" << w << "\n";
}