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
vector<int64_t> T;
vector<int> H;
vector<vector<int>> adj;
vector<array<int64_t, 2>> dp;

array<int64_t, 2> solve(int node, int parent) {
    if (dp[node][0] >= 0)
        return dp[node];

    vector<int> &children = adj[node];
    children.erase(remove(children.begin(), children.end(), parent), children.end());
    array<int64_t, 2> &answer = dp[node];

    for (int down = 0; down <= 1; down++) {
        array<int, 2> counts = {0, 0};

        if (parent >= 0)
            counts[!down]++;

        int64_t &ans = answer[down];
        int64_t sum = 0;
        vector<array<int64_t, 2>> optional;

        // Find the mandatory edges and the optional edges.
        for (int child : children) {
            array<int64_t, 2> result = solve(child, node);

            if (H[node] != H[child]) {
                sum += result[H[node] < H[child]];
                counts[H[node] < H[child]]++;
            } else {
                optional.push_back(result);
            }
        }

        vector<int64_t> differences;

        for (auto &choice : optional) {
            sum += choice[0];
            counts[0]++;
            differences.push_back(choice[1] - choice[0]);
        }

        sort(differences.rbegin(), differences.rend());
        ans = sum + min(counts[0], counts[1]) * T[node];

        for (auto &diff : differences) {
            sum += diff;
            counts[0]--;
            counts[1]++;
            ans = max(ans, sum + min(counts[0], counts[1]) * T[node]);
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    T.resize(N);
    H.resize(N);

    for (auto &t : T)
        cin >> t;

    for (auto &h : H)
        cin >> h;

    adj.assign(N, {});
    int64_t edge_total = 0;

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edge_total += T[u] + T[v];
    }

    dp.assign(N, {-1, -1});
    cout << edge_total - solve(0, -1)[0] << '\n';
}