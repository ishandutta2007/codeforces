#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iostream>
#include <random>
#include <string>
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

    inline void write_str(const string &str) {
        for (char c : str)
            write_char(c);
    }

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
    }
}


const int N_MAX = 1e5 + 5;
const int REQ_CUTOFF = 40;
const double TIME_CUTOFF = 0.01;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

int N, R;
vector<int> A;
vector<vector<int>> requirements;
int8_t group[N_MAX];

vector<int> factorize(int n) {
    vector<int> factors;

    for (int p = 2; p * p <= n; p++)
        if (n % p == 0) {
            factors.push_back(p);

            do {
                n /= p;
            } while (n % p == 0);
        }

    return factors;
}

int main() {
    IO::init();

    IO::read_int(N);
    A.resize(N);

    for (int &a : A)
        IO::read_int(a);

    vector<int> factors;

    for (int i = 0; i < min(N, REQ_CUTOFF); i++) {
        vector<int> current = factorize(A[i]);
        factors.insert(factors.end(), current.begin(), current.end());
    }

    sort(factors.begin(), factors.end());
    factors.resize(unique(factors.begin(), factors.end()) - factors.begin());

    for (int p : factors) {
        vector<int> requirement;

        for (int i = 0; i < N && requirement.size() < REQ_CUTOFF; i++)
            if (A[i] % p != 0)
                requirement.push_back(i);

        // If at most one number is missing a prime, we cannot prevent the prime from showing up in both groups.
        if (requirement.size() <= 1) {
            IO::write_str("NO\n");
            return 0;
        }

        if (requirement.size() < REQ_CUTOFF) {
            requirements.push_back(requirement);

            for (int &a : A)
                while (a % p == 0)
                    a /= p;
        }
    }

    // Sort by length.
    sort(requirements.begin(), requirements.end(), [](const vector<int> &a, const vector<int> &b) {
        return a.size() < b.size();
    });

    R = requirements.size();
    memset(group, -1, sizeof(group));
    long double begin = clock();

    while ((clock() - begin) / CLOCKS_PER_SEC < TIME_CUTOFF) {
        bool bad = false;
        int r;

        for (r = 0; r < R; r++) {
            bool seen[2] = {false, false};
            int last_unassigned = -1;

            for (int x : requirements[r])
                if (group[x] < 0)
                    last_unassigned = x;
                else
                    seen[group[x]] = true;

            for (int x : requirements[r]) {
                if (x == last_unassigned) {
                    // If our last element with a choice must be either missing group, take it.
                    if (!seen[0])
                        group[x] = 0;
                    else if (!seen[1])
                        group[x] = 1;
                }

                if (group[x] < 0)
                    group[x] = rng() % 2;

                seen[group[x]] = true;
            }

            if (!seen[0] || !seen[1]) {
                bad = true;
                break;
            }
        }

        if (bad) {
            while (r >= 0) {
                for (int x : requirements[r])
                    group[x] = -1;

                r--;
            }

            continue;
        }

        for (int i = 0; i < N; i++)
            if (group[i] < 0)
                group[i] = rng() % 2;

        int g[2] = {0, 0};

        for (int i = 0; i < N; i++)
            g[group[i]] = __gcd(g[group[i]], A[i]);

        if (g[0] == 1 && g[1] == 1) {
            IO::write_str("YES\n");

            for (int i = 0; i < N; i++) {
                IO::write_char(group[i] + 1 + '0');
                IO::write_char(i < N - 1 ? ' ' : '\n');
            }

            return 0;
        }

        memset(group, -1, sizeof(group));
    }

    IO::write_str("NO\n");
}