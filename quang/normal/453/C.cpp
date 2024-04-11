#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n, m, start;
int x[N], need[N];
vector <int> a[N], aT[N], res;
bool used[N];

void Make_graph() {
    queue <int> q;
    q.push(start);
    used[start] = 1;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)a[u].size(); i++) {
            int v = a[u][i];
            if(!used[v]) {
                used[v] = 1;
                q.push(v);
                aT[u].push_back(v);
            }
        }
    }
}

void Loaibo(int u) {
    need[u] = x[u];
    for(int i = 0; i < (int)aT[u].size(); i++) {
        int v = aT[u][i];
        Loaibo(v);
        need[u] |= need[v];
    }
}

void DFS(int u, int par) {
    res.push_back(u);
    x[u] ^= 1;
    for(int i = 0; i < (int)aT[u].size(); i++) {
        int v = aT[u][i];
        if(need[v]) {
            DFS(v, u);
            res.push_back(u);
            x[u] ^= 1;
        }
    }
    if(x[u]) {
        if(par) {
            x[u] ^= 1;
            x[par] ^= 1;
            res.push_back(par);
            res.push_back(u);
        }
        else {
            res.pop_back();
            x[u] ^= 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        cin >> x[i];
        if(x[i]) start = i;
    }
    Make_graph();
    Loaibo(start);
    DFS(start, 0);
    for(int i = 1; i <= n; i++)
    if(x[i]) {
        cout << -1;
        return 0;
    }
    cout << res.size() << endl;
    for(int i = 0; i < (int)res.size(); i++) cout << res[i] << " ";
    return 0;
}