#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

template<typename T, bool maximum_mode>
struct monotonic_rmq {
    deque<pair<T, int>> values;
    int current_index = 0;

    bool better(const T &a, const T &b) const {
        return (a < b) ^ maximum_mode;
    }

    // Adds a value and returns its index.
    int add(const T &x) {
        while (!values.empty() && !better(values.back().first, x))
            values.pop_back();

        values.emplace_back(x, current_index);
        return current_index++;
    }

    // Queries for the maximum (minimum) with index at least the given `index`.
    T query(int index) {
        while (values.front().second < index)
            values.pop_front();

        assert(!values.empty());
        return values.front().first;
    }
};

vector<int> screen(const vector<int> &row, int k) {
    int n = row.size();
    monotonic_rmq<int, false> rmq;
    vector<int> screened;

    for (int i = 0; i < n; i++) {
        rmq.add(row[i]);

        if (i >= k - 1)
            screened.push_back(rmq.query(i - (k - 1)));
    }

    return screened;
}

int main() {
    int N, M, A, B;
    long long G, X, Y, Z;
    cin >> N >> M >> A >> B;
    cin >> G >> X >> Y >> Z;
    vector<vector<int>> matrix;

    for (int i = 0; i < N; i++) {
        vector<int> row;

        for (int j = 0; j < M; j++) {
            row.push_back(G);
            G = (G * X + Y) % Z;
        }

        matrix.push_back(screen(row, B));
    }

    vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));

    for (int i = 0; i < (int) matrix.size(); i++)
        for (int j = 0; j < (int) matrix[i].size(); j++)
            transposed[j][i] = matrix[i][j];

    long long total = 0;

    for (int i = 0; i < (int) transposed.size(); i++) {
        transposed[i] = screen(transposed[i], A);
        total += accumulate(transposed[i].begin(), transposed[i].end(), 0LL);
    }

    cout << total << '\n';
}