#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, Q;
vector<vector<int>> one_prefix;
vector<string> matrix;

long long one_count(long long n) {
    // long long count = 0;

    // for (long long i = 0; i < n; i++)
    //     count += __builtin_popcountll(i) % 2;

    // return count;
    long long count = n / 2;

    if (n & 1)
        count += __builtin_popcountll(n - 1) % 2;

    return count;
}

long long solve_one(long long x, long long y, int me) {
    long long sum = one_count(x) * (y - one_count(y)) + one_count(y) * (x - one_count(x));

    if (me == 1)
        sum = x * y - sum;

    return sum;
}

long long combine(long long x, long long y, long long one, long long zero) {
    return solve_one(x, y, 1) * one + solve_one(x, y, 0) * zero;
}

long long solve(long long x, long long y) {
    int x_mod = x % N;
    int y_mod = y % M;

    long long one = one_prefix[x_mod][y_mod];
    long long answer = combine(x / N + 1, y / M + 1, one, x_mod * y_mod - one);

    one = one_prefix[N][y_mod] - one_prefix[x_mod][y_mod];
    answer += combine(x / N, y / M + 1, one, (N - x_mod) * y_mod - one);

    one = one_prefix[x_mod][M] - one_prefix[x_mod][y_mod];
    answer += combine(x / N + 1, y / M, one, x_mod * (M - y_mod) - one);

    one = one_prefix[N][M] - one_prefix[x_mod][M] - one_prefix[N][y_mod] + one_prefix[x_mod][y_mod];
    answer += combine(x / N, y / M, one, (N - x_mod) * (M - y_mod) - one);

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> Q;
    matrix.resize(N);

    for (string &row : matrix)
        cin >> row;

    one_prefix.assign(N + 1, vector<int>(M + 1, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            one_prefix[i + 1][j + 1] = one_prefix[i + 1][j] + one_prefix[i][j + 1] - one_prefix[i][j] + (matrix[i][j] - '0');

    for (int q = 0; q < Q; q++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--;
        cout << solve(x2, y2) - solve(x1, y2) - solve(x2, y1) + solve(x1, y1) << '\n';
    }
}