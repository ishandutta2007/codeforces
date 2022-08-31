#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T>
struct compressed_2D_array {
    int n, m;
    vector<T> data;

    compressed_2D_array(int _n = 0, int _m = 0, T default_value = 0) {
        init(_n, _m, default_value);
    }

    void init(int _n, int _m, T default_value = 0) {
        n = _n;
        m = _m;
        data.assign(n * m, default_value);
    }

    const T& operator()(int row, int col) const {
        return data[row * m + col];
    }

    T& operator()(int row, int col) {
        return data[row * m + col];
    }
};

const char BURN = 'X';
const char EMPTY = '.';

int N, M;
compressed_2D_array<char> forest;
compressed_2D_array<int> forest_sums;
compressed_2D_array<char> start_grid;
compressed_2D_array<int> start_sums;

int query_sums(const compressed_2D_array<int> &sums, int r1, int r2, int c1, int c2) {
    return sums(r2, c2) - sums(r2, c1) - sums(r1, c2) + sums(r1, c1);
}

void build_rectangle_sums(const compressed_2D_array<char> &grid, compressed_2D_array<int> &sums) {
    sums.init(N + 1, M + 1, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            sums(i + 1, j + 1) = sums(i + 1, j) + sums(i, j + 1) - sums(i, j) + (grid(i, j) == BURN);
}

void build_start_grid(int T) {
    start_grid.init(N, M, EMPTY);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int r1 = i - T;
            int r2 = i + T + 1;
            int c1 = j - T;
            int c2 = j + T + 1;

            if (0 <= r1 && r1 < r2 && r2 <= N && 0 <= c1 && c1 < c2 && c2 <= M) {
                long long area = (long long) (r2 - r1) * (c2 - c1);

                if (query_sums(forest_sums, r1, r2, c1, c2) == area)
                    start_grid(i, j) = BURN;
            }
        }
}

bool possible(int T) {
    build_start_grid(T);
    build_rectangle_sums(start_grid, start_sums);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (forest(i, j) == BURN) {
                int r1 = max(i - T, 0);
                int r2 = min(i + T + 1, N);
                int c1 = max(j - T, 0);
                int c2 = min(j + T + 1, M);

                if (query_sums(start_sums, r1, r2, c1, c2) == 0)
                    return false;
            }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    forest.init(N, M);
    string row;

    for (int i = 0; i < N; i++) {
        cin >> row;

        for (int j = 0; j < M; j++)
            forest(i, j) = row[j];
    }

    build_rectangle_sums(forest, forest_sums);
    int low = 0, high = min(N, M) / 2;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (possible(mid))
            low = mid;
        else
            high = mid - 1;
    }

    cout << low << '\n';
    build_start_grid(low);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            cout << start_grid(i, j);

        cout << '\n';
    }
}