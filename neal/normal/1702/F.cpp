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

int highest_bit(uint64_t x) {
    return x == 0 ? -1 : 63 - __builtin_clzll(x);
}

template<int ALPHABET = 2>
struct binary_trie {
    struct trie_node {
        array<int, ALPHABET> child;
        int words_here = 0, starting_with = 0;

        trie_node() {
            memset(&child[0], -1, ALPHABET * sizeof(int));
        }
    };

    static const int ROOT = 0;

    vector<trie_node> nodes = {trie_node()};

    binary_trie(int total_length = -1) {
        if (total_length >= 0)
            nodes.reserve(total_length + 1);
    }

    int get_or_create_child(int node, int c) {
        if (nodes[node].child[c] < 0) {
            nodes[node].child[c] = int(nodes.size());
            nodes.emplace_back();
        }

        return nodes[node].child[c];
    }

    int build(uint64_t word, int delta) {
        int node = ROOT;

        for (int bit = highest_bit(word); bit >= 0; bit--) {
            nodes[node].starting_with += delta;
            node = get_or_create_child(node, int(word >> bit & 1));
        }

        nodes[node].starting_with += delta;
        return node;
    }

    int add(uint64_t word) {
        int node = build(word, +1);
        nodes[node].words_here++;
        return node;
    }

    int erase(uint64_t word) {
        int node = build(word, -1);
        nodes[node].words_here--;
        return node;
    }

    int find(uint64_t query) const {
        int node = ROOT;

        for (int bit = highest_bit(query); bit >= 0; bit--) {
            node = nodes[node].child[query >> bit & 1];

            if (node < 0)
                break;
        }

        return node;
    }

    // Given a string, how many words in the trie are prefixes of the string?
    int count_prefixes(uint64_t query, bool include_full) const {
        int node = ROOT, count = 0;

        for (int bit = highest_bit(query); bit >= 0; bit--) {
            count += nodes[node].words_here;
            node = nodes[node].child[query >> bit & 1];

            if (node < 0)
                break;
        }

        if (include_full && node >= 0)
            count += nodes[node].words_here;

        return count;
    }

    // Given a string, how many words in the trie start with the given string?
    int count_starting_with(uint64_t query, bool include_full) const {
        int node = find(query);

        if (node < 0)
            return 0;

        return nodes[node].starting_with - (include_full ? 0 : nodes[node].words_here);
    }
};


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);

    for (auto &a : A) {
        cin >> a;
        a >>= __builtin_ctz(a);
    }

    for (auto &b : B) {
        cin >> b;
        b >>= __builtin_ctz(b);
    }

    binary_trie trie;

    for (auto &b : B)
        trie.add(b);

    sort(A.rbegin(), A.rend());

    for (auto &a : A) {
        int node = trie.find(a);

        if (node < 0 || trie.nodes[node].starting_with <= 0) {
            cout << "NO" << '\n';
            return;
        }

        trie.erase(a);
    }

    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}