#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())

const int maxn = 2e5 + 42;

int n;
vector<int> graph[maxn];
int size_[maxn];
int heavy[maxn];
int h[maxn];
int parent[maxn];

void dfs(int v) {
    size_[v] = 1;
    int maxchild = 0;
    for (auto to: graph[v]) {
        if (to != parent[v]) {
            parent[to] = v;
            h[to] = h[v] + 1;
            dfs(to);
            size_[v] += size_[to];
            if (size_[to] > maxchild) {
                maxchild = size_[to];
                heavy[v] = to;
            }
        }
    }
}

int askD(int v) {
    cout << "d " << v << endl;
    int x;
    cin >> x;
    assert(x != -1);
    return x;
}

int askS(int v) {
    cout << "s " << v << endl;
    int x;
    cin >> x;
    assert(x != -1);
    return x;
}

void ok(int v) {
    cout << "! " << v << endl;
    exit(0);
}

void solve(int v, int depth) {
    if (depth == 0) {
        ok(v);
    }
    vector<int> path;
    for (int i = v; i != 0; i = heavy[i]) {
        path.push_back(i);
    }
    int xleaf = askD(path.back());
    int vleaf = h[path.back()] - h[v];
    
    int a = ((depth - h[v]) + vleaf - xleaf);
    assert(a >= 0 && a % 2 == 0);
    a /= 2;
    assert(a < sz(path));
    int u = path[a];
    if (a == depth - h[v]) {
        ok(u);
    }
    solve(askS(u), depth);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1);
    
    int depth = askD(1);
    solve(1, depth);
}