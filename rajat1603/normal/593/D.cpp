#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n , q;
vector < pair < int , int > > v[N];
long long weight[N];
int edge1[N];
int edge2[N];
int type , a , b;
long long y;
long long val[N];
int depth[N];
int dp[LN][N];
int parent[N];
int find(int node){
    if(val[node] > 1){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void dfs(int node , int baap , int level){
    depth[node] = level;
    parent[node] = baap;
    dp[0][node] = baap;
    for(auto it : v[node]){
        if(it.first != baap){
            val[it.first] = weight[it.second];
            dfs(it.first , node , level + 1);
        }
    }
}
int lca(int a , int b){
    if(depth[a] < depth[b]){
        return lca(b , a);
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
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d %lld" , &a , &b , weight + i);
        v[a].emplace_back(make_pair(b , i));
        v[b].emplace_back(make_pair(a , i));
        edge1[i] = a;
        edge2[i] = b;
    }
    val[1] = 2;
    dfs(1 , 0 , 0);
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    while(q--){
        scanf("%d" , &type);
        if(type == 1){
            scanf("%d %d %lld" , &a , &b , &y);
            int lc = lca(a , b);
            int cur = a;
            while(y && depth[cur] > depth[lc]){
                y /= val[cur];
                cur = find(parent[cur]);
            }
            cur = b;
            while(y && depth[cur] > depth[lc]){
                y /= val[cur];
                cur = find(parent[cur]);
            }
            printf("%lld\n" , y);
        }
        else{
            scanf("%d %lld" , &a , &y);
            weight[a] = y;
            if(edge2[a] == dp[0][edge1[a]]){
                swap(edge1[a] , edge2[a]);
            }
            val[edge2[a]] = y;
        }
    }
}