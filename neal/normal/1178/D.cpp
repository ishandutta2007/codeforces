#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    if (n < 2)
        return false;

    for (int p = 2; p * p <= n; p++)
        if (n % p == 0)
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int M = N;

    while (!prime(M))
        M++;

    assert(M <= N + N / 2);
    cout << M << '\n';

    for (int i = 0; i < N; i++)
        cout << i + 1 << ' ' << (i + 1) % N + 1 << '\n';

    for (int i = 0; i < M - N; i++)
        cout << i + 1 << ' ' << i + N / 2 + 1 << '\n';
}