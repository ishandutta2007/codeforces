#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

int N;
vector<long long> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    B.resize(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    for (int i = 0; i < N; i++) {
        A[i] *= i + 1;
        A[i] *= N - i;
    }

    sort(A.begin(), A.end());
    sort(B.rbegin(), B.rend());
    long long total = 0;

    for (int i = 0; i < N; i++)
        total = (total + A[i] % MOD * B[i]) % MOD;

    cout << total << '\n';
}