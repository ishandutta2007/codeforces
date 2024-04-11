#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int LN = 17;
int n;
int a[N] , b[N];
vector < int > v[N];
int x , y;
int dp[LN][N];
int depth[N];
int sum[N];
int q;
void dfs(int node , int parent){
    depth[node] = depth[parent] + 1;
    dp[0][node] = parent;
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            sum[node] += sum[next];
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
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &x , &y);
        v[x].emplace_back(y);
        v[y].emplace_back(x);
        a[i] = x;
        b[i] = y;
    }
    dfs(1 , 0);
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    scanf("%d" , &q);
    while(q--){
        scanf("%d %d" , &x , &y);
        ++sum[x];
        ++sum[y];
        sum[lca(x , y)] -= 2;
    }
    dfs(1 , 0);
    for(int i = 1 ; i < n ; ++i){
        if(depth[a[i]] < depth[b[i]]){
            swap(a[i] , b[i]);
        }
        printf("%d " , sum[a[i]]);
    }
}