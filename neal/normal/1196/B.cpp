#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    int N, K;
    cin >> N >> K;
    vector<int> A(N);

    for (int &a : A)
        cin >> a;

    vector<int> ends;

    for (int i = 0; i < N; i++)
        if (A[i] % 2 == 1)
            ends.push_back(i + 1);

    if (ends.empty() || (int) ends.size() < K || ends.size() % 2 != K % 2) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';

    for (int i = 0; i < K - 1; i++)
        cout << ends[i] << ' ';

    cout << N << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}