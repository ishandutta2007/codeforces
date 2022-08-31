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


void run_case() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> adj(N);

    for (auto &a : A)
        cin >> a;

    for (int e = 0; e < N - 1; e++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int longest = 0;

    y_combinator([&](auto dfs, int node, int parent) -> array<int, 2> {
        int white = 0, black = 0;

        if (A[node] == 1)
            white = 1;
        else if (A[node] == 2)
            black = 1;

        for (int neighbor : adj[node])
            if (neighbor != parent) {
                array<int, 2> child = dfs(neighbor, node);
                int c_white = child[0], c_black = child[1];
                longest = max({longest, white + c_black, black + c_white});
                white = max(white, c_white);
                black = max(black, c_black);

                if (A[node] == 1)
                    white = max(white, 1 + c_black);

                if (A[node] == 2)
                    black = max(black, 1 + c_white);
            }

        longest = max({longest, white, black});
        return {white, black};
    })(0, -1);

    cout << longest / 2 + 1 << '\n';
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