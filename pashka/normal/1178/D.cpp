#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

bool prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int m = n; m <= n + n / 2; m++) {
        if (prime(m)) {
            cout << m << "\n";
            for (int i = 0; i < n; i++) {
                cout << i + 1 << " " << ((i + 1) % n + 1) << "\n";
            }
            for (int i = 0; i < m - n; i++) {
                cout << i + 1 << " " << ((i + n / 2) + 1) << "\n";
            }
            ///

            return 0;
        }
    }


    return 0;
}