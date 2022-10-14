#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> Depth;
vector<int> Diameter;

void dfsDepth(int n = 0, int p = -1, int d = 0) {
    for (auto i : G[n]) if (i != p) dfsDepth(i, n, d + 1);
    Depth[n] = d;
}

bool dfsDiameter(int n, int t, int p = -1) {
    if (n == t) {
        Diameter.emplace_back(n);
        return true;
    }
    bool res = false;
    for (auto i : G[n]) if (i != p) res |= dfsDiameter(i, t, n);
    if (res) Diameter.emplace_back(n);
    return res;
}

vector<int> Degree;
vector<vector<int>> Distance;

void dfsDistance(int n, int p = -1, int d = 0) {
    for (auto i : G[n]) if (i != p) dfsDistance(i, n, d + 1);
    Distance[d].emplace_back(n);
}

vector<int> inDiameter;
void dfsTop(int n, int p = -1, int d = 0) {
    for (auto i : G[n]) if (i != p && inDiameter[i] == 0) dfsTop(i, n, d + 1);
    Depth[n] = d;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;
    G.resize(N);
    Depth.resize(N);
    Distance.resize(N);
    Degree.resize(N);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        Degree[u]++;
        Degree[v]++;
    }

    dfsDepth();
    int end1 = 0;
    for (int i = 0; i < N; i++) {
        if (Depth[i] > Depth[end1]) end1 = i;
    }

    dfsDepth(end1);
    int end2 = 0;
    for (int i = 0; i < N; i++) {
        if (Depth[i] > Depth[end2]) end2 = i;
    }

    dfsDiameter(end1, end2);


    bool can = true;
    dfsDistance(end1);
    for (int i = 0; i < N; i++) {
        if (Distance[i].empty()) continue;
        int k = Distance[i][0];
        for (auto j : Distance[i]) {
            if (Degree[k] != Degree[j]) {
                can = false;
                break;
            }
        }
        if (!can) break;
    }
    
    if (can) {
        cout << end1 + 1 << "\n";
        return 0;
    }

    Distance.clear();
    Distance.resize(N);
    can = true;
    dfsDistance(end2);
    for (int i = 0; i < N; i++) {
        if (Distance[i].empty()) continue;
        int k = Distance[i][0];
        for (auto j : Distance[i]) {
            if (Degree[k] != Degree[j]) {
                can = false;
                break;
            }
        }
        if (!can) break;
    }
    
    if (can) {
        cout << end2 + 1 << "\n";
        return 0;
    }

    int radius = Diameter[Diameter.size() / 2];
    Distance.clear();
    Distance.resize(N);
    can = true;
    dfsDistance(radius);
    for (int i = 0; i < N; i++) {
        if (Distance[i].empty()) continue;
        int k = Distance[i][0];
        for (auto j : Distance[i]) {
            if (Degree[k] != Degree[j]) {
                can = false;
                break;
            }
        }
        if (!can) break;
    }
    
    if (can) {
        cout << radius + 1 << "\n";
        return 0;
    }


    Depth.assign(N, -1);
    inDiameter.resize(N);
    for (auto i : Diameter) {
        inDiameter[i] = 1;
    }

    dfsTop(radius);
    int top = -1;
    for (int i = 0; i < N; i++) {
        if (Depth[i] == -1) continue;
        if (Degree[i] > 1) continue;
        if (top == -1 || Depth[top] > Depth[i]) top = i;
    }

    if (top == -1) {
        cout << -1 << "\n";
        return 0;
    }

    Distance.clear();
    Distance.resize(N);
    can = true;
    dfsDistance(top);
    for (int i = 0; i < N; i++) {
        if (Distance[i].empty()) continue;
        int k = Distance[i][0];
        for (auto j : Distance[i]) {
            if (Degree[k] != Degree[j]) {
                can = false;
                break;
            }
        }
        if (!can) break;
    }
    
    if (can) {
        cout << top + 1 << "\n";
        return 0;
    }

    cout << -1 << "\n";
    return 0;
}