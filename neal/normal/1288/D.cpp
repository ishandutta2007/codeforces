#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, M;
vector<vector<int>> A;

pair<int, int> solve(int threshold) {
    vector<int> exists(1 << M, -1);

    for (int i = 0; i < N; i++) {
        int mask = 0;

        for (int j = 0; j < M; j++)
            mask |= (A[i][j] >= threshold) << j;

        exists[mask] = i;
    }

    for (int mask = 0; mask < 1 << M; mask++)
        for (int other = 0; other < 1 << M; other++)
            if ((mask | other) == (1 << M) - 1 && exists[mask] >= 0 && exists[other] >= 0)
                return {exists[mask], exists[other]};

    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.assign(N, vector<int>(M));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    int low = 0, high = INF;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (solve(mid).first >= 0)
            low = mid;
        else
            high = mid - 1;
    }

    pair<int, int> answer = solve(low);
    cout << answer.first + 1 << ' ' << answer.second + 1 << '\n';
}