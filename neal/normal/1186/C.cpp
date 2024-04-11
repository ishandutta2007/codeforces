#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;
    int N = A.size(), M = B.size();
    vector<int> A_sum(N + 1, 0), B_sum(M + 1, 0);

    for (int i = 0; i < N; i++)
        A_sum[i + 1] = A_sum[i] + (A[i] - '0');

    for (int i = 0; i < M; i++)
        B_sum[i + 1] = B_sum[i] + (B[i] - '0');

    int answer = 0;

    for (int i = 0; i + M <= N; i++) {
        int sum = A_sum[i + M] - A_sum[i] + B_sum[M];

        if (sum % 2 == 0)
            answer++;
    }

    cout << answer << '\n';
}