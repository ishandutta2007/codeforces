#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    long long N, M;
    cin >> N >> M;
    long long numbers = N / M;
    long long sum = 0;

    for (int i = 1; i <= 10; i++) {
        long long digit = M * i % 10;
        long long count = numbers / 10 + (numbers % 10 >= i ? 1 : 0);
        sum += count * digit;
    }

    cout << sum << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}