/* Riven is not just my life :) */

#include <bits/stdc++.h>
#define prob "test"
typedef long long llint;
using namespace std;
void MAIN();
int main(){
    #ifndef ONLINE_JUDGE
        freopen(prob".inp","r",stdin);
      //  freopen(prob".out","w",stdout);
    #endif
    MAIN();
    return 0;
}
const llint N = 2e5 + 1, mod = 1e9 + 7;

int n, m, child[N], lenChild[N], par[N], lenTotal[N], lenFinal[N];
int cntHave[N], lenFar[N], maxLevel[N], lenPar[N], ok[N];

vector < int > adj[N];

void dfs(int u){
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;

        par[v] = u; dfs(v);
        lenChild[u] += lenChild[v] + child[v];
        child[u] += child[v];
    }
}

void dfs2(int u){
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;

        dfs2(v);
        if(child[v] > 0){
            ++cntHave[u];
            lenTotal[u] += lenTotal[v] + 2;
        }
    }
}

void dfs3(int u){
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;

        lenFinal[v] = lenFinal[u] - (child[v] > 0) * 2 + (child[0] - child[u] > 0 || child[u] - child[v] > 0) * 2;
        dfs3(v);
    }
}

void dfs4(int u){
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;

        dfs4(v);
        if(child[v] > 0){
            maxLevel[u] = max(maxLevel[u], maxLevel[v] + 1);
        }
    }
}

void dfs5(int u){
    int bigFirst = n + 1, bigSecond = n + 1, sz = adj[u].size();

    for(int i = 0; i < sz ; ++i){
        int v = adj[u][i];
        if(v == par[u]) continue;
        if(maxLevel[v] >= maxLevel[bigFirst]){
            bigSecond = bigFirst;
            bigFirst = v;
        }
        else{
            if(maxLevel[v] >= maxLevel[bigSecond]){
                bigSecond = v;
            }
        }
    }
    lenFinal[u] -= max(maxLevel[u], lenPar[u]);

    for(int i = 0; i < sz ;++i){
        int v = adj[u][i];
        if(v == par[u]) continue;
        if(child[v] < 1) continue;
        if(child[u] - child[v] - ok[u] == 0){
            if(child[0] - child[u] == 0) lenPar[v] = ok[u];
            else lenPar[v] = lenPar[u] + 1;
            dfs5(v);
        }
        else{
            int node = bigFirst;
            if(v == bigFirst) node = bigSecond;

            lenPar[v] = max(lenPar[u] + 1, maxLevel[node] + 2);
            dfs5(v);
        }
    }
}

void MAIN(){
    scanf("%d%d", &n, &m);

    for(int i = 1; i < n; ++i){
        int u, v; scanf("%d%d", &u, &v);
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= m; ++i){
        int u; scanf("%d", &u);
        --u;
        child[u] = 1;
        ok[u] = 1;
    }
    dfs(0);
    dfs2(0);
    lenFinal[0] = lenTotal[0];;
    dfs3(0);
    dfs4(0);
    dfs5(0);
    //cerr << maxLevel[0] << endl;
    int ans = mod;
    for(int i = 0; i < n; ++i){
        ans = min(ans, lenFinal[i]);
    }
    for(int i = 0; i < n; ++i){
        if(lenFinal[i] == ans){
            printf("%d\n%d", i + 1, ans);
            return;
        }
    }
}