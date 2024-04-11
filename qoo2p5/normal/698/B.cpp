#include <bits/stdc++.h>

using namespace std;

#define ll long long
const int INF = 1e9;
const ll LINF = 1e18;

const int N = 2e5 + 123;

struct DSU {
    int parent[N];
    
    DSU() {
        for (int i = 0; i < N; i++) {
            parent[i] = i;
        }
    }
    
    int get(int u) {
        if (parent[u] == u) {
            return u;
        }
        
        return parent[u] = get(parent[u]);
    }
    
    void unite(int u, int v) {
        u = get(u);
        v = get(v);
        parent[u] = v;
    }
} dsu;

int n;
int p[N];
int ans[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    
    vector<int> alone;
    vector<int> others;
    
    for (int i = 1; i <= n; i++) {
        int u = i;
        int v = p[i];
        
        if (dsu.get(u) == dsu.get(v)) {
            if (u == v) {
                alone.push_back(u);
            } else {
                others.push_back(u);
            }
        } else {
            dsu.unite(u, v);
        }
    }
    
    copy(p, p + n + 1, ans);
    
    if (!alone.empty() || !others.empty()) {
        int root;
    
        if (!alone.empty()) {
            root = alone[0];
        } else {
            root = others[0];
        }
        
        for (int i : alone) {
            ans[i] = root;
        }
        
        for (int i : others) {
            ans[i] = root;
        }
    }
    
    int to_correct = 0;
    for (int i = 1; i <= n; i++) {
        to_correct += p[i] != ans[i];
    }
    
    printf("%d\n", to_correct);
    for (int i = 1; i <= n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    
    return 0;
}