#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long r;
    cin >> r;
    for (long x = 1; x * x <= r; x++) {
        long c = r - x * x - x - 1;
        if (c > 0 && c % (2 * x) == 0) {
            cout << x << " " << (c / (2 * x));
            return 0;
        }
    }
    cout << "NO";

    return 0;
}