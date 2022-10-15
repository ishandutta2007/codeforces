#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v[202020];
vector<int> w[202020];
vector<pair<int,int>> e, e2;

int z[202020];
int f[202020];
bool ok;
int g;
int h[202020];
int hh;

void dfs1(int s) {
    if (z[s] == 1) ok = false;
    if (!ok) return;
    if (z[s] == 2) return;
    z[s] = 1;
    for (auto u : v[s]) dfs1(u);
    z[s] = 2;
    h[s] = ++hh;
}

void dfs2(int s) {
    if (z[s] == 3) return;
    z[s] = 3;
    g = min(g,s);
    for (auto u : w[s]) dfs2(u);
}

void dfs3(int s) {
    if (z[s] == 4) return;
    z[s] = 4;
    f[s] = g;
    for (auto u : w[s]) dfs3(u);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            v[i].clear();
            w[i].clear();
            z[i] = f[i] = 0;
        }
        e.clear();
        e2.clear();
        for (int i = 1; i <= m; i++) {
            int t, a, b;
            cin >> t >> a >> b;
            if (t == 0) {
                e.push_back({a,b});
            } else {
                e2.push_back({a,b});
                v[a].push_back(b);
                w[a].push_back(b);
                w[b].push_back(a);
            }
        }
        ok = true;
        for (int i = 1; i <= n; i++) {
            dfs1(i);
        }
        if (!ok) {
            cout << "NO\n";
            continue;
        }
        for (int i = 1; i <= n; i++) {
            if (z[i] > 2) continue;
            g = n+1;
            dfs2(i);
            dfs3(i);
        }
        cout << "YES\n";
        for (auto x : e) {
            int a = f[x.first];
            int b = f[x.second];
            if ((a == b && h[x.first] < h[x.second]) || a > b) swap(x.first,x.second);
            cout << x.first << " " << x.second << "\n";
        }
        for (auto x : e2) {
            cout << x.first << " " << x.second << "\n";
        }
    }
}