#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N, M;
set<pair<int, int>> edges;
vector<vector<int>> adj;
vector<int> group;
vector<int> group_list[4];
vector<bool> visited;

bool set_group(int node, int g) {
    if (group[node] >= 0 && group[node] != g)
        return false;

    if (group[node] != g) {
        group[node] = g;
        group_list[g].push_back(node);
    }

    return true;
}

bool edge_exists(int a, int b) {
    if (a > b)
        swap(a, b);

    return edges.find({a, b}) != edges.end();
}

bool dfs(int node) {
    assert(!visited[node]);
    visited[node] = true;

    assert(group[node] >= 0);

    for (int &x : adj[node])
        if (group[x] >= 0) {
            swap(x, adj[node].front());
            break;
        }

    int front = adj[node].front();
    assert(group[front] >= 0 && group[front] != group[node]);
    int other = 1 + 2 + 3 - group[node] - group[front];

    for (int x : adj[node]) {
        if (x == adj[node].front())
            continue;

        if (edge_exists(x, adj[node].front())) {
            if (!set_group(x, other))
                return false;
        } else {
            if (!set_group(x, group[front]))
                return false;
        }
    }

    for (int x : adj[node])
        if (!visited[x] && !dfs(x))
            return false;

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});
    group.assign(N, -1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges.insert({a, b});
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < N; i++)
        if (adj[i].size() < 2) {
            cout << -1 << '\n';
            return 0;
        }

    set_group(0, 1);
    set_group(adj[0].front(), 2);
    visited.assign(N, false);

    if (!dfs(0)) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++)
        if (group[i] < 0) {
            cout << -1 << '\n';
            return 0;
        }

    for (int g = 1; g <= 3; g++)
        if (group_list[g].empty()) {
            cout << -1 << '\n';
            return 0;
        }

    long long edge_count = 0;

    for (int a = 1; a <= 3; a++)
        for (int b = a + 1; b <= 3; b++) {
            edge_count += (long long) group_list[a].size() * group_list[b].size();

            for (int x : group_list[a])
                for (int y : group_list[b])
                    if (!edge_exists(x, y)) {
                        cout << -1 << '\n';
                        return 0;
                    }
        }

    if (edge_count != M) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++)
        cout << group[i] << (i < N - 1 ? ' ' : '\n');
}