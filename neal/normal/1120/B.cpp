#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int LIMIT = 1e5;

int N;
vector<long long> A, B, original;
vector<long long> operations_at;
vector<pair<int, int>> operations;

bool can_do(int d, int s) {
    assert(s == +1 || s == -1);
    assert(0 <= d && d < N);

    if (s == +1)
        return A[d] < 9;
    else
        return A[d] > (d == 0 ? 1 : 0);
}

bool both_can_do(int d, int s) {
    assert(s == +1 || s == -1);
    assert(0 <= d && d < N - 1);

    if (s == +1)
        return A[d] < 9 && A[d + 1] < 9;
    else
        return A[d] > (d == 0 ? 1 : 0) && A[d + 1] > 0;
}

void compute_ops(int index) {
    if (index < 0 || index >= N - 1)
        return;

    while ((int) operations.size() < LIMIT && operations_at[index] != 0) {
        int op = operations_at[index] > 0 ? +1 : -1;

        if (both_can_do(index, op)) {
            // cerr << "Applying " << op << " at " << index << endl;
            operations.emplace_back(index, op);
            A[index] += op;
            A[index + 1] += op;
            operations_at[index] -= op;
        } else {
            if (!can_do(index, op))
                compute_ops(index - 1);
            else
                compute_ops(index + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S1, S2;
    cin >> N >> S1 >> S2;
    A.resize(N);
    B.resize(N);
    operations_at.assign(N, 0);
    long long a_sum = 0, b_sum = 0;

    for (int i = 0; i < N; i++) {
        A[i] = S1[i] - '0';
        B[i] = S2[i] - '0';
        a_sum += (i % 2 == 0 ? +1 : -1) * A[i];
        b_sum += (i % 2 == 0 ? +1 : -1) * B[i];
    }

    if (a_sum != b_sum) {
        cout << -1 << '\n';
        return 0;
    }

    original = A;

    for (int i = 0; i < N - 1; i++) {
        long long difference = B[i] - A[i];
        A[i] += difference;
        A[i + 1] += difference;
        operations_at[i] += difference;
    }

    if (A.back() != B.back()) {
        cout << -1 << '\n';
        return 0;
    }

    assert(A.back() == B.back());
    long long total_ops = 0;

    for (int i = 0; i < N; i++)
        total_ops += abs(operations_at[i]);

    cout << total_ops << '\n';
    A = original;

    for (int i = 0; i < N - 1; i++)
        compute_ops(i);

    int output = min((int) operations.size(), LIMIT);

    for (int i = 0; i < output; i++)
        cout << operations[i].first + 1 << ' ' << operations[i].second << '\n';
}