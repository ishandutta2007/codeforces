#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
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

struct union_find {
    // When data[x] < 0, x is a root and -data[x] is its tree size. When data[x] >= 0, data[x] is x's parent.
    vector<int> data;
    int components = 0;

    union_find(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        data.assign(n + 1, -1);
        components = n;
    }

    int find(int x) {
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }

    int get_size(int x) {
        return -data[find(x)];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y)
            return false;

        if (-data[x] < -data[y])
            swap(x, y);

        data[x] += data[y];
        data[y] = x;
        components--;
        return true;
    }
};


const int ALPHABET = 20;
const char MIN_CHAR = 'a';

void run_case() {
    int N;
    string A, B;
    cin >> N >> A >> B;
    vector<int> graph(ALPHABET, 0);
    union_find UF(ALPHABET);

    for (int i = 0; i < N; i++)
        if (A[i] != B[i]) {
            int a = A[i] - MIN_CHAR, b = B[i] - MIN_CHAR;
            graph[a] |= 1 << b;
            UF.unite(a, b);
        }

    vector<bool> is_dag(1 << ALPHABET, false);
    is_dag[0] = true;

    for (int mask = 1; mask < 1 << ALPHABET; mask++)
        for (int i = 0; i < ALPHABET; i++)
            if (mask >> i & 1)
                is_dag[mask] = is_dag[mask] || (is_dag[mask ^ 1 << i] && (graph[i] & mask) == 0);

    int biggest = 0;

    for (int mask = 0; mask < 1 << ALPHABET; mask++)
        if (is_dag[mask])
            biggest = max(biggest, __builtin_popcount(mask));

    cout << 2 * ALPHABET - UF.components - biggest << '\n';
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