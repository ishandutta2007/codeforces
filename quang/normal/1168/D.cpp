#include <bits/stdc++.h>

using namespace std;

const int N = 150010;
const int C = 26;

int n, q;
int p[N], root[N];
char c[N];
vector<int> adj[N], adj2[N];
int lv[N];
int lvLeaf;
int rootPar[N];

struct Node {
    int tot;
    bool dead;
    int now[C], child[C];
} t[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        cin >> p[i] >> c[i];
        adj[p[i]].push_back(i);
        lv[i] = lv[p[i]] + 1;
        lvLeaf = max(lvLeaf, lv[i]);
    }
    int found = 0;
    for (int i = 2; i <= n; i++) {
        if (adj[i].empty() && lv[i] != lvLeaf) {
            found = 1;
            break;
        }
    }
    if (found) {
        for (int i = 1; i <= q; i++) {
            int u;
            char c;
            cin >> u >> c;
            cout << "Fou\n";
        }
        return 0;
    }
    root[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (adj[p[i]].size() == 2) root[i] = i;
        else root[i] = root[p[i]];
    }
    for (int i = 1; i <= n; i++) {
        for (int u : adj[i]) {
            if (root[i] != root[u]) {
                adj2[root[i]].push_back(root[u]);
                rootPar[root[u]] = root[i];
            }
        }
    }

    auto add = [&](int u, char c, int delta) {
        if (c == '?') return;
        c -= 'a';
        t[u].now[c] += delta;
        u = rootPar[u];
        while (u) {
            int oldVal = t[u].child[c];
            assert(adj2[u].size() == 2);
            int x = adj2[u][0];
            int y = adj2[u][1];
            t[u].child[c] = max(t[x].now[c] + t[x].child[c], t[y].now[c] + t[y].child[c]);
            t[u].tot += t[u].child[c] - oldVal;
            int totLen = lvLeaf - lv[x] + 1;
            t[u].dead = t[x].dead | t[y].dead;
            if (totLen < t[u].tot) t[u].dead = 1;
            u = rootPar[u];
        }
    };

    auto calc = [&]() {
        if (t[1].dead) {
            cout << "Fou\n";
            return;
        }
        long long res = 0;
        int sum = 0;
        for (int i = 0; i < C; i++) {
            res += 1ll * (i + 1) * (t[1].now[i] + t[1].child[i]);
            sum += (t[1].now[i] + t[1].child[i]);
        }
        res += 351ll * (lvLeaf - sum);
        cout << "Shi " << res << '\n';
    };

    for (int i = 2; i <= n; i++) {
        add(root[i], c[i], 1);
    }
    for (int i = 1; i <= q; i++) {
        int u;
        char val;
        cin >> u >> val;
        add(root[u], c[u], -1);
        c[u] = val;
        add(root[u], c[u], 1);
        calc();
    }
    return 0;
}