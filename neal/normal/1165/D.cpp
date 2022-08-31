#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long D_MAX = 1e6 + 5;

void solve_case() {
    int N;
    cin >> N;
    vector<long long> divisors(N);

    for (auto &d : divisors)
        cin >> d;

    sort(divisors.begin(), divisors.end());
    long long x = 1;

    for (auto d : divisors) {
        x = x / __gcd(x, d) * d;

        if (x > D_MAX * D_MAX)
            break;
    }

    // Prime power
    if (x == divisors.back())
        x *= divisors.front();

    if (x > D_MAX * D_MAX) {
        cout << -1 << '\n';
        return;
    }

    size_t count = 0;

    for (long long d = 2; d * d <= x; d++)
        if (x % d == 0) {
            count++;

            if (d * d < x)
                count++;
        }

    if (count != divisors.size()) {
        cout << -1 << '\n';
        return;
    }

    cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}