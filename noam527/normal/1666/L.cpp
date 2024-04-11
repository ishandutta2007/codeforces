#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
const int OO = 1;
using namespace std;

int n, m, s;
vector<vector<int>> g;
vector<int> vis, par, src;

void dfs(int v, int prev, int sr){
    if (vis[v]) return;
    vis[v] = 1;
    par[v] = prev;
    src[v] = sr;
    for (const auto &i : g[v]){
        dfs(i, v, sr);
    }
}

vector<int> path(int x){
    vector<int> res = {x};
    while (x != s){
        x = par[x];
        res.push_back(x);
    }
    reverse(res.begin(), res.end());
    return res;
}

void output(const vector<int> &a, const vector<int> &b){
    cout << "Possible\n";
    cout << a.size() << '\n';
    for (const auto &i : a) cout << i + 1 << " "; cout << '\n';
    cout << b.size() << '\n';
    for (const auto &i : b) cout << i + 1 << " "; cout << '\n';
}

void solve(){
    cin >> n >> m >> s;
    --s;
    g.resize(n);
    vis.resize(n, 0);
    par.resize(n);
    src.resize(n, -1);
    for (int i = 0, u, v; i < m; i++){
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }
    vis[s] = 1;
    for (const auto &v : g[s]){
        dfs(v, s, v);
    }
    // case 1:
    for (const auto &v : g[s]){
        if (src[v] != v){
            auto path1 = path(v);
            vector<int> path2 = {s, v};
            output(path1, path2);
            return;
        }
    }
    for (int i = 0; i < n; i++){
        if (i == s) continue;
        for (const auto &j : g[i]) {
            if (src[i] != src[j] && j != s && i != s && src[i] != -1 && src[j] != -1) {
                auto path1 = path(j);
                auto path2 = path(i);
                path2.push_back(j);
                output(path1, path2);
                return;
            }
        }
    }
    cout << "Impossible\n";
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
}