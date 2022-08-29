#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

long long fibonacci(int n) {
    long long a = 1, b = 1;

    for (int i = 0; i < n; i++) {
        long long c = (a + b) % MOD;
        a = b;
        b = c;
    }

    return a;
}

int main() {
    int N, M;
    cin >> N >> M;
    long long answer = 2 * (fibonacci(N) + fibonacci(M)) - 2;
    answer = (answer % MOD + MOD) % MOD;
    cout << answer << '\n';
}