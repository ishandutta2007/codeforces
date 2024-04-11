#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
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

    inline void read_str(string &str) {
        while (isspace(next_char(false)))
            next_char();

        str.clear();

        do {
            str += next_char();
        } while (!isspace(next_char(false)));
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

    inline void write_str(const string &str, char after = '\0') {
        for (char c : str)
            write_char(c);

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


const int INF = 1e9 + 5;

struct prefix_min_fenwick_tree {
    int tree_n;
    vector<int> tree;

    prefix_min_fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, INF);
    }

    // index is in [0, tree_n).
    void update(int index, int value) {
        assert(0 <= index && index < tree_n);

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] = min(tree[i], value);
    }

    // Returns the min of the range [0, count).
    int query(int count) const {
        assert(count <= tree_n);
        int result = INF;

        for (int i = count; i > 0; i -= i & -i)
            result = min(result, tree[i]);

        return result;
    }
};


bool compare_last(const array<int, 3> &x, const array<int, 3> &y) {
    return x[2] < y[2];
}

struct query {
    array<int, 3> location;
    int index;

    bool operator<(const query &other) const {
        return compare_last(location, other.location);
    }
};

const int MAX = 1e5 + 5;

int N, M, K;
array<int, 3> store_min, store_max;
vector<string> answers;

void convert(array<int, 3> &location) {
    for (int d = 0; d < 3; d++)
        if (location[d] < store_min[d])
            location[d] -= store_min[d];
        else if (location[d] > store_max[d])
            location[d] -= store_max[d];
        else
            location[d] = 0;
}

prefix_min_fenwick_tree tree[2][2];

void solve(vector<array<int, 3>> &closed, vector<query> &queries) {
    for (array<int, 3> &cl : closed)
        cl[2] = abs(cl[2]);

    for (query &q : queries)
        q.location[2] = abs(q.location[2]);

    sort(closed.begin(), closed.end(), compare_last);
    sort(queries.begin(), queries.end());

    for (int x = 0; x < 2; x++)
        for (int y = 0; y < 2; y++)
            tree[x][y].init(x == 0 ? MAX - store_max[0] : store_min[0] + 5);

    size_t c = 0;

    for (query &q : queries) {
        while (c < closed.size() && closed[c][2] <= q.location[2]) {
            for (int x = 0; x < 2; x++)
                if ((x == 0 ? +1 : -1) * closed[c][0] >= 0)
                    for (int y = 0; y < 2; y++)
                        if ((y == 0 ? +1 : -1) * closed[c][1] >= 0)
                            tree[x][y].update(abs(closed[c][0]), abs(closed[c][1]));

            c++;
        }

        if (q.location[0] == 0 && q.location[1] == 0 && q.location[2] == 0) {
            answers[q.index] = "OPEN";
        } else {
            int minimum = tree[q.location[0] < 0][q.location[1] < 0].query(abs(q.location[0]) + 1);
            answers[q.index] = abs(q.location[1]) < minimum ? "UNKNOWN" : "CLOSED";
        }
    }
}

vector<array<int, 3>> closed[2];
vector<query> queries[2];

int main() {
    IO::init();

    int _;
    IO::read_int(_, _, _, N, M, K);

    for (int d = 0; d < 3; d++) {
        store_min[d] = INF;
        store_max[d] = -INF;
    }

    for (int i = 0; i < N; i++)
        for (int d = 0; d < 3; d++) {
            int v;
            IO::read_int(v);
            store_min[d] = min(store_min[d], v);
            store_max[d] = max(store_max[d], v);
        }

    for (int i = 0; i < M; i++) {
        array<int, 3> location;
        IO::read_int(location[0], location[1], location[2]);
        convert(location);

        if (location[0] == 0 && location[1] == 0 && location[2] == 0) {
            IO::write_str("INCORRECT", '\n');
            return 0;
        }

        for (int z = 0; z < 2; z++)
            if ((z == 0 ? +1 : -1) * location[2] >= 0)
                closed[z].push_back(location);
    }

    IO::write_str("CORRECT", '\n');

    for (int i = 0; i < K; i++) {
        query q;
        IO::read_int(q.location[0], q.location[1], q.location[2]);
        convert(q.location);
        q.index = i;
        queries[q.location[2] < 0].push_back(q);
    }

    answers.resize(K);
    solve(closed[0], queries[0]);
    solve(closed[1], queries[1]);

    for (int i = 0; i < K; i++)
        IO::write_str(answers[i], '\n');
}