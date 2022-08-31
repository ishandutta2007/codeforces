#include <algorithm>
#include <array>
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


array<int64_t, 2> normalize(array<int64_t, 2> slope) {
    int64_t g = __gcd(slope[0], slope[1]);
    return {slope[0] / g, slope[1] / g};
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int64_t> A(N), B(N), C(N), D(N);

    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];

    vector<array<array<int64_t, 2>, 2>> slopes(N);
    vector<array<int64_t, 2>> sorted;

    for (int i = 0; i < N; i++) {
        slopes[i][0] = normalize({B[i] * C[i], (A[i] + B[i]) * D[i]});
        slopes[i][1] = normalize({B[i] * (C[i] + D[i]), A[i] * D[i]});
        sorted.push_back(slopes[i][0]);
        sorted.push_back(slopes[i][1]);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int S = int(sorted.size());
    vector<vector<int>> adj(N + S);

    auto get_index = [&](array<int64_t, 2> slope) -> int {
        return int(lower_bound(sorted.begin(), sorted.end(), slope) - sorted.begin());
    };

    auto add_edge = [&](int a, int b) -> void {
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    for (int i = 0; i < N; i++) {
        add_edge(i, N + get_index(slopes[i][0]));
        add_edge(i, N + get_index(slopes[i][1]));
    }

    vector<array<int, 2>> matches;
    vector<bool> visited(N + S, false);

    auto solve = y_combinator([&](auto self, int node) -> int {
        if (visited[node])
            return -1;

        visited[node] = true;
        vector<int> choices;

        for (int neigh : adj[node]) {
            int child = self(neigh);

            if (child >= 0)
                choices.push_back(child);
        }

        while (choices.size() >= 2) {
            matches.push_back({choices[choices.size() - 2], choices.back()});
            choices.pop_back();
            choices.pop_back();
        }

        int current = node < N ? node : -1;

        if (!choices.empty() && current >= 0) {
            matches.push_back({choices[0], current});
            choices.pop_back();
            current = -1;
        }

        if (node >= N && !choices.empty())
            current = choices[0];

        return current;
    });

    for (int i = N; i < N + S; i++)
        solve(i);

    cout << matches.size() << '\n';

    for (array<int, 2> match : matches)
        cout << match[0] + 1 << ' ' << match[1] + 1 << '\n';
}