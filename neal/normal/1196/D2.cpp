#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char COLORS[3] = {'R', 'G', 'B'};

int N, K;
string S;

void solve_case() {
    cin >> N >> K >> S;
    vector<vector<int>> changes(N + 1, vector<int>(3, 0));

    for (int i = N - 1; i >= 0; i--)
        for (int c = 0; c < 3; c++)
            changes[i][c] = (S[i] == COLORS[c] ? 0 : 1) + changes[i + 1][(c + 1) % 3];

    int best = N;

    for (int i = 0; i + K <= N; i++)
        for (int c = 0; c < 3; c++)
            best = min(best, changes[i][c] - changes[i + K][(c + K) % 3]);

    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}