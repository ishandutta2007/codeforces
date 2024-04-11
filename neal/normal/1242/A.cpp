#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<uint64_t, int>> factorize(uint64_t n) {
    vector<pair<uint64_t, int>> result;

    for (uint64_t p = 2; p * p <= n; p++)
        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}

int main() {
    long long N;
    cin >> N;
    vector<pair<uint64_t, int>> factors = factorize(N);

    if (factors.size() == 1)
        cout << factors.front().first << '\n';
    else
        cout << 1 << '\n';
}