#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int digit_product(int n) {
    int p = 1;

    while (n != 0) {
        p *= n % 10;
        n /= 10;
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    N++;

    int best = 0;
    int p = 1;

    while (N != 0) {
        best = max(best, digit_product(N * p - 1));
        N /= 10;
        p *= 10;
    }

    cout << best << '\n';
}