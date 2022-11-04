#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 1;
const int N = 4e5 + 123;

int n;
vector<int> g[N];
int w[N], dp[N];
bool ans[N];

void precalc(int v, int from = -1) {
    w[v] = 1;
    
    for (int u : g[v]) {
        if (u == from) {
            continue;
        }
        
        precalc(u, v);
        w[v] += w[u];
    }
    
    dp[v] = INF;
    
    for (int u : g[v]) {
        if (u == from) {
            continue;
        }
        
        dp[v] = min(dp[v], dp[u] + w[v] - w[u]);
        if (2 * w[u] <= n) {
            dp[v] = min(dp[v], w[v] - w[u]);
        }
    }
    
    if (from != -1 && g[v].size() == 1) {
        dp[v] = 1;
    }
}

void solve(int v, int from = -1, int up = 0) {
    ans[v] &= 2 * up <= n;
    
    int k = g[v].size();
    int* a = new int[k];
    int* prefix = new int[k];
    int* suffix = new int[k];
    
    for (int i = 0; i < k; i++) {
        int u = g[v][i];
        
        if (u == from) {
            a[i] = up + w[v];
            if (2 * (n - w[v]) <= n) {
                a[i] = min(a[i], w[v]);
            }
        } else {
            ans[v] &= 2 * dp[u] <= n;
            
            a[i] = dp[u] + (n - w[u]);
            if (2 * w[u] <= n) {
                a[i] = min(a[i], n - w[u]);
            }
        }
    }
    
    prefix[0] = a[0];
    for (int i = 1; i < k; i++) {
        prefix[i] = min(prefix[i - 1], a[i]);
    }
    
    suffix[k - 1] = a[k - 1];
    for (int i = k - 2; i >= 0; i--) {
        suffix[i] = min(suffix[i + 1], a[i]);
    }
    
    for (int i = 0; i < k; i++) {
        int u = g[v][i];
        
        if (u == from) {
            continue;
        }
        
        int x = INF;
        if (i > 0) {
            x = min(x, prefix[i - 1]);
        }
        if (i < k - 1) {
            x = min(x, suffix[i + 1]);
        }
        
        if (x != INF) {
            x -= w[u];
        }
        
        if (k == 1) {
            x = 1;
        }
        
        solve(u, v, x);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    precalc(0);
    fill(ans, ans + n, true);
    solve(0);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", (int) ans[i]);
    }
    printf("\n");
    
    return 0;
}