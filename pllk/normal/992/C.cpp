#include <iostream>

using namespace std;

typedef long long ll;

#define M 1000000007LL

ll pot(int a, ll b) {
    if (b == 0) return 1;
    ll x = pot(a,b/2);
    x = (x*x)%M;
    if (b%2 == 1) x = (x*a)%M;
    return x;
}

ll inv(ll x) {
    return pot(x,M-2);
}

int main() {
    ll x, k;
    cin >> x >> k;
    if (x == 0) {
        cout << "0\n";
        return 0;
    }
    x = x%M;
    ll a = (x*pot(2,k+1))%M;
    ll b = (a-pot(2,k+1)+2)%M;
    if (b < 0) b += M;
    ll c = ((a+b)*inv(2))%M;
    cout << c << "\n";
}