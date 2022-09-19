#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    long n;
    cin >> n;
    n--;
    int nc = n % 3;
    n /= 3;
    long z = 1;
    int p = 0;
    while (n >= z) {
        n -= z;
        p += 2;
        z *= 4;
    }
    if (nc == 0) {
        cout << ((1ll << p) + n);
    } else if (nc == 1) {
        long res = (2ll << p);
        for (int i = 0; i < p / 2; i++) {
            res ^= ((n >> (2 * i)) & 1) << (2 * i + 1);
            res ^= ((n >> (2 * i + 1)) & 1) << (2 * i + 1);
            res ^= ((n >> (2 * i + 1)) & 1) << (2 * i);
        }
        cout << res;
    } else {
        long res = (3ll << p);
        for (int i = 0; i < p / 2; i++) {
            res ^= ((n >> (2 * i)) & 1) << (2 * i);
            res ^= ((n >> (2 * i)) & 1) << (2 * i + 1);
            res ^= ((n >> (2 * i + 1)) & 1) << (2 * i);
        }
        cout << res;
    }

    cout << "\n";


}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}