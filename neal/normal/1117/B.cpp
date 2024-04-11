#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

long long N, M, K;
vector<long long> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    A.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i];

    nth_element(A.begin(), A.begin() + N - 2, A.end());
    cout << A[N - 1] * (M - M / (K + 1)) + A[N - 2] * (M / (K + 1)) << '\n';
}