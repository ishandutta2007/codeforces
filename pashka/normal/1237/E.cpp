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

    int n;
    cin >> n;
    int k = 1;
    int c = 0;
    while (k <= n) {
        if (k == n || k + 1 == n) {
            cout << 1;
            return 0;
        }
        k = k * 2 + 1;
        if (c == 0) {
            k++;
        }
        c ^= 1;
    }
    cout << 0;

    return 0;
}