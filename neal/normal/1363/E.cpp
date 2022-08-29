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


int N;
vector<int> A, B, C;
vector<vector<int>> adj;
int64_t answer;

array<int, 2> solve(int node, int parent) {
    if (parent >= 0)
        A[node] = min(A[node], A[parent]);

    array<int, 2> needs = {0, 0};

    if (B[node] < C[node])
        needs[0]++;
    else if (B[node] > C[node])
        needs[1]++;

    for (int neigh : adj[node])
        if (neigh != parent) {
            array<int, 2> below = solve(neigh, node);
            needs[0] += below[0];
            needs[1] += below[1];
        }

    int here = min(needs[0], needs[1]);
    answer += 2LL * here * A[node];
    needs[0] -= here;
    needs[1] -= here;
    return needs;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    A.resize(N);
    B.resize(N);
    C.resize(N);
    adj.assign(N, {});

    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i] >> C[i];

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    answer = 0;
    array<int, 2> result = solve(0, -1);

    if (result[0] != 0 || result[1] != 0)
        cout << -1 << '\n';
    else
        cout << answer << '\n';
}