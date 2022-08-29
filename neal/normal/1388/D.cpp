#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <numeric>
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

// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = int(adj.size());
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < int(order.size())) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


const int64_t INF64 = int64_t(2e18) + 5;

int N;
vector<int> A, B;
vector<int64_t> dp;
vector<vector<int>> children;
vector<vector<int>> order_adj;

void add_dependency(int a, int b) {
    // a comes before b.
    order_adj[a].push_back(b);
}

void dfs(int node) {
    dp[node] = A[node];

    for (int child : children[node]) {
        dfs(child);

        if (dp[child] > 0) {
            dp[node] += dp[child];
            add_dependency(child, node);
        } else {
            add_dependency(node, child);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    A.resize(N);
    B.resize(N);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B) {
        cin >> b;

        if (b >= 0)
            b--;
    }

    children.assign(N, {});

    for (int i = 0; i < N; i++)
        if (B[i] >= 0)
            children[B[i]].push_back(i);

    order_adj.assign(N, {});
    dp.assign(N, -INF64);

    for (int i = 0; i < N; i++)
        if (B[i] < 0)
            dfs(i);

    vector<int> order = topological_sort(order_adj);
    assert(int(order.size()) == N);
    cout << accumulate(dp.begin(), dp.end(), 0LL) << '\n';
    output_vector(order, true);
}