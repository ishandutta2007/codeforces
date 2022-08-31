#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<int N_MAX>
struct gaussian_binary {
    int n;
    vector<bitset<N_MAX>> coefficients;
    vector<bool> values;
    bool solve_called = false;

    gaussian_binary(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        coefficients = {};
        values = {};
    }

    void print() const {
        cerr << n << " vars, " << coefficients.size() << " equations" << endl;

        for (int i = 0; i < int(coefficients.size()); i++) {
            string coefs = coefficients[i].to_string().substr(N_MAX - n);
            reverse(coefs.begin(), coefs.end());
            cerr << coefs << ": " << values[i] << endl;
        }
    }

    template<typename T_coefs>
    void add_equation(const T_coefs &coefs, bool value) {
        assert(int(coefs.size()) >= n);
        bitset<N_MAX> b_coefs;

        for (int i = 0; i < n; i++)
            b_coefs[i] = coefs[i];

        coefficients.push_back(b_coefs);
        values.push_back(value);
    }

    void swap_rows(int a, int b) {
        swap(coefficients[a], coefficients[b]);
        swap(values[a], values[b]);
    }

    // Eliminates `coefficients[target][col]` by canceling the `target` row with the `source` row.
    void eliminate(int target, int source, int col) {
        if (coefficients[target][col] == 0)
            return;

        assert(coefficients[source][col] != 0);
        coefficients[target] ^= coefficients[source];
        values[target] = values[target] ^ values[source];
    }

    bitset<N_MAX> solve() {
        solve_called = true;
        int rows = int(coefficients.size());
        vector<int> row_for_column(n, -1);
        int current_row = 0;

        for (int i = 0; i < n; i++) {
            int on_row = -1;

            for (int row = current_row; row < rows; row++)
                if (coefficients[row][i] != 0) {
                    on_row = row;
                    break;
                }

            if (current_row >= rows || on_row < 0)
                continue;

            swap_rows(on_row, current_row);
            row_for_column[i] = current_row;

            for (int row = current_row + 1; row < rows; row++)
                eliminate(row, current_row, i);

            current_row++;
        }

        bitset<N_MAX> answers;

        for (int i = n - 1; i >= 0; i--) {
            if (row_for_column[i] < 0)
                continue;

            current_row = row_for_column[i];

            for (int j = 0; j < i; j++)
                assert(coefficients[current_row][j] == 0);

            answers[i] = values[current_row] ^ ((coefficients[current_row] & answers).count() % 2);
        }

        return answers;
    }

    // Returns -1 if there are no solutions; otherwise returns the rank. rank = r means there are 2^(n - r) solutions.
    int rank() const {
        assert(solve_called);
        int count = 0;

        for (int i = 0; i < int(coefficients.size()); i++) {
            if (values[i] && coefficients[i].none())
                return -1;

            count += coefficients[i].any();
        }

        return count;
    }

    bool invalid() const {
        return rank() < 0;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    static const int VAR_MAX = 2005;

    auto &&color_to_index = [](char color) {
        switch (color) {
            case 'W': return 0;
            case 'R': return 1;
            case 'Y': return 2;
            case 'B': return 3;
            default: assert(false);
        }
    };

    auto &&index_to_color = [](int index) {
        switch (index) {
            case 0: return '.';
            case 1: return 'R';
            case 2: return 'Y';
            case 3: return 'B';
            default: assert(false);
        }
    };

    int N, K;
    cin >> N >> K;
    gaussian_binary<VAR_MAX> solver(2 * N);
    vector<array<bitset<2>, 2>> vars(N);

    for (int i = 0; i < N; i++)
        vars[i][0][0] = vars[i][1][1] = 1;

    for (int t = 0; t < K; t++) {
        string op;
        int m;
        cin >> op >> m;
        vector<int> indices(m);

        for (int &index : indices) {
            cin >> index;
            index--;
        }

        if (op == "mix") {
            char result;
            cin >> result;
            int result_index = color_to_index(result);

            for (int x = 0; x < 2; x++) {
                bitset<VAR_MAX> coefs;

                for (int index : indices) {
                    coefs[2 * index] = vars[index][x][0];
                    coefs[2 * index + 1] = vars[index][x][1];
                }

                solver.add_equation(coefs, result_index >> x & 1);
            }
        } else if (op == "RB") {
            for (int x : indices)
                vars[x][1] ^= vars[x][0];
        } else if (op == "YB") {
            for (int x : indices)
                vars[x][0] ^= vars[x][1];
        } else if (op == "RY") {
            for (int x : indices)
                swap(vars[x][0], vars[x][1]);
        } else {
            assert(false);
        }
    }

    // solver.print();
    bitset<VAR_MAX> answers = solver.solve();

    if (solver.invalid()) {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';

    for (int i = 0; i < N; i++) {
        int value = answers[2 * i] + 2 * answers[2 * i + 1];
        cout << index_to_color(value);
    }

    cout << '\n';
}