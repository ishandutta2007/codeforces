#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int LN = 18;
int n , m;
int a , b , c;
vector < pair < int , int > > v[N];
int dp[LN][N];
int mx[LN][N];
pair < pair < int , int > , pair < int , int > > edges[N];
int parent[N];
long long sum = 0;
int depth[N];
long long ans[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
bool join(int a , int b){
    if(find(a) == find(b)){
        return 0;
    }
    parent[find(a)] = find(b);
    return 1;
}
void dfs(int node , int parent){
    dp[0][node] = parent;
    for(auto it : v[node]){
        if(it.first != parent){
            depth[it.first] = depth[node] + 1;
            mx[0][it.first] = it.second;
            dfs(it.first , node);
        }
    }
}
int lca(int a , int b){
    if(depth[a] < depth[b]){
        swap(a , b);
    }
    int dif = depth[a] - depth[b];
    int val = 0;
    for(int i = 0 ; i < LN ; ++i){
        if(dif & (1 << i)){
            val = max(val , mx[i][a]);
            a = dp[i][a];
        }
    }
    if(a != b){
        for(int i = LN - 1 ; i >= 0 ; --i){
            if(dp[i][a] != dp[i][b]){
                val = max(val , max(mx[i][a] , mx[i][b]));
                a = dp[i][a];
                b = dp[i][b];
            }
        }
        val = max(val , max(mx[0][a] , mx[0][b]));
    }
    return val;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        edges[i] = make_pair(make_pair(c , i) , make_pair(a , b));
    }
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    sort(edges + 1 , edges + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        if(join(edges[i].second.first , edges[i].second.second)){
            sum += edges[i].first.first;
            v[edges[i].second.first].emplace_back(make_pair(edges[i].second.second , edges[i].first.first));
            v[edges[i].second.second].emplace_back(make_pair(edges[i].second.first , edges[i].first.first));
        }
    }
    mx[0][1] = 0;
    depth[1] = 0;
    dfs(1 , 0);
    for(int i = 1 ; i < LN ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            mx[i][j] = max(mx[i - 1][j] , mx[i - 1][dp[i - 1][j]]);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        ans[edges[i].first.second] = sum - lca(edges[i].second.first , edges[i].second.second) + edges[i].first.first;
    }
    for(int i = 1 ; i <= m ; ++i){
        printf("%lld\n" , ans[i]);
    }
}