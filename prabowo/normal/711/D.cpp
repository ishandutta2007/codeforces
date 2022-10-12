#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int N = 200005;

int par[N];
int dist[N];
vector <int> edge[N];

int sum;
int cycle;
int dsu(int u) {
    if (u == par[u]) return u;
    return par[u] = dsu(par[u]);
}   

int power(int x, int y) {
    return y ? y & 1 ? 1LL * x * power(1LL * x * x % MOD, y >> 1) % MOD : power(1LL * x * x % MOD, y >> 1) : 1;
}

void bfs(int u) {
    queue <int> q;
    q.push(u);
    dist[u] = 0;
    
    while (q.size()) {
        int u = q.front();
        
        // cout << u << endl;
        q.pop();

        for (int i=0; i<edge[u].size(); i++) {
            int v = edge[u][i];
            if (dist[v] >= 0) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int main() {
    int n;
    scanf ("%d", &n);
    
    int u; memset (dist, -1, sizeof dist);
    for (int i=0; i<n; i++) par[i] = i;
    
    long long ans = 1;
    int sum = n;
    for (int i=0; i<n; i++) {
        scanf ("%d", &u);
        u--;
     
        if (dsu(u) == dsu(i)) {
            bfs(u);
            // cout << dist[i] + 1 << endl;
            ans *= (power(2, dist[i] + 1) - 2 + MOD) % MOD;
            ans %= MOD;
            sum -= dist[i] + 1;
        }
        
        par[dsu(u)] = dsu(i);
        
        edge[u].push_back(i);
        edge[i].push_back(u);
    }
    
    ans *= power(2, sum);
    ans %= MOD;
    
    // cout << power(2, n) << endl;
    // cout << cycle << " " << sum << endl;
    printf ("%I64d\n", ans);
    
    return 0;
}