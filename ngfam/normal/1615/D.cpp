#include <bits/stdc++.h>
#define long long long

using namespace std;

const int maxn = 600005;

int N, M;
int color[maxn];
vector<int> g2[maxn];
vector<pair<int,int>> g[maxn];

bool dfs(int v, int c = 0) {
    color[v] = c;
    for(int s: g2[v]) {
        if (color[s] == -1){ 
            if (dfs(s, 1-c) == false) {
                return false;
            }
        }
        else {
            if (color[v] == color[s]) return false;
        }
    }
    return true;
}

void dfs_solve(int v, int p = -1) {
    for(auto &[s, w]: g[v]) if (s != p) {
        if (w == -1) w = color[s] ^ color[v];
        cout << s+1 << " " << v+1 << " " << w << "\n";
        dfs_solve(s, v);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int ntest; cin >> ntest;
    while(ntest--) {
        cin >> N >> M;

        int cnt = N;
        auto addEdge = [&](int u, int v) -> void {
            g2[u].push_back(v);
            g2[v].push_back(u);
        };

        for(int i = 1; i < N; ++i) {
            int u, v, w; cin >> u >> v >> w;
            --u; --v;
            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);

            if (w != -1) {
                if (__builtin_popcount(w) % 2 == 0) {
                    addEdge(u, cnt);
                    addEdge(v, cnt);
                    cnt++;
                } else {
                    addEdge(u, v);
                }
            }
        }

        while(M--) {
            int u, v, w; cin >> u >> v >> w;
            --u; --v;
            if (w == 0) {
                addEdge(u, cnt);
                addEdge(v, cnt);
                cnt++;
            } else {
                addEdge(u, v);
            }
        }
        fill(color, color+cnt, -1);

        bool able = true;
        for(int i = 0; i < N && able; ++i) {
            if (color[i] == -1) able &= dfs(i);
        }

        if (!able) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            dfs_solve(0, -1);
        }

        for(int i = 0; i <= cnt; ++i) {
            g[i].clear();
            g2[i].clear();
            color[i] = -1;
        }
    }

    return 0;
}