#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

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

const int MOD = 1e9 + 7;

struct mod_int {
    int val;

    mod_int(long long v = 0) {
        if (v < 0) v = v % MOD + MOD;
        if (v >= MOD) v %= MOD;
        val = v;
    }

    explicit operator int() const {
        return val;
    }

    mod_int& operator+=(const mod_int &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }

    mod_int& operator-=(const mod_int &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }

    static unsigned fast_mod(uint64_t x, unsigned m = MOD) {
#if !defined(_WIN32) || defined(_WIN64)
        return x % m;
#endif
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in a 32-bit integer.
        unsigned x_high = x >> 32, x_low = (unsigned) x;
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mod_int& operator*=(const mod_int &other) {
        val = fast_mod((uint64_t) val * other.val);
        return *this;
    }

    mod_int& operator/=(const mod_int &other) {
        return *this *= other.inv();
    }

    friend mod_int operator+(const mod_int &a, const mod_int &b) { return mod_int(a) += b; }
    friend mod_int operator-(const mod_int &a, const mod_int &b) { return mod_int(a) -= b; }
    friend mod_int operator*(const mod_int &a, const mod_int &b) { return mod_int(a) *= b; }
    friend mod_int operator/(const mod_int &a, const mod_int &b) { return mod_int(a) /= b; }

    mod_int& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }

    mod_int& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }

    mod_int operator++(int) { mod_int before = *this; ++*this; return before; }
    mod_int operator--(int) { mod_int before = *this; --*this; return before; }

    mod_int operator-() const {
        return val == 0 ? 0 : MOD - val;
    }

    bool operator==(const mod_int &other) const { return val == other.val; }
    bool operator!=(const mod_int &other) const { return val != other.val; }

    mod_int inv() const;

    mod_int pow(long long p) const {
        assert(p >= 0);
        mod_int a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }

        return result;
    }

    friend ostream& operator<<(ostream &stream, const mod_int &m) {
        return stream << m.val;
    }
};

const int SAVE_INV = 1e5 + 5;

mod_int save_inv[SAVE_INV];

void prepare_save() {
    // Make sure MOD is prime, which is necessary for the inverse algorithm below.
    for (int p = 2; p * p <= MOD; p++)
        assert(MOD % p != 0);

    save_inv[0] = 0;
    save_inv[1] = 1;

    for (int i = 2; i < SAVE_INV; i++)
        save_inv[i] = save_inv[MOD % i] * (MOD - MOD / i);
}

mod_int mod_int::inv() const {
    if (save_inv[1] == 0)
        prepare_save();

    if (val < SAVE_INV)
        return save_inv[val];

    mod_int product = 1;
    int v = val;

    while (v >= SAVE_INV) {
        product *= MOD - MOD / v;
        v = MOD % v;
    }

    return product * save_inv[v];
}

struct segment_change {
    mod_int to_add;

    segment_change(mod_int _to_add = 0) : to_add(_to_add) {}

    void reset() {
        to_add = 0;
    }

