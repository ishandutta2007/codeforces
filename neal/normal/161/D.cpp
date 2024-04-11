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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


struct result {
    deque<int> counts;

    int size() const {
        return int(counts.size());
    }

    int get(int index) const {
        return 0 <= index && index < size() ? counts[index] : 0;
    }
};

int N, K;
vector<vector<int>> adj;
vector<result> results;
int64_t total = 0;

void extend(result &root) {
    // To add an edge upward, shift the counts forward by one.
    root.counts.push_front(0);
}

void attach(result &root, result &child) {
    if (root.size() < child.size())
        swap(root, child);

    for (int d = 0; d < child.size(); d++)
        total += int64_t(child.counts[d]) * root.get(K - d);

    for (int d = 0; d < child.size(); d++)
        root.counts[d] += child.counts[d];
}

void dfs(int node, int parent) {
    result &current = results[node];
    current.counts = {1};

    for (int neigh : adj[node])
        if (neigh != parent) {
            dfs(neigh, node);
            result &child = results[neigh];
            extend(child);
            attach(current, child);
        }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> K;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    results.assign(N, {});
    total = 0;
    dfs(0, -1);
    cout << total << '\n';
}