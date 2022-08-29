#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi = v.begin(); vi != v.end(); ++vi) { if (vi != v.begin()) os << ", "; os << *vi; } os << "}"; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { os << '(' << p.first << ", " << p.second << ')'; return os; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


auto random_address = [] { char *p = new char; delete p; return (uint64_t) p; };
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * (random_address() | 1));

using hash_t = uint64_t;

// When P = 2^32 - 13337, both P and (P - 1) / 2 are prime.
const hash_t HASH_P = (unsigned) -13337;

// Avoid multiplication bases near 0 or P - 1.
uniform_int_distribution<hash_t> MULT_DIST(0.1 * HASH_P, 0.9 * HASH_P);
const hash_t HASH_MULT = MULT_DIST(rng);
// const hash_t HASH_MULT = 100;

uint64_t mod_inv(uint64_t a, uint64_t m) {
    return a == 1 ? 1 : m - mod_inv(m % a, a) * m / a;
}

const hash_t INV_HASH_MULT = mod_inv(HASH_MULT, HASH_P);

vector<hash_t> hash_pow = {1};

struct segment {
    int count;
    hash_t hash_value;
    bool first = false, last = false;

    segment(int _count = 0, hash_t _hash_value = 0) : count(_count), hash_value(_hash_value) {}

    void join(segment other) {
        if (last && other.first) {
            hash_value = (hash_value - '1' + HASH_P) % HASH_P;
            hash_value = hash_value * INV_HASH_MULT % HASH_P;
            other.hash_value = (other.hash_value - (uint64_t) '1' * hash_pow[other.count - 1] % HASH_P + HASH_P) % HASH_P;

            count--;
            other.count--;
        }

        if (count == 0)
            first = other.first;

        if (other.count != 0)
            last = other.last;

        hash_value = (hash_value * hash_pow[other.count] + other.hash_value) % HASH_P;
        count += other.count;

        if (count == 0)
            first = last = false;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = true;

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
        int n = initial.size();
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
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
};


int N, Q;
string T;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> T >> Q;
    dbg(HASH_MULT, INV_HASH_MULT);

    for (int i = 0; i < N; i++)
        hash_pow.push_back(hash_pow.back() * HASH_MULT % HASH_P);

    basic_seg_tree tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++) {
        initial[i] = segment(1, T[i]);
        initial[i].first = initial[i].last = T[i] == '1';
    }

    tree.build(initial);

    for (int q = 0; q < Q; q++) {
        int start1, start2, len;
        cin >> start1 >> start2 >> len;
        start1--; start2--;
        hash_t hash1 = tree.query(start1, start1 + len).hash_value;
        hash_t hash2 = tree.query(start2, start2 + len).hash_value;
        dbg(hash1, hash2);
        cout << (hash1 == hash2 ? "Yes" : "No") << '\n';
    }
}