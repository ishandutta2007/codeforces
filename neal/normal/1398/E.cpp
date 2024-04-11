#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

using splay_key = int;

struct splay_node {
    splay_node *parent = nullptr, *child[2] = {nullptr, nullptr};
    splay_key key;
    int size = 1;
    int64_t sum = 0;

    static int get_size(splay_node *x) {
        return x == nullptr ? 0 : x->size;
    }

    static int64_t get_sum(splay_node *x) {
        return x == nullptr ? 0 : x->sum;
    }

    int parent_index() const {
        if (parent == nullptr)
            return -1;

        return this == parent->child[0] ? 0 : 1;
    }

    void set_child(int index, splay_node *x) {
        child[index] = x;

        if (x != nullptr)
            x->parent = this;
    }

    void join() {
        size = get_size(child[0]) + get_size(child[1]) + 1;
        sum = get_sum(child[0]) + get_sum(child[1]) + key;
    }
};

auto random_address = [] { char *p = new char; delete p; return uint64_t(p); };
mt19937_64 splay_rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));
int64_t splay_count = 0;

struct splay_tree {
    static const int POOL_SIZE = 10000;
    static vector<splay_node*> node_pool;
    static vector<splay_node*> pointers_to_delete;

    static splay_node* new_node(const splay_key &key) {
        if (node_pool.empty()) {
            splay_node *ptr = new splay_node[POOL_SIZE];
            pointers_to_delete.push_back(ptr);

            for (int i = POOL_SIZE - 1; i >= 0; i--)
                node_pool.push_back(ptr + i);
        }

        splay_node *node = node_pool.back();
        node_pool.pop_back();
        node->key = key;
        node->sum = key;
        return node;
    }

    static bool _exit_delete_setup;

    static void _delete_pointers() {
        for (splay_node *node : pointers_to_delete)
            delete[] node;

        pointers_to_delete.clear();
    }

    ~splay_tree() {
        if (!_exit_delete_setup) {
            atexit(_delete_pointers);
            _exit_delete_setup = true;
        }
    }

    splay_node *root = nullptr;

    bool empty() const {
        return root == nullptr;
    }

    int size() const {
        return root == nullptr ? 0 : root->size;
    }

