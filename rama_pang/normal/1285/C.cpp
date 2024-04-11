#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint n, x;
    cin >> n;
    x = n;
    vector<lint> mul;
    lint ans[2] = {1, n};

    vector<pair<lint, lint>> primeFactors;
    for (lint i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            lint a = i, b = n / i;
            if (__gcd(a, b) == 1) {
                if (max(ans[0], ans[1]) > max(a, b)) {
                    ans[0] = a;
                    ans[1] = b;
                }
            }
        }
    }

    cout << ans[0] << " " << ans[1] << "\n";
    return 0;
}

// 40200