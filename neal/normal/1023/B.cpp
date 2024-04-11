#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    if (k >= 2 * n) {
        cout << 0 << '\n';
    } else if (k > n) {
        long long start = k - n;
        long long count = n - start + 1;

        if (k % 2 == 0)
            count--;

        cout << count / 2 << '\n';
    } else {
        cout << (k - 1) / 2 << '\n';
    }

    return 0;
}