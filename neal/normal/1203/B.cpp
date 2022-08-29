#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N;
    cin >> N;
    vector<int> A(4 * N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());

    for (int i = 0; i < 4 * N; i += 2)
        if (A[i] != A[i + 1]) {
            cout << "NO" << '\n';
            return;
        }

    int product = A[0] * A[4 * N - 1];

    for (int i = 0; i < 2 * N; i++)
        if (product != A[i] * A[4 * N - 1 - i]) {
            cout << "NO" << '\n';
            return;
        }

    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}