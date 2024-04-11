#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';

    for (int i = 0; i < 2 * N; i++) {
        int number = 2 * (i % N) + 1;

        if (((i % N) % 2 == 0) ^ (i < N))
            number++;

        cout << number << (i < 2 * N - 1 ? ' ' : '\n');
    }
}