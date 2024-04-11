#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int digit_sum(long long n) {
    int sum = 0;

    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main() {
    long long N;
    cin >> N;
    long long x = 0;
    int best = 0;

    while (x <= N) {
        best = max(best, digit_sum(x) + digit_sum(N - x));
        x = 10 * x + 9;
    }

    cout << best << '\n';
}