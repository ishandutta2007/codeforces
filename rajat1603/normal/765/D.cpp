#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int f[N];
int parent[N];
vector < int > v[N];
int m;
int g[N];
int h[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void join(int a , int b){
    parent[find(a)] = find(b);
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
        v[i].clear();
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , f + i);
        v[f[i]].emplace_back(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j < v[i].size() ; ++j){
            join(v[i][j - 1] , v[i][j]);
        }
    }
    m = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(find(i) == i){
            g[i] = ++m;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(find(i) != i){
            g[i] = g[find(i)];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        h[g[i]] = f[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        if(h[g[i]] != f[i]){
            printf("-1\n");
            return 0;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(g[h[i]] != i){
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n" , m);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , g[i] , " \n"[i == n]);
    }
    for(int i = 1 ; i <= m ; ++i){
        printf("%d%c" , h[i] , " \n"[i == m]);
    }
}