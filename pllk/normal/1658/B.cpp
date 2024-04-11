#include <iostream>

using namespace std;
using ll = long long;

#define M 998244353

ll f[1001];

int main() {
    f[0] = 1;
    for (int i = 1; i <= 1000; i++) f[i] = f[i-1]*i%M;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n%2 == 1) cout << 0 << "\n";
        else cout << f[n/2]*f[n/2]%M << "\n";
    }
}