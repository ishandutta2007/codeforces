#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <queue>
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


void run_case() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> adj(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (K == 1) {
        cout << N - 1 << '\n';
        return;
    }

    vector<int> neighbors(N, 0);

    for (int i = 0; i < N; i++)
        neighbors[i] = int(adj[i].size());

    vector<int> leaves(N, 0);

    for (int i = 0; i < N; i++)
        if (adj[i].size() == 1)
            leaves[adj[i].front()]++;

    queue<int> q;

    for (int i = 0; i < N; i++)
        if (leaves[i] >= K)
            q.push(i);

    int answer = 0;

    while (!q.empty()) {
        int top = q.front(); q.pop();
        assert(leaves[top] >= K);
        int take = leaves[top] / K;
        answer += take;
        leaves[top] -= K * take;
        neighbors[top] -= K * take;

        if (neighbors[top] == 1) {
            for (int neigh : adj[top])
                if (++leaves[neigh] == K)
                    q.push(neigh);
        }
    }

    cout << answer << '\n';
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