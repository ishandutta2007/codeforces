#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    long long n;
    cin >> n;

    for (long long a = 2; a * a * a < n; a++)
        if (n % a == 0) {
            long long m = n / a;

            for (long long b = a + 1; b * b < m; b++)
                if (m % b == 0) {
                    cout << "YES" << '\n';
                    cout << a << ' ' << b << ' ' << m / b << '\n';
                    return;
                }
        }

    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}