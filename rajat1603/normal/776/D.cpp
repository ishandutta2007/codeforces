#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int arr[N];
int sz;
vector < int > v[N];
int val;
int parent[N];
int comp[N];
int cur;
vector < int > g[N];
int col[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void join(int a , int b){
    parent[find(b)] = find(a);
}
void dfs(int node){
    for(int next : g[node]){
        if(col[next] == -1){
            col[next] = col[node] ^ 1;
            dfs(next);
        }
        else if(col[next] == col[node]){
            printf("NO\n");
            exit(0);
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        v[i].clear();
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , &sz);
        while(sz--){
            scanf("%d" , &val);
            v[val].emplace_back(i);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        parent[i] = i;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i]){
            join(v[i][0] , v[i][1]);
        }
    }
    cur = 0;
    for(int i = 1 ; i <= m ; ++i){
        if(find(i) == i){
            comp[i] = ++cur;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(find(i) != i){
            comp[i] = comp[find(i)];
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        g[i].clear();
        col[i] = -1;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!arr[i]){
            int a = comp[v[i][0]];
            int b = comp[v[i][1]];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
    }
    for(int i = 1 ; i <= cur ; ++i){
        if(col[i] == -1){
            col[i] = 0;
            dfs(i);
        }
    }
    printf("YES\n");
}