#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long X;
    cin >> X;
    long long ans1 = 0, ans2 = 0;

    for (long long p = 1; p * p <= X; p++)
        if (X % p == 0) {
            long long q = X / p;

            if (__gcd(p, q) == 1) {
                ans1 = p;
                ans2 = q;
            }
        }

    cout << ans1 << ' ' << ans2 << '\n';
}