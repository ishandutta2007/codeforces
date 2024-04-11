#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n , m;
int a , b;
vector < int > v[N];
int perm[N];
int comp[N];
vector < int > g[N];
int parent[N];
int col[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        v[i] = {i};
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i = 1 ; i <= n ; ++i){
        sort(v[i].begin() , v[i].end());
        perm[i] = i;
    }
    sort(perm + 1 , perm + 1 + n , [](int a , int b){
        return v[a] < v[b];
    });
    for(int i = 1 ; i <= n ; ++i){
        comp[perm[i]] = comp[perm[i - 1]] + (v[perm[i]] != v[perm[i - 1]]);
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j : v[i]){
            if(comp[i] != comp[j]){
                g[comp[i]].push_back(comp[j]);
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        sort(g[i].begin() , g[i].end());
        g[i].resize(unique(g[i].begin() , g[i].end()) - g[i].begin());
        if(g[i].size() > 2){
            printf("NO\n");
            return 0;
        }
        parent[i] = i;
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j : g[i]){
            if(i < j){
                continue;
            }
            if(find(i) == find(j)){
                printf("NO\n");
                return 0;
            }
            parent[find(i)] = find(j);
        }
    }
    printf("YES\n");
    for(int i = 1 ; i <= n ; ++i){
        if(g[i].size() == 1){
            int cur = 0;
            int last = -1;
            do{
                col[i] = ++cur;
                int nxt;
                for(int x : g[i]){
                    if(x != last){
                        nxt = x;
                    }
                }
                last = i;
                i = nxt;
            }
            while(g[i].size() > 1);
            col[i] = ++cur;
            break;
        }
    }
    if(v[perm[1]] == v[perm[n]]){
        col[comp[1]] = 1;
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , col[comp[i]] , " \n"[i == n]);
    }
}