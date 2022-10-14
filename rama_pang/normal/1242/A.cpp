#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    lint N;
    cin >> N;
    vector<lint> factors;
    for (lint i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            while (N % i == 0) {
                N = N / i;
            }
            factors.emplace_back(i);
        }
    }

    if (N > 1) {
        factors.emplace_back(N);
    }

    if (factors.size() == 1) {
        cout << factors[0] << "\n";
    } else {
        cout << 1 << "\n";
    }
}