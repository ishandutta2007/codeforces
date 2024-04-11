#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 4096;
    const int NUMBER_BUFFER = 100;

    FILE *input_stream = stdin;
    FILE *output_stream = stdout;

    int input_pos = BUFFER_SIZE;
    int input_read = BUFFER_SIZE;

    int output_pos = 0;

    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];

    char number_buffer[NUMBER_BUFFER];

    void init(const char *input_file, const char *output_file) {
        input_stream = fopen(input_file, "r");
        output_stream = fopen(output_file, "w");
    }

    void _update_input_buffer() {
        if (input_pos >= input_read && input_read == BUFFER_SIZE) {
            input_read = fread(input_buffer, sizeof(char), BUFFER_SIZE, input_stream);
            input_pos = 0;
        }
    }

    char next_char(bool advance = true) {
        _update_input_buffer();
        return input_buffer[advance ? input_pos++ : input_pos];
    }

    bool on_whitespace() {
        return isspace(next_char(false));
    }

    bool on_digit() {
        return isdigit(next_char(false));
    }

    void skip_whitespace() {
        while (on_whitespace())
            next_char();
    }

    bool input_finished() {
        skip_whitespace();
        return input_pos >= input_read && input_read < BUFFER_SIZE;
    }

    long long next_int() {
        skip_whitespace();
        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        long long number = 0;

        while (on_digit())
            number = 10 * number + (next_char() - '0');

        return negative ? -number : number;
    }

    double next_double() {
        skip_whitespace();
        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        double number = 0;

        while (on_digit())
            number = 10 * number + (next_char() - '0');

        if (next_char(false) == '.') {
            next_char();

            for (double multiplier = 0.1; on_digit(); multiplier *= 0.1)
                number += multiplier * (next_char() - '0');
        }

        return negative ? -number : number;
    }

    void read_str(char *str) {
        skip_whitespace();

        while (!on_whitespace())
            *str++ = next_char();

        *str = '\0';
    }

    void read_line(char *str) {
        while (next_char(false) == '\n')
            next_char();

        while (next_char(false) != '\n')
            *str++ = next_char();

        *str = '\0';
    }

    void flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, output_stream);
        output_pos = 0;
    }

    void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            flush_output();

        output_buffer[output_pos++] = c;
    }

    void write_int(long long number, char after = 0) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        do {
            number_buffer[length++] = number % 10 + '0';
            number /= 10;
        } while (number > 0);

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    void write_str(const char *str, char after = 0) {
        while (*str)
            write_char(*str++);

        if (after)
            write_char(after);
    }

    void write_double(double number, char after = 0, int places = 6) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        assert(number <= 9e18);

        // Round up the number according to places.
        number += 0.5 * pow(0.1, places);
        long long floored = (long long) number;
        write_int(floored);

        if (places > 0) {
            write_char('.');
            number = (number - floored) * pow(10.0, places);
            floored = (long long) number;

            for (int i = 0; i < places; i++) {
                number_buffer[i] = floored % 10 + '0';
                floored /= 10;
            }

            for (int i = places - 1; i >= 0; i--)
                write_char(number_buffer[i]);
        }

        if (after)
            write_char(after);
    }

    // Make sure flush_output() is called at the end of the program.
    struct Dummy {
        ~Dummy() {
            flush_output();
        }
    } dummy;
}


struct union_find {
    vector<int> parent;
    vector<uint8_t> rank;
    bool use_rank;

    union_find(int n = 0, bool _use_rank = true) : use_rank(_use_rank) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);

        for (int i = 0; i <= n; i++)
            parent[i] = i;

        if (use_rank)
            rank = vector<uint8_t>(n + 1, 0);
    }

    int find(int x) {
        return x == parent[x] ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (!use_rank || rank[x] < rank[y]) {
            parent[x] = y;
        } else {
            parent[y] = x;

            if (rank[x] == rank[y])
                rank[x]++;
        }

        return true;
    }
};

const int N_MAX = 5e5 + 5, LOG = 19;
const int INF = 1e9 + 5;

int N, K, M;
int depth[N_MAX];
int ancestor[LOG][N_MAX];
vector<int> adj[N_MAX];
vector<array<int, 3>> queries;

void add_edge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
}

void dfs(int node, int parent) {
    ancestor[0][node] = parent;
    depth[node] = parent == -1 ? 0 : depth[parent] + 1;

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node);
}

int lca(int a, int b) {
    if (depth[a] > depth[b])
        swap(a, b);

    for (int k = 0; k < LOG; k++)
        if ((depth[b] - depth[a]) & 1 << k)
            b = ancestor[k][b];

    if (a == b)
        return a;

    assert(a != b && depth[a] == depth[b]);

    for (int k = LOG - 1; k >= 0; k--)
        if (ancestor[k][a] != ancestor[k][b]) {
            a = ancestor[k][a];
            b = ancestor[k][b];
        }

    assert(ancestor[0][a] == ancestor[0][b]);
    return ancestor[0][a];
}

int mark_path(int node, int common, union_find &weight_uf) {
    int edges = 0;

    while (true) {
        node = weight_uf.find(node);

        if (depth[node] <= depth[common])
            break;

        edges++;
        weight_uf.unite(node, ancestor[0][node]);
    }

    return edges;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    N = IO::next_int();
    K = IO::next_int();
    M = IO::next_int();
    union_find uf(N);

    for (int i = 0; i < K; i++) {
        int a = IO::next_int(), b = IO::next_int();
        a--; b--;
        add_edge(a, b);
        uf.unite(a, b);
    }

    long long answer = 0;

    for (int i = 0; i < M; i++) {
        int a = IO::next_int(), b = IO::next_int(), w = IO::next_int();
        a--; b--;
        queries.push_back({a, b, w});

        if (uf.unite(a, b)) {
            add_edge(a, b);
            answer -= w;
        }
    }

    for (int i = 0; i < N; i++)
        ancestor[0][i] = -1;

    dfs(0, -1);

    for (int k = 0; k + 1 < LOG; k++)
        for (int i = 0; i < N; i++)
            ancestor[k + 1][i] = ancestor[k][i] == -1 ? -1 : ancestor[k][ancestor[k][i]];

    union_find weight_uf(N, false);
    int edges = 0;

    for (auto &query : queries) {
        int a = query[0], b = query[1], w = query[2];
        int common = lca(a, b);
        int new_edges = mark_path(a, common, weight_uf) + mark_path(b, common, weight_uf);
        edges += new_edges;
        answer += (long long) w * new_edges;
    }

    cout << (edges == N - 1 ? answer : -1) << '\n';
    return 0;
}