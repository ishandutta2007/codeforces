#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> A, B;
    A.assign(N + M - 1, {});
    B.assign(N + M - 1, {});

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            A[i + j].emplace_back();
            cin >> A[i + j].back();
        }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            B[i + j].emplace_back();
            cin >> B[i + j].back();
        }

    for (int sum = 0; sum < N + M - 1; sum++) {
        sort(A[sum].begin(), A[sum].end());
        sort(B[sum].begin(), B[sum].end());

        if (A[sum] != B[sum]) {
            cout << "NO" << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
}