#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2e5 + 5;

int n, m;
vi g[N], grev[N];

bool cycle, rstack[N], visited[N], visitedr[N];

void dfs_cycle(int x) {
    if (cycle) return;
    rstack[x] = visited[x] = true;

    for (int &i : g[x]) {
        if (rstack[i])
            cycle = true;
        if (!visited[i])
            dfs_cycle(i);
    }
    rstack[x] = false;
}

bool t_sort() {
    cycle = false;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] and !cycle)
            dfs_cycle(i);
    }
    return cycle;
}

void dfs1(int x) {
    visited[x] = true;

    for (auto &i : g[x]) {
        if (!visited[i])
            dfs1(i);
    }
}

void dfs2(int x) {
    visitedr[x] = true;

    for (auto &i : grev[x]) {
        if (!visitedr[i])
            dfs2(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        grev[v].push_back(u);
    }

    if (t_sort()) {
        cout << "-1\n";
        return 0;
    }

    fill(visited + 1, visited + n + 1, false);

    string s;
    int c = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] and !visitedr[i]) {
            s.push_back('A');
            c += 1;
        }
        else s.push_back('E');
        dfs1(i);
        dfs2(i);
    }

    cout << c << "\n" << s << "\n";
    return 0;
}