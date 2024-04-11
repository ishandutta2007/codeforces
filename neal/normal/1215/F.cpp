#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[100];
    uint8_t lookup[100];

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }

    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }

    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            _flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = (lookup_value & 15) + '0';
            number_buffer[length++] = (lookup_value >> 4) + '0';
        }

        if (number != 0 || length == 0)
            write_char(number + '0');

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


struct two_sat {
    int n = 0;
    vector<vector<int>> adj;
    vector<bool> assignment;

    int inv(int var) {
        return var ^ 1;
    }

    int new_var() {
        adj.emplace_back();
        adj.emplace_back();
        return 2 * n++;
    }

    void implies(int a, int b) {
        adj[a].push_back(b);
        adj[inv(b)].push_back(inv(a));
    }

    void either(int a, int b) {
        adj[inv(a)].push_back(b);
        adj[inv(b)].push_back(a);
    }

    void set_value(int a) {
        adj[inv(a)].push_back(a);
    }

    void equal(int a, int b) {
        implies(a, b);
        implies(inv(a), inv(b));
    }

    void unequal(int a, int b) {
        implies(a, inv(b));
        implies(inv(a), b);
    }

    // Warning: this only creates an implication in the negative direction. It is still possible for
    // a = b = true with and_var = false. In particular, it does not work to call set_value on inv(and_var).
    int create_and(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(result, a);
        implies(result, b);
        return result;
    }

    // Warning: this only creates an implication in the positive direction. It is still possible for
    // a = b = false with or_var = true. In particular, it does not work to call set_value on or_var.
    int create_or(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        int result = new_var();
        implies(a, result);
        implies(b, result);
        return result;
    }

    int create_at_most_one(int a, int b) {
        if (a < 0 || b < 0) return max(a, b);
        either(inv(a), inv(b));
        return create_or(a, b);
    }

    template<typename T_iterable>
    int create_at_most_one(const T_iterable &vars) {
        int aux = -1;

        for (int var : vars)
            aux = create_at_most_one(aux, var);

        return aux;
    }

    bool solve() {
        assignment.assign(2 * n, false);
        vector<bool> vis[2];
        vector<int> q[2];
        vis[0].assign(2 * n, false);
        vis[1].assign(2 * n, false);
        q[0].resize(2 * n);
        q[1].resize(2 * n);

        for (int i = 0; i < n; i++) {
            if (!assignment[2 * i] && !assignment[2 * i + 1]) {
                // we have to do the search
                bool bad[2] = {false, false};
                int qs[2] = {0, 0};
                int qi[2] = {0, 0};
                int qt[2] = {0, 0};

                for (int z = 0; z < 2; z++) {
                    vis[z][2 * i + z] = true;
                    q[z][qt[z]++] = 2 * i + z;
                }

                while (true) {
                    if (bad[0] && bad[1])
                        return false;

                    for (int z = 0; z < 2; z++) {
                        if (bad[z])
                            continue;

                        if (qs[z] >= qt[z]) {
                            // we're done, so we should finalize it
                            for (int ind = 0; ind < qt[z]; ind++)
                                assignment[q[z][ind]] = true;

                            bad[!z] = true;
                            goto done;
                        }

                        int v = q[z][qs[z]];

                        if (qi[z] == int(adj[v].size())) {
                            qs[z]++;
                            qi[z] = 0;
                            continue;
                        }

                        int u = adj[v][qi[z]];
                        assert(!assignment[inv(u)]);

                        if (vis[z][inv(u)]) {
                            bad[z] = true;
                        } else if (!assignment[u] && !vis[z][u]) {
                            vis[z][u] = true;
                            q[z][qt[z]++] = u;
                        }

                        qi[z]++;
                    }
                }

done:
                assert(bad[0] ^ bad[1]);

                // reset vis
                for (int z = 0; z < 2; z++)
                    for (int ind = 0; ind < qt[z]; ind++)
                        vis[z][q[z][ind]] = false;
            }

            assert(assignment[2 * i] ^ assignment[2 * i + 1]);
        }

        return true;
    }
};


template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<> ostream& operator<<(ostream &os, const vector<string> &v) { os << "{"; for (vector<string>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << "\"" << *vi << "\""; } os << "}"; return os; }

struct power_signal {
    int L, R, index;

    bool operator<(const power_signal &other) const {
        return L < other.L;
    }
};

int N, R, M, C;
vector<power_signal> power, original;

int main() {
    IO::init();

    IO::read_int(N, R, M, C);
    two_sat TS;
    vector<int> radio_var(R);

    for (int i = 0; i < R; i++)
        radio_var[i] = TS.new_var();

    for (int i = 0; i < N; i++) {
        int x, y;
        IO::read_int(x, y);
        x--; y--;
        TS.either(radio_var[x], radio_var[y]);
    }

    power.resize(R);

    for (int i = 0; i < R; i++) {
        IO::read_int(power[i].L, power[i].R);
        power[i].index = i;
    }

    original = power;
    sort(power.begin(), power.end());

    for (int i = 0; i < C; i++) {
        int u, v;
        IO::read_int(u, v);
        u--; v--;
        TS.either(TS.inv(radio_var[u]), TS.inv(radio_var[v]));
    }

    vector<int> or_var(R + 1, -1);

    for (int i = R - 1; i >= 0; i--)
        or_var[i] = TS.create_or(or_var[i + 1], radio_var[power[i].index]);

    for (int i = 0; i < R; i++) {
        power_signal search = {original[i].R + 1, -1, -1};
        int index = lower_bound(power.begin(), power.end(), search) - power.begin();

        if (index < R)
            TS.implies(or_var[index], TS.inv(radio_var[i]));
    }

    if (!TS.solve()) {
        cout << -1 << '\n';
        return 0;
    }

    int minimum = 1, maximum = M;
    vector<int> contracts;

    for (int i = 0; i < R; i++)
        if (TS.assignment[radio_var[i]]) {
            contracts.push_back(i);
            minimum = max(minimum, original[i].L);
            maximum = min(maximum, original[i].R);
        }

    IO::write_int(contracts.size(), ' ');
    IO::write_int(minimum, '\n');

    for (int i = 0; i < (int) contracts.size(); i++)
        IO::write_int(contracts[i] + 1, i < (int) contracts.size() - 1 ? ' ' : '\n');
}