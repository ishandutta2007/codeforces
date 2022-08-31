// Solution to https://codeforces.com/contest/1046/problem/A
#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


typedef int treap_value;
typedef int treap_priority;

treap_priority PRIORITY_INF = 1 << 30;

struct treap_node {
    treap_node *parent, *child[2];
    int size;
    treap_value value;
    treap_priority priority;

    treap_node() : parent(nullptr), child{nullptr, nullptr}, size(1) {}

    static int get_size(treap_node *x) {
        return x == nullptr ? 0 : x->size;
    }

    static treap_priority get_priority(treap_node *x) {
        return x == nullptr ? -1 : x->priority;
    }

    int parent_index() const {
        if (parent == nullptr)
            return -1;

        return this == parent->child[0] ? 0 : 1;
    }

    void set_child(int index, treap_node *x) {
        child[index] = x;

        if (x != nullptr)
            x->parent = this;
    }

    void join() {
        size = get_size(child[0]) + get_size(child[1]) + 1;
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
long long treap_rotations = 0;

struct treap {
    static const int POOL_SIZE = 10000;
    static vector<treap_node*> node_pool;

    static treap_node* new_node() {
        if (node_pool.empty()) {
            treap_node *ptr = new treap_node[POOL_SIZE];

            for (int i = POOL_SIZE - 1; i >= 0; i--)
                node_pool.push_back(ptr + i);
        }

        treap_node *node = node_pool.back();
        node_pool.pop_back();
        return node;
    }

    treap_node *root;

    treap() : root(nullptr) {}

    int tree_size() const {
        return root == nullptr ? 0 : root->size;
    }

    treap_node *set_root(treap_node *x) {
        if (x != nullptr)
            x->parent = nullptr;

        return root = x;
    }

    void rotate_up(treap_node *x, bool x_join = true) {
        treap_rotations++;
        treap_node *p = x->parent, *gp = p->parent;
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

    void bring_up(treap_node *x) {
        while (x != root && x->priority > x->parent->priority)
            rotate_up(x, false);

        x->join();
    }

    void bring_down(treap_node *x) {
        while (true) {
            int larger = treap_node::get_priority(x->child[0]) > treap_node::get_priority(x->child[1]) ? 0 : 1;

            if (x->child[larger] == nullptr || x->child[larger]->priority <= x->priority)
                break;

            rotate_up(x->child[larger]);
        }
    }

    treap_node *insert(const treap_value &value) {
        treap_node *x = new_node();
        x->value = value;
        x->priority = rng() & (PRIORITY_INF - 1);

        if (root == nullptr)
            return set_root(x);

        treap_node *current = root, *prev = nullptr;

        while (current != nullptr) {
            prev = current;
            current->size++;
            current = current->child[value < current->value ? 0 : 1];
        }

        prev->set_child(value < prev->value ? 0 : 1, x);
        bring_up(x);
        return x;
    }

    treap_node *begin() {
        treap_node *x = root;

        while (x->child[0] != nullptr)
            x = x->child[0];

        return x;
    }

    treap_node *successor(treap_node *x) const {
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

    void erase(treap_node *x) {
        x->priority = -1;
        bring_down(x);
        treap_node *fix_node = x->parent;

        if (x == root)
            set_root(nullptr);
        else
            x->parent->set_child(x->parent_index(), nullptr);

        for (treap_node *node = fix_node; node != nullptr; node = node->parent)
            node->join();

        // Instead of deleting, add x back to node_pool.
        *x = treap_node();
        node_pool.push_back(x);
    }

    pair<treap_node*, int> lower_bound(const treap_value &value) {
        treap_node *current = root, *answer = nullptr;
        int below = 0;

        while (current != nullptr)
            if (current->value < value) {
                below += treap_node::get_size(current->child[0]) + 1;
                current = current->child[1];
            } else {
                answer = current;
                current = current->child[0];
            }

        return make_pair(answer, below);
    }

    bool erase(const treap_value &value) {
        treap_node *x = lower_bound(value).first;

        if (x == nullptr || x->value != value)
            return false;

        erase(x);
        return true;
    }

    int less_than(const treap_value &value) {
        return lower_bound(value).second;
    }

    int less_equal(const treap_value &value) {
        assert(is_integral<treap_value>::value);
        return less_than(value + 1);
    }

    treap_node *node_at_index(int index) {
        if (index < 0 || index >= tree_size())
            return nullptr;

        treap_node *current = root;

        while (current != nullptr) {
            int left_size = treap_node::get_size(current->child[0]);

            if (index == left_size)
                return current;

            if (index < left_size) {
                current = current->child[0];
            } else {
                current = current->child[1];
                index -= left_size + 1;
            }
        }

        assert(false);
    }
};

vector<treap_node*> treap::node_pool;


struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    size_t operator()(unsigned x) const {
        static const unsigned FIXED_RANDOM = hash32(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        return hash32(x ^ FIXED_RANDOM);
    }
};


struct robot {
    int x, radius, iq;

    bool operator<(const robot &other) const {
        return radius > other.radius;
    }
};

int N, K;
vector<robot> robots;
gp_hash_table<int, treap, safe_hash32> iq_map;

int main() {
    scanf("%d %d", &N, &K);
    robots.resize(N);

    for (robot &r : robots)
        scanf("%d %d %d", &r.x, &r.radius, &r.iq);

    sort(robots.begin(), robots.end());
    long long total = 0;

    for (robot &r : robots) {
        for (int iq = r.iq - K; iq <= r.iq + K; iq++)
            if (iq_map.find(iq) != iq_map.end())
                total += iq_map[iq].less_equal(r.x + r.radius) - iq_map[iq].less_than(r.x - r.radius);

        iq_map[r.iq].insert(r.x);
    }

    printf("%lld\n", total);
}