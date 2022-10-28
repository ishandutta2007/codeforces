#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int col[N];
int a[N] , b[N];
int parent[N];
int num[N];
int cur;
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void join(int a , int b){
    parent[find(a)] = find(b);
}
vector < int > v[N];
int who;
int dist;
void dfs(int node , int parent , int level){
    if(level > dist){
        dist = level;
        who = node;
    }
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node , level + 1);
        }
    }
}
int solve(){
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    for(int i = 1 ; i < n ; ++i){
        if(col[a[i]] == col[b[i]]){
            join(a[i] , b[i]);
        }
    }
    cur = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(find(i) == i){
            num[i] = ++cur;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        num[i] = num[find(i)];
    }
    for(int i = 1 ; i < n ; ++i){
        if(num[a[i]] != num[b[i]]){
            v[num[a[i]]].push_back(num[b[i]]);
            v[num[b[i]]].push_back(num[a[i]]);
        }
    }
    who = 1;
    dist = 1;
    dfs(1 , 0 , 1);
    dist = 1;
    dfs(who , 0 , 1);
    return dist >> 1;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , col + i);
    }
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , a + i , b + i);
    }
    printf("%d\n" , solve());
}