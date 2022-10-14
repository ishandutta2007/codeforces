#include <bits/stdc++.h>
using namespace std;
using lint = long long;

inline lint lcm(lint a, lint b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint a, b;
    cin >> a >> b;
    lint ans = 0;

    if (a > b) {
        swap(a, b);
    }

    vector<lint> fact;
    lint d = b - a;
    for (lint i = 1; i * i <= d; i++) {
        if (d % i == 0) {
            fact.emplace_back(i);
            fact.emplace_back(d / i);
        }
    }
    sort(begin(fact), end(fact));
    fact.resize(unique(begin(fact), end(fact)) - begin(fact));

    for (auto f : fact) {
        // gcd(a + k, d) = f
        // f | (a + k)
        lint k = 0;
        if (a % f == 0) {
            k = 0;
        } else {
            k = f - (a % f);
        }
        if ((a + k) * (b + k) / f < (a + ans) * (b + ans) / __gcd(a + ans, b + ans)) {
            ans = k;
        }
    }
    
    cout << ans << "\n";

}