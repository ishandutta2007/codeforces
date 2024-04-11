#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    sort(A.rbegin(), A.rend());
    vector<long long> jump_sum(N + M + 1, 0);

    for (int i = N - 1; i >= 0; i--)
        jump_sum[i] = A[i] + jump_sum[i + M];

    long long sum = 0;

    for (int i = N - 1; i >= 0; i--) {
        sum += jump_sum[i];
        cout << sum << (i > 0 ? ' ' : '\n');
    }
}