    splay_node *set_root(splay_node *x) {
        if (x != nullptr)
            x->parent = nullptr;

        return root = x;
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

    void splay(splay_node *x) {
        splay_count++;

        while (x != root) {
            splay_node *p = x->parent;

            if (p != root)
                rotate_up(x->parent_index() == p->parent_index() ? p : x, false);

            rotate_up(x, false);
        }

        x->join();
    }

    static constexpr double SPLAY_RNG_RANGE = double(splay_rng.max()) + 1.0;
    static constexpr double LOG_CONSTANT = 2.0;
    static constexpr double SPLAY_PROBABILITY = 0.25;
    static const int SIZE_CUTOFF = 100;

    void check_splay(splay_node *x, int depth) {
        int n = size(), log_n = 32 - __builtin_clz(n);

        // Splay when deep or with a certain random chance when small.
        if (depth > LOG_CONSTANT * log_n || (n < SIZE_CUTOFF && double(splay_rng()) < SPLAY_PROBABILITY * SPLAY_RNG_RANGE))
            splay(x);
    }

    pair<splay_node*, int> insert(const splay_key &key, bool require_unique = false) {
        return insert(new_node(key), require_unique);
    }

    // Returns {new node pointer, index (number of existing elements that are strictly less)}
    pair<splay_node*, int> insert(splay_node *x, bool require_unique = false) {
        if (root == nullptr)
            return {set_root(x), 0};

        splay_node *current = root, *prev = nullptr;
        int below = 0, depth = 0;

        while (current != nullptr) {
            prev = current;
            depth++;

            if (current->key < x->key) {
                below += splay_node::get_size(current->child[0]) + 1;
                current = current->child[1];
            } else {
                // Check for equal keys.
                if (require_unique && !(x->key < current->key)) {
                    below += splay_node::get_size(current->child[0]);
                    check_splay(current, depth);
                    return {current, below};
                }

                current = current->child[0];
            }
        }

        prev->set_child(prev->key < x->key ? 1 : 0, x);
        check_splay(x, depth);

        for (splay_node *node = x; node != nullptr; node = node->parent)
            node->join();

        return {x, below};
    }

    splay_node *begin() {
        if (root == nullptr)
            return nullptr;

        splay_node *x = root;
        int depth = 0;

        while (x->child[0] != nullptr) {
            x = x->child[0];
            depth++;
        }

        check_splay(x, depth);
        return x;
    }

    // To iterate through all nodes in order:
    // for (splay_node *node = tree.begin(); node != nullptr; node = tree.successor(node))
    splay_node *successor(splay_node *x) const {
        if (x == nullptr)
            return nullptr;

        if (x->child[1] != nullptr) {
            x = x->child[1];

            while (x->child[0] != nullptr)
                x = x->child[0];

            return x;
        }

        while (x->parent_index() == 1)
            x = x->parent;

        return x->parent;
    }

    splay_node *predecessor(splay_node *x) const {
        if (x == nullptr)
            return nullptr;

        if (x->child[0] != nullptr) {
            x = x->child[0];

            while (x->child[1] != nullptr)
                x = x->child[1];

            return x;
        }

        while (x->parent_index() == 0)
            x = x->parent;

        return x->parent;
    }

    splay_node *last() {
        if (root == nullptr)
            return nullptr;

        splay_node *x = root;
        int depth = 0;

        while (x->child[1] != nullptr) {
            x = x->child[1];
            depth++;
        }

        check_splay(x, depth);
        return x;
    }

    void clear() {
        vector<splay_node*> nodes;
        nodes.reserve(size());

        for (splay_node *node = begin(); node != nullptr; node = successor(node))
            nodes.push_back(node);

        for (splay_node *node : nodes) {
            // Instead of deleting, add `node` back to `node_pool`.
            *node = splay_node();
            node_pool.push_back(node);
        }

        set_root(nullptr);
    }

    void erase(splay_node *x) {
        splay_node *new_x = nullptr, *fix_node = nullptr;

        if (x->child[0] == nullptr || x->child[1] == nullptr) {
            new_x = x->child[x->child[0] == nullptr ? 1 : 0];
            fix_node = x->parent;
        } else {
            splay_node *next = successor(x);
            assert(next != nullptr && next->child[0] == nullptr);
            new_x = next;
            fix_node = next->parent == x ? next : next->parent;

            next->parent->set_child(next->parent_index(), next->child[1]);
            next->set_child(0, x->child[0]);
            next->set_child(1, x->child[1]);
        }

        if (x == root)
            set_root(new_x);
        else
            x->parent->set_child(x->parent_index(), new_x);

        int depth = 0;

        for (splay_node *node = fix_node; node != nullptr; node = node->parent) {
            node->join();
            depth++;
        }

        if (fix_node != nullptr)
            check_splay(fix_node, depth);

        // Instead of deleting, add `x` back to `node_pool`.
        *x = splay_node();
        node_pool.push_back(x);
    }

    // Returns {node pointer, index (number of existing elements that are strictly less)}
    pair<splay_node*, int> lower_bound(const splay_key &key) {
        splay_node *current = root, *prev = nullptr, *answer = nullptr;
        int below = 0, depth = 0;

        while (current != nullptr) {
            prev = current;
            depth++;

            if (current->key < key) {
                below += splay_node::get_size(current->child[0]) + 1;
                current = current->child[1];
            } else {
                answer = current;
                current = current->child[0];
            }
        }

        if (prev != nullptr)
            check_splay(prev, depth);

        return make_pair(answer, below);
    }

    bool contains(const splay_key &key) {
        splay_node *node = lower_bound(key).first;
        return node != nullptr && node->key == key;
    }

    bool erase(const splay_key &key) {
        splay_node *x = lower_bound(key).first;

        if (x == nullptr || x->key != key)
            return false;

        erase(x);
        return true;
    }

    splay_node *node_at_index(int index) {
        if (index < 0 || index >= size())
            return nullptr;

        splay_node *current = root;
        int depth = 0;

        while (current != nullptr) {
            int left_size = splay_node::get_size(current->child[0]);
            depth++;

            if (index == left_size) {
                check_splay(current, depth);
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

    // Returns a splay_node pointer representing all nodes with key less than `key`. If none, returns `nullptr`.
    splay_node *query_prefix_key(const splay_key &key) {
        splay_node *node = lower_bound(key).first;

        if (node == nullptr)
            return root;

        splay(node);
        return node->child[0];
    }

    // Returns a splay_node pointer representing the first `prefix` nodes. If none, returns `nullptr`.
    splay_node *query_prefix_count(int prefix) {
        if (prefix <= 0)
            return nullptr;

        if (prefix >= size())
            return root;

        splay_node *node = node_at_index(prefix);
        splay(node);
        return node->child[0];
    }

    // Returns a splay_node pointer representing all nodes with key >= `key`. If none, returns `nullptr`.
    splay_node *query_suffix_key(const splay_key &key) {
        splay_node *node = lower_bound(key).first;

        if (node == nullptr)
            return nullptr;

        node = predecessor(node);

        if (node == nullptr)
            return root;

        splay(node);
        return node->child[1];
    }

    // Returns a splay_node pointer representing the last `suffix` nodes. If none, returns `nullptr`.
    splay_node *query_suffix_count(int suffix) {
        if (suffix >= size())
            return root;

        if (suffix <= 0)
            return nullptr;

        int index = size() - suffix;
        splay_node *node = node_at_index(index - 1);
        splay(node);
        return node->child[1];
    }
};

bool splay_tree::_exit_delete_setup = false;
vector<splay_node*> splay_tree::node_pool;
vector<splay_node*> splay_tree::pointers_to_delete;



void print_tree(splay_node *x, int depth = 0) {
    if (x == nullptr)
        return;

    for (int i = 0; i < depth; i++)
        cerr << ' ';

    cerr << x->key << " (" << x->size << ")\n";
    print_tree(x->child[0], depth + 1);
    print_tree(x->child[1], depth + 1);
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    splay_tree spells, lightning;
    int64_t spell_sum = 0;

    auto &&query = [&] {
        if (lightning.empty())
            return spell_sum;

        spells.erase(lightning.begin()->key);
        int take = min(lightning.size(), spells.size());
        int64_t extra = splay_node::get_sum(spells.query_suffix_count(take));
        spells.insert(lightning.begin()->key);
        return spell_sum + extra;
    };

    for (int i = 0; i < N; i++) {
        int t, d;
        cin >> t >> d;
        spell_sum += d;

        if (d > 0) {
            spells.insert(d);
            if (t == 1) lightning.insert(d);
        } else {
            d = -d;
            spells.erase(d);
            if (t == 1) lightning.erase(d);
        }

        cout << query() << '\n';
    }
}