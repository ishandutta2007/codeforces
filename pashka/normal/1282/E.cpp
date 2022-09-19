#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int n;
vector<vector<int>> g;
vector<vector<int>> a;
map<pair<int, int>, vector<int>> ed;

vector<pair<int, int>> path;
vector<int> order;

void dfs(int v, int x, int y) {
//    cout << v << " " << x << " " << y << "\n";
    vector<pair<int, int>> go;
    if (x != -1) {
        int z = -1;
        for (int i = 0; i < 3; i++) {
            if (a[v][i] != x && a[v][i] != y) {
                z = a[v][i];
            }
        }
        go = {{x, z},
              {z, y}};
    } else {
        for (int i = 0; i < 3; i++) {
            int x = a[v][i];
            int y = a[v][(i + 1) % 3];
            go.push_back({x, y});
        }
    }
    for (auto p : go) {
        auto pp = p;
        if (p.first > p.second) {
            swap(p.first, p.second);
        }
        if (ed[p].size() == 1) {
            path.push_back(pp);
        } else {
            for (auto u : ed[p]) {
                if (u != v) {
                    dfs(u, pp.first, pp.second);
                }
            }
        }
    }
    order.push_back(v);
}

void solve_test() {
    cin >> n;
    n -= 2;
    g.clear();
    g.resize(n);
    a.assign(n, vector<int>(3));
    ed.clear();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
        for (int j = 0; j < 3; j++) {
            int x = a[i][j];
            int y = a[i][(j + 1) % 3];
            if (x > y) swap(x, y);
            ed[{x, y}].push_back(i);
        }
    }

    path.clear();
    order.clear();
    dfs(0, -1, -1);
    for (auto p : path) {
        cout << p.second << " ";
    }
    cout << "\n";
    for (auto x : order) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}