    bool has_change() const {
        return to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    mod_int sum = 0;

    segment(mod_int _sum = 0) : sum(_sum) {}

    void apply(int length, const segment_change &change) {
        if (change.to_add != 0)
            sum += length * change.to_add;
    }

    void join(const segment &other) {
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = initial.size();
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    void push_down(int position, int length) {
        if (!changes[position].has_change())
            return;

        if (2 * position < tree_n) {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);

            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};

struct heavy_light {
    int n = 0;
    bool vertex_mode;

    vector<vector<int>> adj;
    vector<int> parent, depth, subtree_size;

    vector<int> chain_root, chain_size;
    vector<seg_tree> chain_tree;

    heavy_light() {}

    heavy_light(int _n, bool _vertex_mode) {
        init(_n, _vertex_mode);
    }

    void init(int _n, bool _vertex_mode) {
        n = _n;
        vertex_mode = _vertex_mode;

        adj.assign(n, {});
        parent.resize(n);
        depth.resize(n);
        subtree_size.resize(n);

        chain_root.resize(n);
        chain_size.assign(n, 0);
        chain_tree.assign(n, {});
    }

    void add_edge(int a, int b) {
         adj[a].push_back(b);
         adj[b].push_back(a);
    }

    void dfs(int node, int par) {
        parent[node] = par;
        depth[node] = par < 0 ? 0 : depth[par] + 1;
        subtree_size[node] = 1;

        if (par >= 0)
            adj[node].erase(find(adj[node].begin(), adj[node].end(), par));

        for (int &child : adj[node]) {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];

            if (subtree_size[child] > subtree_size[adj[node].front()])
                swap(child, adj[node].front());
        }
    }

    void chain_dfs(int node, bool heavy) {
        chain_root[node] = heavy ? chain_root[parent[node]] : node;
        chain_size[chain_root[node]]++;
        bool heavy_child = true;

        for (int child : adj[node]) {
            chain_dfs(child, heavy_child);
            heavy_child = false;
        }
    }

    void build(const segment &initial) {
        parent.assign(n, -1);

        for (int i = 0; i < n; i++)
            if (parent[i] < 0) {
                dfs(i, -1);
                chain_dfs(i, false);
            }

        for (int i = 0; i < n; i++)
            if (chain_root[i] == i) {
                chain_tree[i].init(chain_size[i]);
                chain_tree[i].build(vector<segment>(chain_size[i], initial));
            }
    }

    template<typename T_tree_op>
    void process_path(int u, int v, T_tree_op &&op) {
        while (chain_root[u] != chain_root[v]) {
            // Always pull up the chain with the deeper root.
            if (depth[chain_root[u]] > depth[chain_root[v]])
                swap(u, v);

            int root = chain_root[v];
            op(chain_tree[root], 0, depth[v] - depth[root] + 1);
            v = parent[root];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        // u is now an ancestor of v.
        int root = chain_root[v];
        op(chain_tree[root], depth[u] - depth[root] + (vertex_mode ? 0 : 1), depth[v] - depth[root] + 1);
    }

    segment query_path(int u, int v) {
        segment answer;

        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            answer.join(tree.query(a, b));
        });

        return answer;
    }

    void update_path(int u, int v, const segment_change &change) {
        process_path(u, v, [&](seg_tree &tree, int a, int b) {
            tree.update(a, b, change);
        });
    }
};

struct identity {
    template<typename T>
    T operator()(const T &x) const {
        return x;
    }
};

template<typename T, typename T_extract_key = identity>
void radix_sort(vector<T> &data, int bits_per_pass = 10, const T_extract_key &extract_key = identity()) {
    if (data.size() < 256) {
        sort(data.begin(), data.end(), [&](const T &a, const T &b) {
            return extract_key(a) < extract_key(b);
        });
        return;
    }

    using T_key = decltype(extract_key(data.front()));
    T_key minimum = numeric_limits<T_key>::max();

    for (T &x : data)
        minimum = min(minimum, extract_key(x));

    int max_bits = 0;

    for (T &x : data) {
        T_key key = extract_key(x);
        max_bits = max(max_bits, key == minimum ? 0 : 64 - __builtin_clzll(key - minimum));
    }

    int passes = max((max_bits + bits_per_pass / 2) / bits_per_pass, 1);

    if (32 - __builtin_clz(data.size()) <= 1.5 * passes) {
        sort(data.begin(), data.end(), [&](const T &a, const T &b) {
            return extract_key(a) < extract_key(b);
        });
        return;
    }

    vector<T> buffer(data.size());
    vector<int> counts;
    int bits_so_far = 0;

    for (int p = 0; p < passes; p++) {
        int bits = (max_bits + p) / passes;
        counts.assign(1 << bits, 0);

        for (T &x : data) {
            T_key key = extract_key(x) - minimum;
            counts[(key >> bits_so_far) & ((1 << bits) - 1)]++;
        }

        int count_sum = 0;

        for (int &count : counts) {
            int current = count;
            count = count_sum;
            count_sum += current;
        }

        for (T &x : data) {
            T_key key = extract_key(x) - minimum;
            int key_section = (key >> bits_so_far) & ((1 << bits) - 1);
            buffer[counts[key_section]++] = x;
        }

        swap(data, buffer);
        bits_so_far += bits;
    }
}


int main() {
    int N;
    IO::read_int(N);
    vector<int> L(N), R(N), C(N);
    vector<mod_int> inv_C(N);

    for (int i = 0; i < N; i++) {
        IO::read_int(L[i], R[i]);
        L[i]--;
        C[i] = R[i] - L[i];
        inv_C[i] = 1 / mod_int(C[i]);
    }

    heavy_light HLD(N, false);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        IO::read_int(u, v);
        u--; v--;
        HLD.add_edge(u, v);
    }

    HLD.build(segment(0));
    vector<pair<int, int>> events(2 * N);

    for (int i = 0; i < N; i++) {
        events[i] = {L[i], i};
        events[N + i] = {R[i], N + i};
    }

    radix_sort(events, 10, [](const pair<int, int> &x) {
        return x.first;
    });

    mod_int inv_sum = 0, depth_sum = 0, depth_left_sum = 0, depth_right_sum = 0, lca_sum = 0;
    mod_int answer = 0;

    for (int i = 0; i < 2 * N - 1; i++) {
        int node = events[i].second;
        bool add = true;

        if (node >= N) {
            node -= N;
            add = false;
        }

        mod_int inv_change = inv_C[node];
        mod_int depth_change = inv_C[node] * HLD.depth[node];

        if (!add) {
            inv_change = -inv_change;
            depth_change = -depth_change;
        }

        // When removing, update before querying.
        if (!add) {
            inv_sum += inv_change;
            depth_sum += depth_change;
            HLD.update_path(node, 0, segment_change(inv_change));
        }

        depth_left_sum += depth_sum * inv_change;
        depth_right_sum += inv_sum * depth_change;
        lca_sum += inv_change * HLD.query_path(node, 0).sum;

        // When adding, update after querying.
        if (add) {
            inv_sum += inv_change;
            depth_sum += depth_change;
            HLD.update_path(node, 0, segment_change(inv_change));
        }

        answer += (events[i + 1].first - events[i].first) * (depth_left_sum + depth_right_sum - 2 * lca_sum);
    }

    for (int i = 0; i < N; i++)
        answer *= C[i];

    cout << answer << '\n';
}