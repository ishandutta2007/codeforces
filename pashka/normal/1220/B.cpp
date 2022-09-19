#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

long mysqrt(long x) {
    long l = 0;
    long r = 1;
    while (r * r <= x) r *= 2;
    while (r - l > 1) {
        long m = (l + r) / 2;
        if (m * m <= x) l = m; else r = m;
    }
    return l;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        int k = (j + 1) % n;
        cout << mysqrt(1ll * a[i][j] * a[i][k] / a[j][k]) << "\n";
    }

    return 0;
}