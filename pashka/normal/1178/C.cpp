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

    int n, m;
    cin >> n >> m;
    long res = 4;
    long MOD = 998244353;
    for (int i = 0; i < n - 1; i++) {
        res *= 2;
        res %= MOD;
    }
    for (int i = 0; i < m - 1; i++) {
        res *= 2;
        res %= MOD;
    }
    cout << res << "\n";

    return 0;
}