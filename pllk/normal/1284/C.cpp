#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll m;
ll f[1222333];

int main() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= 1000000; i++) f[i] = f[i-1]*i%m;
    ll s = 0;
    for (int k = 1; k <= n; k++) {
        ll u = f[k]*(n-k+1)%m*(n-k+1)%m*f[n-k]%m;
        s = (s+u)%m;
    }
    cout << s << "\n";
}