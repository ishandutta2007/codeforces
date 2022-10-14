#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N, M = 0;
map<lint, set<lint>> G;
vector<lint> MIN, MAX;
vector<pair<lint, lint>> E;

deque<lint> euler_path;
void dfs(lint n) {
    while (G[n].size() > 0) {
        auto e = E[*G[n].begin()];
        int id = *G[n].begin();
        if (G[e.first].count(id)) {
            G[e.first].erase(id);
            G[e.second].erase(id ^ 1);
        } else {
            G[e.second].erase(id);
            G[e.first].erase(id ^ 1);
        }
        dfs(e.first ^ e.second ^ n);
    }
    euler_path.emplace_back(n);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    MIN.resize(N - 1), MAX.resize(N - 1);
    for (int i = 0; i + 1 < N; i++) {
        cin >> MIN[i];
    }
    for (int i = 0; i + 1 < N; i++) {
        cin >> MAX[i];
    }
    for (int i = 0; i + 1 < N; i++) {
        if (MIN[i] > MAX[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    for (int i = 0; i + 1 < N; i++) {
        G[MIN[i]].emplace(M);
        G[MAX[i]].emplace(M + 1);
        E.emplace_back(MIN[i], MAX[i]);
        E.emplace_back(MAX[i], MIN[i]);
        M += 2;
    }

    int v1 = -1, v2 = -1;
    for (auto& i : G) {
        if (i.second.size() % 2 == 0) continue;
        if (v1 == -1) {
            v1 = i.first;
            continue;
        }
        if (v2 == -1) {
            v2 = i.first;
            continue;
        }
        cout << -1 << "\n";
        return 0;
    }
    
    // cout << G[1].size() << " " << G[3].size() << "\n";
    // cout << v1 << " " << v2 << "\n";

    if (v1 != -1 && v2 != -1) {
        G[v1].emplace(M);
        G[v2].emplace(M + 1);
        E.emplace_back(v1, v2);
        E.emplace_back(v2, v1);
        M += 2;
    }    

    dfs(G.begin()->first);

    if (v1 != -1 && v2 != -1) euler_path.pop_back();
    while (v1 != -1 && v2 != -1) {
        if (euler_path[0] == v1 && euler_path.back() == v2) {
            break;
        }
        swap(v1, v2);
        if (euler_path[0] == v1 && euler_path.back() == v2) {
            break;
        }
        euler_path.push_front(euler_path.back());
        euler_path.pop_back();
    }
    if (euler_path.size() != N) {
        cout << -1 << "\n";
        return 0;
    }
    for (auto i : euler_path) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}