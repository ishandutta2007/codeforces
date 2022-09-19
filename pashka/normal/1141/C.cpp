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
    vector<long> a(n - 1);
    for (int i = 0; i < n - 1; i++) cin >> a[i];
    long x = 0;
    long s = 0;
    for (int i = 0; i < n - 1; i++) {
        x += a[i];
        s += x;
    }
    long ss = 1ll * n * (n + 1) / 2;
    vector<long> b(n);
    b[0] = (ss - s) / n;
    for (int i = 1; i < n; i++) {
        b[i] = b[i - 1] + a[i - 1];
    }
    vector<long> c = b;
    sort(c.begin(), c.end());
    for (int i = 0; i < n; i++) {
        if (c[i] != i + 1) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}