#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

struct mod_matrix {
    static const uint64_t ULL_BOUND = numeric_limits<uint64_t>::max() - (uint64_t) MOD * MOD;

    int rows, cols;
    vector<vector<int>> values;

    mod_matrix(int r = -1, int c = -1) : rows(r), cols(c) {
        if (cols < 0)
            cols = rows;

        if (rows > 0)
            values.assign(rows, vector<int>(cols, 0));
    }

    mod_matrix(const vector<vector<int>> &v) {
        assert(!v.empty());
        values = v;
        rows = v.size();
        cols = v[0].size();
    }

    bool is_square() const {
        return rows == cols;
    }

    void make_identity() {
        assert(is_square());

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                values[i][j] = i == j ? 1 : 0;
    }

    void clean_values() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                values[i][j] = (values[i][j] % MOD + MOD) % MOD;
    }

    mod_matrix operator*(mod_matrix &other) {
        assert(cols == other.rows);
        clean_values();
        other.clean_values();

        mod_matrix product(rows, other.cols);
        vector<uint64_t> row;

        for (int i = 0; i < rows; i++) {
            row.assign(other.cols, 0);

            for (int j = 0; j < cols; j++)
                if (values[i][j] != 0)
                    for (int k = 0; k < other.cols; k++) {
                        row[k] += (uint64_t) values[i][j] * other.values[j][k];

                        if (row[k] > ULL_BOUND)
                            row[k] %= MOD;
                    }

            for (int k = 0; k < other.cols; k++)
                product.values[i][k] = row[k] % MOD;
        }

        return product;
    }

    mod_matrix& operator*=(mod_matrix &other) {
        assert(other.is_square() && cols == other.rows);
        return *this = *this * other;
    }

    mod_matrix power(long long p) {
        assert(is_square());
        mod_matrix result(rows), temp = *this;
        result.make_identity();

        while (p > 0) {
            if (p & 1)
                result *= temp;

            if (p > 1)
                temp *= temp;

            p >>= 1;
        }

        return result;
    }

    void print() {
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                cerr << values[i][j] << (j < cols - 1 ? ' ' : '\n');
    }
};

int main() {
    long long N, M;
    cin >> N >> M;

    mod_matrix vec(M, 1);

    for (int i = 0; i < M; i++)
        vec.values[i][0] = 1;

    mod_matrix transition(M, M);
    transition.values[M - 1][0] = transition.values[M - 1][M - 1] = 1;

    for (int i = 0; i < M - 1; i++)
        transition.values[i][i + 1] = 1;

    vec = transition.power(N) * vec;
    cout << vec.values[0][0] << '\n';
}