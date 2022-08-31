#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> A;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.assign(N, vector<int>(M, 0));

    for (vector<int> &row : A)
        for (int &elem : row)
            cin >> elem;

    vector<vector<bool>> good(N, vector<bool>(M, false));
    vector<pair<int, int>> ops;

    for (int i = 0; i + 1 < N; i++)
        for (int j = 0; j + 1 < M; j++)
            if (A[i][j] == 1 && A[i][j + 1] == 1 && A[i + 1][j] == 1 && A[i + 1][j + 1] == 1) {
                good[i][j] = good[i][j + 1] = good[i + 1][j] = good[i + 1][j + 1] = true;
                ops.emplace_back(i, j);
            }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (A[i][j] == 1 && !good[i][j]) {
                cout << -1 << '\n';
                return 0;
            }

    cout << ops.size() << '\n';

    for (pair<int, int> &p : ops)
        cout << p.first + 1 << ' ' << p.second + 1 << '\n';
}