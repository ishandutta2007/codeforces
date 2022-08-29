#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int N;
vector<vector<int>> adj;
vector<pair<int, int>> answer;

void dfs(int node, int parent, int time) {
    // Erase the edge to parent.
    adj[node].erase(remove(adj[node].begin(), adj[node].end(), parent), adj[node].end());
    answer.emplace_back(node, time);
    int children = adj[node].size();
    int goal = parent < 0 ? children : time - 1;
    bool subtracted = false;

    for (int child : adj[node]) {
        if (!subtracted && time > children) {
            time -= children + 1;
            answer.emplace_back(node, time);
            subtracted = true;
        }

        time++;
        dfs(child, node, time);
        answer.emplace_back(node, time);
    }

    if (time != goal) {
        assert(goal < time);
        time = goal;
        answer.emplace_back(node, time);
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1, 0);
    cout << answer.size() << '\n';

    for (pair<int, int> &vt : answer)
        cout << vt.first + 1 << ' ' << vt.second << '\n';
}