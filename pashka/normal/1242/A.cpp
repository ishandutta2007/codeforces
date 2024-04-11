#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long n;
    cin >> n;
    for (long d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            while (n % d == 0) {
                n /= d;
            }
            if (n == 1) {
                cout << d << "\n";
            } else {
                cout << 1 << "\n";
            }
            return 0;
        }
    }
    cout << n << "\n";

    return 0;
}