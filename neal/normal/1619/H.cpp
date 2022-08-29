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

    void init() {
        // Ensures that _flush_output() is called at the end of the program.
        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);

        for (int i = 0; i < 100; i++)
            lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}


using T = int;

struct splay_node {
    splay_node *parent = nullptr, *child[2] = {nullptr, nullptr};
    int size = 1;

    T value;

    friend int get_size(splay_node *x) {
        return x == nullptr ? 0 : x->size;
    }

    int parent_index() const {
        return parent == nullptr ? -1 : int(this == parent->child[1]);
    }

    void set_child(int index, splay_node *x) {
        child[index] = x;

        if (x != nullptr)
            x->parent = this;
    }

    void join() {
        size = get_size(child[0]) + get_size(child[1]) + 1;
    }
};

namespace splay_tree {
    const int POOL_SIZE = 10000;
    vector<splay_node*> node_pool;
    vector<splay_node*> pointers_to_delete;
    int64_t splay_count = 0;

    splay_node* new_node(const T &value) {
        if (node_pool.empty()) {
            splay_node *ptr = new splay_node[POOL_SIZE];
            pointers_to_delete.push_back(ptr);
            node_pool.reserve(POOL_SIZE);

            for (int i = POOL_SIZE - 1; i >= 0; i--)
                node_pool.push_back(ptr + i);
        }

        splay_node *node = node_pool.back();
        node_pool.pop_back();
        *node = splay_node();
        node->value = value;
        node->join();
        return node;
    }

    bool _exit_delete_setup = false;

    void _delete_pointers() {
        for (splay_node *node : pointers_to_delete)
            delete[] node;

        pointers_to_delete.clear();
    }

    void init() {
        if (!_exit_delete_setup) {
            atexit(_delete_pointers);
            _exit_delete_setup = true;
        }
    }

    splay_node *construct(const vector<splay_node *> &nodes, int start, int end) {
        if (start >= end)
            return nullptr;

        if (end - start == 1)
            return nodes[start];

        int mid = (start + end) / 2;
        splay_node *current = nodes[mid];
        current->set_child(0, construct(nodes, start, mid));
        current->set_child(1, construct(nodes, mid + 1, end));
        current->join();
        return current;
    }

    // Constructs the splay tree in linear time.
    splay_node *build(const vector<splay_node *> &nodes) {
        return construct(nodes, 0, int(nodes.size()));
    }

    splay_node *set_root(splay_node *x) {
        if (x != nullptr)
            x->parent = nullptr;

        return x;
    }

    bool is_root(splay_node *x) {
        return x == nullptr || x->parent == nullptr;
    }

    void rotate_up(splay_node *x, bool x_join = true) {
        splay_node *p = x->parent, *gp = p->parent;
        int index = x->parent_index();

        if (gp == nullptr)
            set_root(x);
        else
            gp->set_child(p->parent_index(), x);

        p->set_child(index, x->child[!index]);
        x->set_child(!index, p);
        p->join();

        if (x_join)
            x->join();
    }

    // Note that splay(x) handles both pushing x and joining all nodes from x to the root, inclusive.
    void splay(splay_node *x) {
        if (x == nullptr)
            return;

        splay_count++;

        while (!is_root(x)) {
            splay_node *p = x->parent;

            if (!is_root(p))
                rotate_up(x->parent_index() == p->parent_index() ? p : x, false);

            rotate_up(x, false);
        }

        x->join();
    }

    int get_index(splay_node *node) {
        splay(node);
        return get_size(node->child[0]);
    }

    int get_tree_size(splay_node *node) {
        splay(node);
        return get_size(node);
    }

    splay_node *node_at_index(splay_node *root, int index) {
        assert(is_root(root));

        if (index < 0 || index >= get_size(root))
            return nullptr;

        splay_node *current = root;

        while (current != nullptr) {
            int left_size = get_size(current->child[0]);

            if (index == left_size) {
                splay(current);
                return current;
            }

            if (index < left_size) {
                current = current->child[0];
            } else {
                current = current->child[1];
                index -= left_size + 1;
            }
        }

        assert(false);
    }

    splay_node *insert(splay_node *root, int index, splay_node *node) {
        assert(is_root(root) && is_root(node));
        assert(0 <= index && index <= get_size(root));

        if (node == nullptr)
            return nullptr;
        else if (root == nullptr)
            return set_root(node);

        splay_node *current = root, *previous = nullptr;
        int previous_dir = -1;

        while (current != nullptr) {
            previous = current;
            int left_size = get_size(current->child[0]);

            if (index <= left_size) {
                current = current->child[0];
                previous_dir = 0;
            } else {
                current = current->child[1];
                previous_dir = 1;
                index -= left_size + 1;
            }
        }

        previous->set_child(previous_dir, node);
        splay(node);
        return node;
    }

    // Detach x from its parent, producing two separate splay trees as a result.
    void detach(splay_node *x) {
        if (x == nullptr)
            return;

        if (is_root(x)) {
            set_root(nullptr);
            return;
        }

        splay_node *parent = x->parent;
        assert(parent != nullptr);
        parent->set_child(x->parent_index(), nullptr);
        x->parent = nullptr;
        splay(parent);
    }

