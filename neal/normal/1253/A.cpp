#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A, B;

void solve_case() {
    cin >> N;
    A.resize(N);
    B.resize(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    if (A == B) {
        cout << "YES" << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
        A[i] = B[i] - A[i];

    if (*min_element(A.begin(), A.end()) < 0) {
        cout << "NO" << '\n';
        return;
    }

    int first = -1, last = -1;

    for (int i = 0; i < N; i++)
        if (A[i] > 0) {
            if (first < 0)
                first = i;

            last = i;
        }

    for (int i = first; i <= last; i++)
        if (A[i] != A[first]) {
            cout << "NO" << '\n';
            return;
        }

    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}