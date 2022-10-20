#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    long long res = 0;
    for (int i = 2; 1ll * i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            res = __gcd(res, 1ll * i);
        }
    }
    if (n > 1) res = __gcd(res, n);
    cout << res << endl;
    return 0;
}