#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    long long sum = 0;

    for (int i = 0; i < N; i++) {
        sum += A[i];

        if (sum <= 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    sum = 0;

    for (int i = N - 1; i >= 0; i--) {
        sum += A[i];

        if (sum <= 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}