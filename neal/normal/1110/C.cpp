#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool is_power_of_two(int n) {
    return (n & (n - 1)) == 0;
}

int smallest_factor(int n) {
    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return i;

    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0) {
        int A;
        cin >> A;

        if (is_power_of_two(A + 1)) {
            cout << A / smallest_factor(A) << '\n';
        } else {
            cout << (1 << (32 - __builtin_clz(A))) - 1 << '\n';
        }
    }
}