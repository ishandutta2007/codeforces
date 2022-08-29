#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

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
}


const int MAX = 60;
const int SG_MAX = 3;

int N, X, Y, Z;
vector<int> SG[3];
int period[3];

int get_SG(int a, long long n) {
    if (n <= MAX)
        return SG[a][n];

    n = MAX - period[a] + (n - MAX) % period[a];
    return SG[a][n];
}

int compute_end_period(const vector<int> &v) {
    for (int p = 1; ; p++) {
        bool works = true;

        for (int i = MAX / 2; i + p <= MAX; i++)
            if (v[i] != v[i + p]) {
                works = false;
                break;
            }

        if (works)
            return p;
    }
}

void precompute() {
    for (int a = 0; a < 3; a++)
        SG[a].assign(MAX + 1, 0);

    for (int n = 1; n <= MAX; n++)
        for (int a = 0; a < 3; a++) {
            vector<bool> seen(SG_MAX + 1, false);

            seen[SG[0][max(n - X, 0)]] = true;
            if (a != 1) seen[SG[1][max(n - Y, 0)]] = true;
            if (a != 2) seen[SG[2][max(n - Z, 0)]] = true;

            SG[a][n] = 0;

            while (seen[SG[a][n]])
                SG[a][n]++;
        }

    for (int a = 0; a < 3; a++)
        period[a] = compute_end_period(SG[a]);
}

vector<long long> A;

void run_case() {
    IO::read_int(N, X, Y, Z);
    precompute();
    dbg(period[0], period[1], period[2]);
    A.resize(N);

    for (long long &a : A)
        IO::read_int(a);

    int overall_SG = 0;

    for (long long &a : A)
        overall_SG ^= get_SG(0, a);

    int total = 0;

    for (long long &a : A) {
        overall_SG ^= get_SG(0, a);

        total += (overall_SG ^ get_SG(0, max(a - X, 0LL))) == 0;
        total += (overall_SG ^ get_SG(1, max(a - Y, 0LL))) == 0;
        total += (overall_SG ^ get_SG(2, max(a - Z, 0LL))) == 0;

        overall_SG ^= get_SG(0, a);
    }

    printf("%d\n", total);
}

int main() {
    int tests;
    IO::read_int(tests);

    while (tests-- > 0)
        run_case();
}