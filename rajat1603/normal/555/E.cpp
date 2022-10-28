#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n , m , q;
int a[N] , b[N];
vector < pair < int , int > > v[N];
bool bridge[N];
bool visited[N];
int tin[N];
int anc[N];
int timer = 0;
int cur = 0;
int comp[N];
int dp[LN][N];
int depth[N];
vector < int > g[N];
int arr1[N];
int arr2[N];
int inpcomp[N];
int inpcur = 0;
int x , y , z;
void dfs(int node , int edge){
    inpcomp[node] = inpcur;
    visited[node] = 1;
    tin[node] = anc[node] = ++timer;
    for(auto it : v[node]){
        if(!visited[it.first]){
            dfs(it.first , it.second);
            anc[node] = min(anc[node] , anc[it.first]);
        }
        else if(edge != it.second){
            anc[node] = min(anc[node] , tin[it.first]);
        }
    }
    if(anc[node] == tin[node]){
        bridge[edge] = 1;
    }
}
void dfs1(int node){
    for(auto it : v[node]){
        if(!bridge[it.second] && !comp[it.first]){
            comp[it.first] = cur;
            dfs1(it.first);
        }
    }
}
void dfs2(int node , int baap){
    depth[node] = depth[baap] + 1;
    dp[0][node] = baap;
    for(int next : g[node]){
        if(next != baap){
            dfs2(next , node);
        }
    }
}
int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b];
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            a = dp[i][a];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        a = dp[0][a];
    }
    return a;
}
void dfs3(int node , int baap){
    for(int next : g[node]){
        if(next != baap){
            dfs3(next , node);
            arr1[node] += arr1[next];
            arr2[node] += arr2[next];
        }
    }
    if(min(arr1[node] , arr2[node]) > 0){
        printf("No\n");
        exit(0);
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &q);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
        v[a[i]].emplace_back(make_pair(b[i] , i));
        v[b[i]].emplace_back(make_pair(a[i] , i));
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            ++inpcur;
            dfs(i , 0);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!comp[i]){
            ++cur;
            comp[i] = cur;
            dfs1(i);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(bridge[i]){
            g[comp[a[i]]].emplace_back(comp[b[i]]);
            g[comp[b[i]]].emplace_back(comp[a[i]]);
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(!dp[0][i]){
            dfs2(i , 0);
        }
    }
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= cur ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    while(q--){
        scanf("%d %d" , &x , &y);
        if(inpcomp[x] != inpcomp[y]){
            printf("No\n");
            return 0;
        }
        x = comp[x];
        y = comp[y];
        z = lca(x , y);
        ++arr1[x];
        --arr1[z];
        ++arr2[y];
        --arr2[z];
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(!dp[0][i]){
            dfs3(i , 0);
        }
    }
    printf("Yes\n");
}