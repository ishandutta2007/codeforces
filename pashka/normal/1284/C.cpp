#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<long> f(n + 1);
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1] * i;
        f[i] %= m;
    }

    long res = 0;
    for (int k = 1; k <= n; k++) {
        long x = f[k];
        x *= f[n - k];
        x %= m;
        x *= (n - k + 1);
        x %= m;
        x *= (n - k + 1);
        x %= m;
        res += x;
        res %= m;
    }
    cout << res << "\n";

    return 0;
}