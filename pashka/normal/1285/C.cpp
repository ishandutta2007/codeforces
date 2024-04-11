#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long x;
    cin >> x;

    long xx = x;

    vector<long> p;
    for (long i = 2; i * i <= x; i++) {
        long q = 1;
        while (x % i == 0) {
            x /= i;
            q *= i;
        }
        if (q > 1) {
            p.push_back(q);
        }
    }
    if (x > 1) {
        p.push_back(x);
    }

    int n = p.size();
    long resa = xx;
    long resb = 1;
    for (int m = 0; m < (1 << n); m++) {
        long s = 1;
        for (int i = 0; i < n; i++) {
            if ((m >> i) & 1) {
                s *= p[i];
            }
        }
        if (s < xx / s) continue;
        if (s < resa) {
            resa = s;
            resb = xx / s;
        }
    }
    cout << resa << " " << resb << "\n";


    return 0;
}