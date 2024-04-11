#include <algorithm>
#include <array>
#include <cassert>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<pair<int, int>> segments;

    for (int i = 0; i < N; i++) {
        int L, R;
        cin >> L >> R;
        R++;
        segments.emplace_back(L, 2 * i);
        segments.emplace_back(R, 2 * i + 1);
    }

    sort(segments.begin(), segments.end());
    vector<vector<int>> adj(2 * N);

    auto add_edge = [&](int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    };

    for (int i = 0; i < N; i++)
        add_edge(2 * i, 2 * i + 1);

    for (int i = 0; i < 2 * N; i += 2)
        add_edge(segments[i].second, segments[i + 1].second);

    vector<int> depth(2 * N, -1);

    auto dfs = y_combinator([&](auto self, int node, int d) -> void {
        if (depth[node] >= 0) {
            assert(depth[node] % 2 == d % 2);
            return;
        }

        depth[node] = d;

        for (int neigh : adj[node])
            self(neigh, d + 1);
    });

    for (int i = 0; i < 2 * N; i++)
        if (depth[i] < 0)
            dfs(i, 0);

    for (int i = 0; i < N; i++)
        cout << depth[2 * i] % 2 << (i < N - 1 ? ' ' : '\n');
}