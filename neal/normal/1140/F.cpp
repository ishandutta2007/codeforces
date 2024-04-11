#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

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

struct safe_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = splitmix64(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        return splitmix64(x ^ FIXED_RANDOM);
    }
};

template<typename T_pair>
struct safe_pair32_hash {
    size_t operator()(const T_pair &x) const {
        assert(sizeof(x.first) <= 4 && sizeof(x.second) <= 4);
        static safe_hash hash_obj;
        return hash_obj(((uint64_t) x.first << 32) ^ x.second);
    }
};

const int INF = 1e9 + 5;

struct dynamic_connectivity {
    struct undo_op {
        int x, y, y_parent;

        undo_op(int _x = -INF, int _y = -INF, int _y_parent = -INF) : x(_x), y(_y), y_parent(_y_parent) {}
    };

    struct dc_union_find {
        vector<int> parent;
        vector<pair<int, int>> size;
        long long combined = 0;

        dc_union_find(int n = 0) {
            if (n > 0)
                init(n);
        }

        void init(int n) {
            parent.resize(2 * n);
            size.resize(2 * n);
            combined = 0;

            for (int i = 0; i < 2 * n; i++) {
                parent[i] = i;
                size[i] = i < n ? make_pair(1, 0) : make_pair(0, 1);
            }
        }

        int find(int x) {
            while (x != parent[x])
                x = parent[x];

            return x;
        }

        int size_sum(int x) const {
            return size[x].first + size[x].second;
        }

        bool unite(int x, int y, vector<undo_op> &undo_ops) {
            x = find(x);
            y = find(y);

            if (x == y)
                return false;

            if (size_sum(x) < size_sum(y))
                swap(x, y);

            undo_ops.emplace_back(x, y, parent[y]);
            parent[y] = x;
            combined += (long long) size[x].first * size[y].second + (long long) size[y].first * size[x].second;
            size[x].first += size[y].first;
            size[x].second += size[y].second;
            return true;
        }

        void undo(const undo_op &op) {
            size[op.x].first -= size[op.y].first;
            size[op.x].second -= size[op.y].second;
            combined -= (long long) size[op.x].first * size[op.y].second + (long long) size[op.y].first * size[op.x].second;
            parent[op.y] = op.y_parent;
        }
    };

    struct query {
        // type = +1: add, type = -1: erase, type = 0: answer
        int type, x, y, other_index;

        query(int _type = -INF, int _x = -INF, int _y = -INF, int _other_index = INF)
            : type(_type), x(_x), y(_y), other_index(_other_index) {}
    };

    vector<query> queries;
    gp_hash_table<pair<int, int>, int, safe_pair32_hash<pair<int, int>>> seen_table;
    dc_union_find UF;
    vector<undo_op> undo_ops;
    vector<long long> answers;

    void recurse(int start, int end) {
        if (end - start <= 1) {
            if (end - start == 1 && queries[start].type == 0)
                answers.push_back(UF.combined);

            return;
        }

        int mid = (start + end) / 2;
        size_t initial_size = undo_ops.size();

        for (int i = mid; i < end; i++)
            if (queries[i].type == -1 && queries[i].other_index < start)
                UF.unite(queries[i].x, queries[i].y, undo_ops);

        recurse(start, mid);

        while (undo_ops.size() > initial_size) {
            UF.undo(undo_ops.back());
            undo_ops.pop_back();
        }

        for (int i = start; i < mid; i++)
            if (queries[i].type == +1 && queries[i].other_index >= end)
                UF.unite(queries[i].x, queries[i].y, undo_ops);

        recurse(mid, end);

        while (undo_ops.size() > initial_size) {
            UF.undo(undo_ops.back());
            undo_ops.pop_back();
        }
    }

    void add_query() {
        queries.emplace_back(0);
    }

    void add_edge_op(int x, int y) {
        if (x > y)
            swap(x, y);

        if (seen_table.find({x, y}) == seen_table.end()) {
            seen_table[{x, y}] = queries.size();
            queries.emplace_back(+1, x, y, INF);
        } else {
            int index = seen_table[{x, y}];
            seen_table.erase({x, y});
            queries[index].other_index = queries.size();
            queries.emplace_back(-1, x, y, index);
        }
    }

    vector<long long> solve(int n) {
        UF.init(n);
        recurse(0, queries.size());
        return answers;
    }
};


const int N = 3e5 + 5;

int main() {
    IO::init();
    int Q;
    IO::read_int(Q);
    dynamic_connectivity dc;

    for (int i = 0; i < Q; i++) {
        int x, y;
        IO::read_int(x, y);
        x--; y--;
        dc.add_edge_op(x, y + N);
        dc.add_query();
    }

    auto answers = dc.solve(N);

    for (int i = 0; i < Q; i++)
        IO::write_int(answers[i], i < Q - 1 ? ' ' : '\n');
}