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


void run_case() {
    array<array<int, 3>, 3> D;
    int N;
    cin >> N >> D[0][1] >> D[1][2] >> D[2][0];
    D[1][0] = D[0][1];
    D[2][1] = D[1][2];
    D[0][2] = D[2][0];
    vector<array<int, 2>> edges;
    int D_max = max({D[0][1], D[1][2], D[2][0]});
    int D_sum = D[0][1] + D[1][2] + D[2][0];

    if (D_sum < 2 * D_max || D_sum % 2 != 0 || D_sum > 2 * (N - 1)) {
        cout << "NO" << '\n';
        return;
    }

    array<int, 3> legs;
    int next_node = 3;
    int center;

    if (D_sum == 2 * D_max) {
        for (int i = 0; i < 3; i++)
            if (D[i][(i + 1) % 3] == D_max)
                center = (i + 2) % 3;

        for (int i = 0; i < 3; i++)
            legs[i] = D[center][i];
    } else {
        center = next_node++;
        legs[0] = (D[0][1] + D[2][0] - D[1][2]) / 2;
        legs[1] = (D[0][1] - D[2][0] + D[1][2]) / 2;
        legs[2] = (-D[0][1] + D[2][0] + D[1][2]) / 2;
    }

    int current = center;

    for (int node = 0; node < 3; node++) {
        if (node == center)
            continue;

        current = center;

        for (int iter = 0; iter < legs[node] - 1; iter++) {
            edges.push_back({current, next_node});
            current = next_node++;
        }

        edges.push_back({current, node});
        current = node;
    }

    while (next_node < N) {
        edges.push_back({current, next_node});
        current = next_node++;
    }

    assert(int(edges.size()) == N - 1);
    cout << "YES" << '\n';

    for (auto &e : edges)
        cout << e[0] + 1 << ' ' << e[1] + 1 << '\n';
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