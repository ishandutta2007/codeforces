#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);
const ll MOD = (ll) (1e9 + 7);

template<typename A, typename B> void mini(A& x, const B& y) {
    if (y < x) {
        x = y;
    }
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = (int) 5e5 + 123;

int n, k, m;
vector<int> g[N];
vector<int> t[N];
bool vis[N];

void dfs(int v) {
    vis[v] = 1;
    for (int u : g[v]) {
        if (vis[u]) {
            continue;
        }
        t[v].push_back(u);
        t[u].push_back(v);
        dfs(u);
    }
}

pair<int, int> find_farest(int v, int p = -1) {
    pair<int, int> cur = {1, v};
    for (int u : t[v]) {
        if (u == p) continue;
        auto it = find_farest(u, v);
        it.first++;
        if (it > cur) {
            cur = it;
        }
    }
    return cur;
}

vector<int> path;

bool find_path(int v, int to, int p = -1) {
    if (v == to) {
        path.push_back(v);
        return true;
    }
    for (int u : t[v]) {
        if (u == p) continue;
        if (find_path(u, to, v)) {
            path.push_back(v);
            return true;
        }
    }
    return false;
}

int depth[N];
bool used[N];
void solve(int v, int p = -1) {
    path.push_back(v);
    used[v] = true;
    bool is_leaf = true;
    for (int u : t[v]) {
        if (u == p) {
            continue;
        }
        is_leaf = false;
        depth[u] = depth[v] + 1;
        solve(u, v);
    }
    if (is_leaf) {
        vector<int> to;
        for (int u : g[v]) {
            if (abs(depth[u] - depth[v]) == 1) {
                continue;
            }
            to.push_back(u);
            if ((int) to.size() == 2) {
                break;
            }
        }
        if (k > 0) {
            k--;
            int x = to[0];
            int y = to[1];
            if (depth[x] > depth[y]) {
                swap(x, y);
            }
            int a = depth[v] - depth[x] + 1;
            int b = depth[v] - depth[y] + 1;
            if (a % 3 != 0) {
                cout << a << "\n";
                cout << v << " ";
                for (int i = depth[x]; i < depth[v]; i++) {
                    cout << path[i] << " ";
                }
                cout << "\n";
            } else if (b % 3 != 0) {
                cout << b << "\n";
                cout << v << " ";
                for (int i = depth[y]; i < depth[v]; i++) {
                    cout << path[i] << " ";
                }
                cout << "\n";
            } else {
                cout << (a - b + 2) << "\n";
                cout << v << " ";
                for (int i = depth[x]; i <= depth[y]; i++) {
                    cout << path[i] << " ";
                }
                cout << "\n";
            }
        }
    }
    path.pop_back();
}

void run() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    auto it1 = find_farest(1);
    auto it2 = find_farest(it1.second);
    if (it2.first * 1LL * k >= n) {
        cout << "PATH" << endl;
        find_path(it1.second, it2.second);
        cout << path.size() << endl;
        reverse(path.begin(), path.end());
        for (int v : path) {
            cout << v << " ";
        }
        cout << endl;
        return;
    }

    cout << "CYCLES" << endl;
    solve(1);
}