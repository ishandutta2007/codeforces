#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n , q;
int dp[LN][N];
int par[N];
int lvl[N];
int subtree[N];
int ans[N];
int cnt;
set < int > v[N];
int inp1 , inp2;
void dfs1(int node , int parent){
    for(int next : v[node]){
        if(next != parent){
            dp[0][next] = node;
            lvl[next] = lvl[node] + 1;
            dfs1(next , node);
        }
    }
    ans[node] = lvl[node];
}
void pre(){
    dp[0][1] = 0;
    lvl[1] = 0;
    dfs1(1 , 0);
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}
void dfs2(int node , int parent){
    subtree[node] = 1;
    ++cnt;
    for(int next : v[node]){
        if(next != parent){
            dfs2(next , node);
            subtree[node] += subtree[next];
        }
    }
}
int centroid(int node , int parent){
    for(int next : v[node]){
        if(next != parent){
            if(subtree[next] > cnt){
                return centroid(next , node);
            }
        }
    }
    return node;
}
void decompose(int node , int parent){
    cnt = 0;
    dfs2(node , parent);
    cnt >>= 1;
    int centre = centroid(node , parent);
    par[centre] = parent;
    for(int next : v[centre]){
        if(next != parent){
            v[next].erase(centre);
            decompose(next , centre);
        }
    }
    v[centre].clear();
}
int lca(int a , int b){
    if(lvl[a] < lvl[b]){
        return lca(b , a);
    }
    int dif = lvl[a] - lvl[b];
    for(int i = 0 ; i < LN ; ++i){
        if((dif >> i) & 1){
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
int dist(int a , int b){
    return lvl[a] + lvl[b] - (lvl[lca(a , b)] << 1);
}
void update(int node , int rednode){
    while(node){
        ans[node] = min(ans[node] , dist(node , rednode));
        node = par[node];
    }
}
int query(int node , int qnode){
    int ret = INT_MAX;
    while(node){
        ret = min(ret , ans[node] + dist(node , qnode));
        node = par[node];
    }
    return ret;
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &inp1 , &inp2);
        v[inp1].insert(inp2);
        v[inp2].insert(inp1);
    }
    pre();
    decompose(1 , 0);
    while(q--){
        scanf("%d %d" , &inp1 , &inp2);
        if(inp1 & 1){
            update(inp2 , inp2);
        }
        else{
            printf("%d\n" , query(inp2 , inp2));
        }
    }
}