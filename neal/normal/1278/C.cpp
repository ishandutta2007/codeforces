#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

void run_case() {
    int N;
    cin >> N;
    vector<int> A(2 * N);

    for (int &a : A)
        cin >> a;

    vector<int> prefix_diff(N + 1, 0);
    vector<int> suffix_diff(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_diff[i + 1] = prefix_diff[i] + (A[i] == 1 ? +1 : -1);

    for (int i = N - 1; i >= 0; i--)
        suffix_diff[i] = suffix_diff[i + 1] + (A[N + i] == 1 ? -1 : +1);

    vector<int> latest(2 * N + 1, -INF);

    for (int i = 0; i <= N; i++)
        latest[N + prefix_diff[i]] = i;

    int best = INF;

    for (int i = 0; i <= N; i++)
        best = min(best, i + N - latest[N + suffix_diff[i]]);

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        run_case();
}