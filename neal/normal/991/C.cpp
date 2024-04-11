#include <iostream>
using namespace std;

long long eats(long long n, long long k) {
    long long count = 0;

    while (n > 0) {
        long long vasya = min(n, k);
        n -= vasya;
        count += vasya;

        n -= n / 10;
    }

    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    long long low = 1, high = n;

    while (low < high) {
        long long mid = (low + high) / 2;

        if (2 * eats(n, mid) >= n)
            high = mid;
        else
            low = mid + 1;
    }

    cout << low << '\n';
    return 0;
}