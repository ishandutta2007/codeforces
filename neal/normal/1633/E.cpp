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


struct edge {
    int16_t a, b;
    int weight;
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<edge> edges(M);

    for (auto &e : edges) {
        cin >> e.a >> e.b >> e.weight;
        e.a--; e.b--;
    }

    auto solve_x = [&](int x) -> pair<int64_t, int> {
        sort(edges.begin(), edges.end(), [&](const edge &e, const edge &f) -> bool {
            int e_diff = abs(e.weight - x);
            int f_diff = abs(f.weight - x);

            if (e_diff != f_diff)
                return e_diff < f_diff;

            return e.weight > f.weight;
        });

        union_find UF(N);
        int64_t sum = 0;
        int mult = 0;

        for (auto &e : edges)
            if (UF.unite(e.a, e.b)) {
                if (e.weight > x) {
                    sum += e.weight;
                    mult--;
                } else {
                    sum -= e.weight;
                    mult++;
                }
            }

        return {sum, mult};
    };

    vector<int> cutoffs = {0};

    for (auto &e : edges)
        cutoffs.push_back(e.weight);

    for (int i = 0; i < M; i++)
        for (int j = i + 1; j < M; j++) {
            int half = (edges[i].weight + edges[j].weight + 1) / 2;
            cutoffs.push_back(half);
        }

    sort(cutoffs.begin(), cutoffs.end());
    cutoffs.erase(unique(cutoffs.begin(), cutoffs.end()), cutoffs.end());
    vector<pair<int64_t, int>> answers(cutoffs.size());

    for (int i = 0; i < int(cutoffs.size()); i++)
        answers[i] = solve_x(cutoffs[i]);

    auto solve_query = [&](int x) -> int64_t {
        int index = int(upper_bound(cutoffs.begin(), cutoffs.end(), x) - cutoffs.begin() - 1);
        return answers[index].first + int64_t(answers[index].second) * x;
    };

    int P, K;
    int64_t A, B, C;
    cin >> P >> K >> A >> B >> C;
    int64_t ans_xor = 0;
    int q;

    for (int i = 0; i < P; i++) {
        cin >> q;
        ans_xor ^= solve_query(q);
    }

    for (int i = P; i < K; i++) {
        q = int((A * q + B) % C);
        ans_xor ^= solve_query(q);
    }

    cout << ans_xor << '\n';
}