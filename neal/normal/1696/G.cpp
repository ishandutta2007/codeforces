#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;
 
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
namespace IO {
    const int BUFFER_SIZE = 1 << 15;
 
    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;
 
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
 
    inline void read_double(double &number) {
        bool negative = false;
        number = 0;
 
        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;
 
        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));
 
        if (next_char(false) == '.') {
            next_char();
 
            for (double multiplier = 0.1; isdigit(next_char(false)); multiplier *= 0.1)
                number += multiplier * (next_char() - '0');
        }
 
        if (negative)
            number = -number;
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
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }
 
        if (number != 0 || length == 0)
            write_char(char(number + '0'));
 
        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);
 
        if (after)
            write_char(after);
    }
 
    inline void write_double(double number, char after = '\0', int places = 6) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }
 
        assert(number <= 9e18);
 
        // Round up the number according to places.
        number += 0.5 * pow(0.1, places);
        int64_t floored = int64_t(number);
 
        if (floored <= numeric_limits<int>::max())
            write_int(int(floored));
        else
            write_int(floored);
 
        number -= double(floored);
 
        if (number < 0 || number >= 1)
            number = 0;
 
        if (places > 0) {
            write_char('.');
 
            while (places >= 2) {
                number *= 100;
                int two = int(number);
                number -= two;
                uint8_t lookup_value = lookup[two];
                write_char(char((lookup_value >> 4) + '0'));
                write_char(char((lookup_value & 15) + '0'));
                places -= 2;
            }
 
            if (places == 1) {
                number *= 10;
                int one = int(number);
                write_char(char(one + '0'));
            }
        }
 
        if (after)
            write_char(after);
    }
 
    void init() {
        // Ensures that _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
 
        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}
 
 
using my_double = double;
using matrix = array<array<my_double, 3>, 3>;
 
const my_double D_INF = 1e100;
const matrix NOTHING = {array<my_double, 3>{-D_INF, -D_INF, -D_INF}, {-D_INF, -D_INF, -D_INF}, {-D_INF, -D_INF, -D_INF}};
const matrix IDENTITY = {array<my_double, 3>{0, -D_INF, -D_INF}, {-D_INF, 0, -D_INF}, {-D_INF, -D_INF, 0}};
 
matrix combine(const matrix &a, const matrix &b) {
    matrix combined;
 
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            combined[i][j] = max({a[i][0] + b[0][j], a[i][1] + b[1][j], a[i][2] + b[2][j]});
 
    return combined;
}
 
int X, Y;
 
matrix build(my_double value) {
    return {
        array<my_double, 3>
        {0, value / (X + Y), value / Y},
        {0, value / (X + Y), -D_INF},
        {0, -D_INF, -D_INF},
    };
}
 
 
struct segment {
    matrix transition;
 
    segment(matrix _transition = IDENTITY) : transition(_transition) {}
 
    void join(const segment &other) {
        transition = combine(transition, other.transition);
    }
 
    void join(const segment &a, const segment &b) {
        transition = combine(a.transition, b.transition);
    }
 
    my_double get_answer() const {
        return max({transition[0][0], transition[1][0], transition[2][0]});
    }
};
 
int right_half[32];
 
struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = false;
 
    int tree_n = 0;
    vector<segment> tree;
 
    basic_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }
 
    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;
 
            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }
 
        tree.assign(2 * tree_n, segment());
    }
 
    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);
 
        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];
 
        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }
 
    template<typename T_range_op>
    void process_range(int a, int b, T_range_op &&range_op) const {
        assert(0 <= a && a <= b && b <= tree_n);
        int r_size = 0;
 
        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                range_op(a++);
 
            if (b & 1)
                right_half[r_size++] = --b;
        }
 
        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i]);
    }
 
    segment query(int a, int b) const {
        segment answer;
 
        process_range(a, b, [&](int position) -> void {
            answer.join(tree[position]);
        });
 
        return answer;
    }
 
    segment query_full() const {
        assert(POWER_OF_TWO_MODE);
        return tree[1];
    }
 
    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }
 
    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }
 
    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
 
    // Finds the end of the last subarray starting at `first` satisfying `should_join` via binary search in O(log n).
    template<typename T_bool>
    int find_last_subarray(T_bool &&should_join, int n, int first = 0) const {
        assert(POWER_OF_TWO_MODE);
        assert(0 <= first && first <= n);
        segment current;
 
        // Check the degenerate case.
        if (!should_join(current, current))
            return first - 1;
 
        return y_combinator([&](auto search, int position, int start, int end) -> int {
            if (end <= first) {
                return end;
            } else if (first <= start && end <= n && should_join(current, tree[position])) {
                current.join(tree[position]);
                return end;
            } else if (end - start == 1) {
                return start;
            }
 
            int mid = (start + end) / 2;
            int left = search(2 * position, start, mid);
            return left < mid ? left : search(2 * position + 1, mid, end);
        })(1, 0, tree_n);
    }
};
 
 
int main() {
    IO::init();
 
    int N, Q;
    IO::read_int(N, Q, X, Y);
 
    if (X > Y)
        swap(X, Y);
 
    vector<int> B(N);
 
    for (auto &b : B)
        IO::read_int(b);
 
    basic_seg_tree tree(N);
    vector<segment> initial(N);
 
    for (int i = 0; i < N; i++)
        initial[i] = segment(build(B[i]));
 
    tree.build(initial);
 
    for (int q = 0; q < Q; q++) {
        int type;
        IO::read_int(type);
 
        if (type == 1) {
            int k, v;
            IO::read_int(k, v);
            k--;
            B[k] = v;
            tree.update(k, segment(build(v)));
        } else {
            int L, R;
            IO::read_int(L, R);
            L--;
            array<my_double, 3> dp = {0, 0, 0};
 
            tree.process_range(L, R, [&](int position) -> void {
                matrix mat = tree.tree[position].transition;
                array<my_double, 3> ndp = {-D_INF, -D_INF, -D_INF};
 
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        ndp[j] = max(ndp[j], dp[i] + mat[i][j]);
 
                dp.swap(ndp);
            });
 
            IO::write_double(*max_element(dp.begin(), dp.end()), '\n', 9);
        }
    }
}