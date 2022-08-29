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


int N, M;
vector<vector<int>> adj;
vector<int> visited;

bool dfs(int node, int parity) {
    if (visited[node] >= 0 && visited[node] != parity)
        return false;

    if (visited[node] >= 0)
        return true;

    visited[node] = parity;

    for (int neigh : adj[node])
        if (!dfs(neigh, !parity))
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;
    adj.assign(N, {});
    visited.assign(N, -1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    auto &&get_visit_count = [&] {
        int count = 0;

        for (int i = 0; i < N; i++)
            count += visited[i] >= 0;

        return count;
    };

    int visit_count = 0;
    int team = 0;

    for (int i = 0; i < N; i++)
        if (visited[i] < 0) {
            bool success = dfs(i, 0);
            int previous_count = visit_count;
            visit_count = get_visit_count();

            if (success)
                team += visit_count - previous_count;
            else
                team += visit_count - previous_count - 1;
        }

    if (team % 2 != 0)
        team--;

    cout << N - team << '\n';
}