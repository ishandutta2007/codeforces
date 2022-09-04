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


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> S(N), A(N);

    for (auto &s : S)
        cin >> s;

    for (auto &a : A)
        cin >> a;

    vector<array<int, 2>> edge_list(M);
    vector<vector<pair<int, int>>> adj(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edge_list[i] = {u, v};
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
    }

    vector<int> degree(N);

    for (int i = 0; i < N; i++)
        degree[i] = int(adj[i].size());

    for (int i = 0; i < N; i++)
        if (S[i] == 1 && (A[i] - degree[i]) % 2 != 0) {
            cout << "NO" << '\n';
            return 0;
        }

    vector<int> edge_direction(M, -1);
    vector<bool> in_tight(N, false);
    queue<int> tight;

    for (int i = 0; i < N; i++)
        if (S[i] == 1 && abs(A[i]) == degree[i]) {
            tight.push(i);
            in_tight[i] = true;
        }

    set<int> remaining;

    for (int i = 0; i < M; i++)
        remaining.insert(i);

    auto set_edge = [&](int e, int u, int v) -> void {
        edge_direction[e] = edge_list[e][0] == u;
        remaining.erase(e);

        A[u]--;
        degree[u]--;

        if (S[u] == 1) {
            if (abs(A[u]) > degree[u]) {
                cout << "NO" << '\n';
                exit(0);
            }

            if (abs(A[u]) == degree[u] && !in_tight[u]) {
                tight.push(u);
                in_tight[u] = true;
            }
        }

        A[v]++;
        degree[v]--;

        if (S[v] == 1) {
            if (abs(A[v]) > degree[v]) {
                cout << "NO" << '\n';
                exit(0);
            }

            if (abs(A[v]) == degree[v] && !in_tight[v]) {
                tight.push(v);
                in_tight[v] = true;
            }
        }
    };

    while (!remaining.empty()) {
        if (!tight.empty()) {
            int x = tight.front(); tight.pop();

            for (auto &[neigh, e] : adj[x])
                if (edge_direction[e] < 0) {
                    if (A[x] < 0)
                        set_edge(e, neigh, x);
                    else
                        set_edge(e, x, neigh);
                }

            continue;
        }

        int e = *remaining.begin();
        remaining.erase(e);
        set_edge(e, edge_list[e][0], edge_list[e][1]);
    }

    cout << "YES" << '\n';

    for (int i = 0; i < M; i++)
        if (edge_direction[i] == 0)
            cout << edge_list[i][0] + 1 << ' ' << edge_list[i][1] + 1 << '\n';
        else
            cout << edge_list[i][1] + 1 << ' ' << edge_list[i][0] + 1 << '\n';
}