    // Returns a splay_node pointer representing the first `count` nodes. If none, returns `nullptr`.
    splay_node *query_prefix_count(splay_node *root, int count) {
        assert(is_root(root));

        if (count <= 0)
            return nullptr;
        else if (count >= get_size(root))
            return root;

        splay_node *node = node_at_index(root, count);
        splay(node);
        return node->child[0];
    }

    // Returns a splay_node pointer representing the last `count` nodes. If none, returns `nullptr`.
    splay_node *query_suffix_count(splay_node *root, int count) {
        assert(is_root(root));

        if (count >= get_size(root))
            return root;
        else if (count <= 0)
            return nullptr;

        int index = get_size(root) - count;
        splay_node *node = node_at_index(root, index - 1);
        splay(node);
        return node->child[1];
    }

    // Returns a splay_node pointer representing the index range [start, end). If none, returns `nullptr`.
    splay_node *query_range(splay_node *root, int start, int end) {
        assert(is_root(root));

        if (start >= end)
            return nullptr;
        else if (start <= 0)
            return query_prefix_count(root, end);
        else if (end >= get_size(root))
            return query_suffix_count(root, get_size(root) - start);

        splay_node *before = node_at_index(root, start - 1);
        splay_node *after = node_at_index(root, end);
        splay(after);
        splay(before);

        if (after->parent != before)
            rotate_up(after);

        assert(before->child[1] == after);
        return after->child[0];
    }

    void print_tree(splay_node *x, int depth = 0) {
        cerr << string(depth, ' ');

        if (x == nullptr) {
            cerr << "null" << endl;
            return;
        }

        cerr << x->value << " (" << x->size << ")\n";

        if (x->child[0] != nullptr || x->child[1] != nullptr) {
            print_tree(x->child[0], depth + 1);
            print_tree(x->child[1], depth + 1);
        }
    }
};


struct permutation_cycles {
    int n;
    vector<splay_node *> nodes;
    vector<int> P;

    permutation_cycles(int _n = 0) {
        init(_n);
    }

    permutation_cycles(const vector<int> &_P) {
        init(_P);
    }

    void init(int _n) {
        splay_tree::init();
        n = _n;
        P.resize(n);
        iota(P.begin(), P.end(), 0);
        nodes.resize(n);

        for (int i = 0; i < n; i++)
            nodes[i] = splay_tree::new_node(i);
    }

    void init(const vector<int> &_P) {
        splay_tree::init();
        init(int(_P.size()));
        P = _P;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
            if (!visited[i]) {
                vector<splay_node *> cycle;
                int x = i;

                do {
                    cycle.push_back(nodes[x]);
                    visited[x] = true;
                    x = P[x];
                } while (x != i);

                splay_tree::build(cycle);
            }
    }

    // Performs swap(P[x], P[y])
    void p_swap(int x, int y) {
        assert(0 <= min(x, y) && max(x, y) < n);

        if (x == y)
            return;

        swap(P[x], P[y]);
        int x_index = splay_tree::get_index(nodes[x]);
        int y_index = splay_tree::get_index(nodes[y]);

        if (x_index > y_index) {
            swap(x, y);
            swap(x_index, y_index);
        }

        splay_tree::splay(nodes[y]);
        splay_tree::splay(nodes[x]);

        // same cycle: ... x [... y] ...
        // detach the bracketed portion
        if (!splay_tree::is_root(nodes[y])) {
            if (nodes[y]->parent != nodes[x])
                splay_tree::rotate_up(nodes[y]);

            splay_tree::detach(nodes[y]);
            splay_node *y_right = nodes[y]->child[1];
            splay_tree::detach(y_right);
            splay_tree::insert(nodes[x], splay_tree::get_tree_size(nodes[x]), y_right);
            return;
        }

        // different cycles: ... x ... / ... y ...
        // swap the right halves and then concatenate
        splay_node *x_right = nodes[x]->child[1];
        splay_node *y_right = nodes[y]->child[1];
        splay_tree::detach(x_right);
        splay_tree::detach(y_right);
        splay_tree::insert(nodes[x], splay_tree::get_tree_size(nodes[x]), y_right);
        splay_tree::insert(nodes[y], splay_tree::get_tree_size(nodes[y]), x_right);
        splay_tree::splay(nodes[x]);
        splay_tree::splay(nodes[y]);
        splay_tree::insert(nodes[y], 0, nodes[x]);
    }

    // Returns P[P[...P[x]]] (k iterations of P)
    int get_node_at_offset(int x, int64_t k) {
        int index = splay_tree::get_index(nodes[x]);
        index = int((index + k) % splay_tree::get_tree_size(nodes[x]));
        return splay_tree::node_at_index(nodes[x], index)->value;
    }
};


int main() {
    IO::init();

    int N, Q;
    IO::read_int(N, Q);
    vector<int> P(N);

    for (auto &p : P) {
        IO::read_int(p);
        p--;
    }

    permutation_cycles cycles(P);

    for (int q = 0; q < Q; q++) {
        int type;
        IO::read_int(type);

        if (type == 1) {
            int x, y;
            IO::read_int(x, y);
            x--; y--;
            cycles.p_swap(x, y);
        } else {
            int x, k;
            IO::read_int(x, k);
            x--;
            IO::write_int(cycles.get_node_at_offset(x, k) + 1, '\n');
        }
    }
}