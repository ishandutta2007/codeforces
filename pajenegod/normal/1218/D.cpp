#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
vector<vector<int>> cycles;
vector<bool> visited;
vector<int> parent;
vector<int> endpoints;
vector<int> weights;

void dfs(int u, int p)
{
    visited[u] = 1;
    parent[u] = p;
    
    for (auto [v, w] : graph[u])
    {
        if (v == parent[u] || v == p)
            continue;
        
        weights[v] = w;
        
        if (visited[v])
        {
            endpoints.push_back(u);
            parent[v] = u;
            continue;
        }
        
        dfs(v, u);
    }
}

// FWHT

int MOD = 1000000007;

int modpow(int b, int e)
{
    int a = 1;
    
    while (e)
    {
        if (e & 1)
            a = 1LL * a * b % MOD;
        b = 1LL * b * b % MOD;
        e /= 2;
    }
    
    return a;
}

struct poly
{
    int arr[1 << 17];
    
    poly()
    {
        for (int i = 0; i != 1 << 17; ++i)
            arr[i] = 0;
    }
    
    int degree()
    {
        return (1 << 17);
    }
    
    int & operator [] (int i)
    {
        return arr[i];
    }
};

poly FWHT(poly P, bool inverse) {
    for (int len = 1; 2 * len <= P.degree(); len <<= 1) {
        for (int i = 0; i < P.degree(); i += 2 * len) {
            for (int j = 0; j < len; j++) {
                int u = P[i + j];
                int v = P[i + len + j];
                P[i + j] = ((u + v) % MOD + MOD) % MOD;
                P[i + len + j] = ((u - v) % MOD + MOD) % MOD;
            }
        }
    }
    
    if (inverse) {
        for (int i = 0; i < P.degree(); i++)
            P[i] = 1LL * P[i] * modpow(P.degree(), MOD - 2) % MOD;
    }

    return P;
}

//

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    int total = 0;
    graph.resize(n);
    for (int i = 0; i != m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        
        u--;
        v--;
        
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        
        total ^= w;
    }
    
    visited.resize(n);
    parent.resize(n, -1);
    weights.resize(n);
    dfs(0, -1);
    
    for (int u : endpoints)
    {
        cycles.push_back({weights[u]});
        for (int v = parent[u]; v != u; v = parent[v])
            cycles[cycles.size() - 1].push_back(weights[v]);;
    }
    
    // FWHT
    
    vector<poly> polys(cycles.size());
    for (int i = 0; i != cycles.size(); ++i)
    {
        for (int v : cycles[i])
            polys[i][v]++;
        
        polys[i] = FWHT(polys[i], 0);
    }
    
    poly Q = poly();
    for (int i = 0; i != 1 << 17; ++i)
        Q[i] = 1;
    for (poly & a : polys)
        for (int i = 0; i != 1 << 17; ++i)
            Q[i] = 1LL * Q[i] * a[i] % MOD;
    
    Q = FWHT(Q, 1);
    
    MOD = 998244353;
    
    polys = vector<poly> (cycles.size());
    for (int i = 0; i != cycles.size(); ++i)
    {
        for (int v : cycles[i])
            polys[i][v]++;
        
        polys[i] = FWHT(polys[i], 0);
    }
    
    poly QQ = poly();
    for (int i = 0; i != 1 << 17; ++i)
        QQ[i] = 1;
    for (poly & a : polys)
        for (int i = 0; i != 1 << 17; ++i)
            QQ[i] = 1LL * QQ[i] * a[i] % MOD;
    
    QQ = FWHT(QQ, 1);
    
    for (int i = 0; i != 1 << 17; ++i)
    {
        if (Q[i ^ total] || QQ[i ^ total])
        {
            cout << i << ' ' << Q[i ^ total] << '\n';
            break;
        }
    }
    
    return 0;
}