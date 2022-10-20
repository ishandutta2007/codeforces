#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1e9;

int n, m, q;
int w[N];
int cntTarjan;
int num[N], low[N];
vector<int> stackTarjan;
int curNode;
vector<int> adj[N], adj2[N * 2];

multiset<int> val[N * 2];
int numChild[N * 2], par[N * 2], lv[N * 2], top[N * 2], HLDList[N * 2], posInHLD[N * 2];
int cntHLD;

void tarjan(int u, int p) {
    num[u] = low[u] = ++cntTarjan;
    stackTarjan.push_back(u);
    for (int v : adj[u]) {
        if (v == p) continue;
        if (!num[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= num[u]) {
                curNode++;
                adj2[u].push_back(curNode);
                adj2[curNode].push_back(u);
                while (1) {
                    int x = stackTarjan.back();
                    stackTarjan.pop_back();
                    adj2[x].push_back(curNode);
                    adj2[curNode].push_back(x);
                    if (x == v) break;
                }
            }
        } else low[u] = min(low[u], num[v]);
    }
}

void dfsInit(int u, int p) {
    numChild[u] = 1;
    par[u] = p;
    lv[u] = lv[p] + 1;
    for (int v : adj2[u]) {
        if (v == p) continue;
        dfsInit(v, u);
        numChild[u] += numChild[v];
    }
}

void dfsBuildHLD(int u, int p, int root) {
    top[u] = root;
    HLDList[++cntHLD] = u;
    posInHLD[u] = cntHLD;
    int maxChild = -1;
    for (int v : adj2[u]) {
        if (v == p) continue;
        if (maxChild == -1 || numChild[maxChild] < numChild[v]) {
            maxChild = v;
        }
    }
    if (maxChild != -1) dfsBuildHLD(maxChild, u, root);
    for (int v : adj2[u]) {
        if (v == p || v == maxChild) continue;
        dfsBuildHLD(v, u, v);
    }
}

struct IT {
    int t[N << 3];

    void init(int node, int l, int r) {
        if (l == r) {
            t[node] = *val[HLDList[l]].begin(); 
            return;
        }
        int m = l + r >> 1;
        init(node << 1, l, m);
        init(node << 1 | 1, m + 1, r);
        t[node] = min(t[node << 1], t[node << 1 | 1]);
    }

    void update(int node, int l, int r, int id) {
        if (id > r || id < l) return;
        if (l == r) {
            t[node] = *val[HLDList[l]].begin(); 
            return;
        }
        int m = l + r >> 1;
        update(node << 1, l, m, id);
        update(node << 1 | 1, m + 1, r, id);
        t[node] = min(t[node << 1], t[node << 1 | 1]);
    }

    int get(int node, int l, int r, int x, int y) {
        if (x > r || y < l) return INF;
        if (x <= l && r <= y) return t[node];
        int m = l + r >> 1;
        int p1 = get(node << 1, l, m, x, y);
        int p2 = get(node << 1 | 1, m + 1, r, x, y);
        return min(p1, p2);
    }
} it;   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> q;
    curNode = n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    tarjan(1, 0);
    dfsInit(1, 0);
    dfsBuildHLD(1, 0, 1);
    for (int i = 1; i <= n; i++) {
        val[i].insert(w[i]);
        if (par[i]) val[par[i]].insert(w[i]);
    }
    for (int i = 1; i <= curNode; i++) val[i].insert(INF);
    it.init(1, 1, curNode);    
    while (q--) {
        char op;
        int u, v;
        cin >> op >> u >> v;
        if (op == 'C') {
            val[u].erase(val[u].find(w[u]));
            if (par[u]) val[par[u]].erase(val[par[u]].find(w[u]));

            w[u] = v;
            val[u].insert(w[u]);
            if (par[u]) val[par[u]].insert(w[u]);
            
            it.update(1, 1, curNode, posInHLD[u]);
            if (par[u]) it.update(1, 1, curNode, posInHLD[par[u]]);
        } else {
            int res = INF;
            while (top[u] != top[v]) {
                if (lv[top[u]] < lv[top[v]]) {
                    swap(u, v);
                }
                res = min(res, it.get(1, 1, curNode, posInHLD[top[u]], posInHLD[u]));
                u = par[top[u]];
            } 
            if (lv[u] < lv[v]) swap(u, v);
            res = min(res, it.get(1, 1, curNode, posInHLD[v], posInHLD[u]));
            if (v > n && par[v]) {
                res = min(res, *val[par[v]].begin());
            }
            cout << res << '\n';
        }
    }
    return 0;
}