#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;
const int N_MAX = 24;
const int A_MAX = 50005;

int N;
vector<int> A;
vector<vector<bitset<N_MAX * A_MAX>>> possible;

int main() {
    cin >> N;
    A.resize(2 * N);

    for (int &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    int first_min = A.front(); A.erase(A.begin());
    int second_min = A.front(); A.erase(A.begin());
    N--;

    possible.assign(2 * N + 1, {});

    for (int i = 0; i <= 2 * N; i++)
        possible[i].assign(min(i, N) + 1, {});

    possible[0][0] = 1;

    for (int i = 0; i < 2 * N; i++)
        for (int k = min(i, N); k >= 0; k--) {
            possible[i + 1][k] = possible[i][k];

            if (k < N)
                possible[i + 1][k + 1] |= possible[i][k] << A[i];
        }

    int sum = accumulate(A.begin(), A.end(), 0) / 2;

    while (!possible[2 * N][N][sum])
        sum--;

    vector<int> rows[2];
    rows[0] = {first_min};
    rows[1] = {second_min};
    int half = N;

    for (int i = 2 * N - 1; i >= 0; i--) {
        if (half > 0 && sum >= A[i] && possible[i][half - 1][sum - A[i]]) {
            rows[0].push_back(A[i]);
            half--;
            sum -= A[i];
        } else {
            rows[1].push_back(A[i]);
        }

        assert(possible[i][half][sum]);
    }

    assert(half == 0 && sum == 0);
    sort(rows[0].begin(), rows[0].end());
    sort(rows[1].rbegin(), rows[1].rend());

    for (int r = 0; r < 2; r++)
        for (int i = 0; i <= N; i++)
            cout << rows[r][i] << (i < N ? ' ' : '\n');
}