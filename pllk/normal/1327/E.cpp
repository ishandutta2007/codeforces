#include <iostream>

using namespace std;

#define M 998244353

typedef long long ll;

ll pot(ll a, ll b) {
    if (b == 0) return 1;
    ll u = pot(a,b/2);
    u = u*u%M;
    if (b%2 == 1) u = u*a%M;
    return u;
}

int main() {
    ll n;
    cin >> n;
    for (int i = 1; i <= n-1; i++) {
        ll u = 0;
        u += 2*10*9*pot(10,n-i-1)%M;
        u %= M;
        u += (n-i-1)*10*9*9*pot(10,n-i-2)%M;
        u %= M;
        cout << u << " ";
    }
    cout << "10\n";
}