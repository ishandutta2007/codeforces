#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int a , b;
vector < int > v[N];
int col[N];
void dfs(int node , int parent , int par){
    int cur = 0;
    for(int next : v[node]){
        if(next != parent){
            ++cur;
            if(cur == par){
                ++cur;
            }
            if(cur == col[node]){
                ++cur;
            }
            if(cur == par){
                ++cur;
            }
            if(cur == col[node]){
                ++cur;
            }
            col[next] = cur;
            dfs(next , node , col[node]);
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    int root = 1;
    for(int i = 2 ; i <= n ; ++i){
        if(v[i].size() > v[root].size()){
            root = i;
        }
    }
    col[root] = 1;
    dfs(root , 0 , 0);
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        ans = max(ans , col[i]);
    }
    printf("%d\n" , ans);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , col[i] , " \n"[i == n]);
    }
}