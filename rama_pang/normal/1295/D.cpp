#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#define all(x) begin(x), end(x)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int Tc;
    cin >> Tc;
    while (Tc--) {
        lint a, b;
        cin >> a >> b;

        lint g = __gcd(a, b);
        a /= g;
        b /= g;
        lint totient = b;
        
        vector<lint> primes;
        for (lint f = 2; f * f <= b; f++) {
            while (b % f == 0) {
                primes.emplace_back(f);
                b /= f;
            }
        }
        if (b > 1) {
            primes.emplace_back(b);
        }
        sort(all(primes));
        primes.resize(unique(all(primes)) - begin(primes));
        
        for (auto &p : primes) {
            totient -= totient / p;
        }

        cout << totient << "\n";
    }
}