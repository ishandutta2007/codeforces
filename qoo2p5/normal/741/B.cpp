#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef double ld;

const int N = 1001;

int n, m, s;
int w[N], b[N];
bool vis[N];
vector<int> g[N];
int ptr;

struct {
    int sum_w, sum_b;
    vector<int> ids;
} comp[N];

void dfs(int v) {
    vis[v] = 1;
    comp[ptr].ids.push_back(v);
    comp[ptr].sum_w += w[v];
    comp[ptr].sum_b += b[v];
    for (int u : g[v]) {
        if (vis[u]) {
            continue;
        }
        dfs(u);
    }
}

int dp1[N], dp2[N];

void run() {
    cin >> n >> m >> s;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    for (int v = 0; v < n; v++) {
        if (!vis[v]) {
            dfs(v);
            ptr++;
        }
    }
    
    for (int i = 0; i < ptr; i++) {
        copy(dp1, dp1 + N, dp2);
        for (int j : comp[i].ids) {
            for (int from = 0; from < N; from++) {
                int to = from + w[j];
                if (to < N) {
                    dp2[to] = max(dp2[to], dp1[from] + b[j]);
                }
            }
        }
        
        {
            for (int from = 0; from < N; from++) {
                int to = from + comp[i].sum_w;
                if (to < N) {
                    dp2[to] = max(dp2[to], dp1[from] + comp[i].sum_b);
                }
            }
        }
        
        swap(dp1, dp2);
    }
    
    int ans = 0;
    
    for (int i = 0; i <= s; i++) {
        ans = max(ans, dp1[i]);
    }
    
    cout << ans << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}