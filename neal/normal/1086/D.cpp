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

    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }

    inline void read_char(char &c) {
        while (isspace(next_char(false)))
            next_char();

        c = next_char();
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

    void init() {
        // Make sure _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = (i / 10 << 4) + i % 10;
    }
}


template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    void build(const auto &initial) {
        assert((int) initial.size() == tree_n);

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        T sum = 0;

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the last i in [0, N] such that tree_query(i) <= sum, or -1 if no such i exists.
    int find_last_prefix(T sum) const {
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


const string SHAPES = "RPS";

int N, Q;
string shapes;
vector<fenwick_tree<int>> tree(128);
vector<int> counts(128, 0);

char get_scared(char c) {
    switch(c) {
        case 'R': return 'P';
        case 'P': return 'S';
        case 'S': return 'R';
    }

    assert(false);
}

char get_likes(char c) {
    switch(c) {
        case 'R': return 'S';
        case 'P': return 'R';
        case 'S': return 'P';
    }

    assert(false);
}

int compute_union_count(char piece, int start1, int end1, int start2, int end2) {
    if (end1 - start1 < end2 - start2) {
        swap(start1, start2);
        swap(end1, end2);
    }

    int count = 0;

    if (start1 < end1)
        count += tree[piece].query(start1, end1);

    if (start1 <= start2 && end2 <= end1)
        return count;

    if (start1 <= start2)
        start2 = max(start2, end1);
    else
        end2 = min(end2, start1);

    if (start2 < end2)
        count += tree[piece].query(start2, end2);

    return count;
}

int possible() {
    int total = 0;

    for (char piece : SHAPES) {
        char scared = get_scared(piece);
        char likes = get_likes(piece);
        int count = tree[piece].query(N);

        if (counts[scared] == 0) {
            total += count;
            continue;
        }

        // Find bad locations.
        int left_start = tree[scared].find_last_prefix(0);
        int left_end = counts[likes] == 0 ? N : tree[likes].find_last_prefix(0);

        int right_start = counts[likes] == 0 ? 0 : tree[likes].find_last_prefix(counts[likes] - 1);
        int right_end = tree[scared].find_last_prefix(counts[scared] - 1);

        count -= compute_union_count(piece, left_start, left_end, right_start, right_end);
        total += count;
    }

    return total;
}

int main() {
    IO::init();
    IO::read_int(N, Q);
    IO::read_str(shapes);
    vector<vector<bool>> initial(128);
    initial['R'].assign(N, 0);
    initial['P'].assign(N, 0);
    initial['S'].assign(N, 0);

    for (int i = 0; i < N; i++) {
        counts[shapes[i]]++;
        initial[shapes[i]][i] = 1;
    }

    tree['R'].init(N);
    tree['P'].init(N);
    tree['S'].init(N);
    tree['R'].build(initial['R']);
    tree['P'].build(initial['P']);
    tree['S'].build(initial['S']);

    for (int q = 0; q <= Q; q++) {
        IO::write_int(possible(), '\n');

        if (q < Q) {
            int index;
            char shape;
            IO::read_int(index);
            IO::read_char(shape);
            index--;

            counts[shapes[index]]--;
            tree[shapes[index]].update(index, -1);
            shapes[index] = shape;
            counts[shapes[index]]++;
            tree[shapes[index]].update(index, +1);
        }
    }
}