#include <iostream>

#define ll long long
#define M 1000000009

using namespace std;

ll n, m, k;

ll pot(int n) {
    if (n == 0) return 1;
    if (n == 1) return 2;
    if (n%2 == 1) return (2*pot(n-1))%M;
    ll x = pot(n/2);
    return (x*x)%M;
}

int main() {
    cin >> n >> m >> k;
    if (k*(n-m) >= n) {
        cout << m << endl;
        return 0;
    }
    ll a = n-k*(n-m);
    ll b = a/k;
    ll c = a%k;
    ll t = ((pot(b+1)-2+M)*k)%M;
    if (b == 0) t = 0;
    t += c;
    t += (k-1)*(n-m);
    t %= M;
    cout << t << endl;
}