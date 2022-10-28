#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int M = 3e3 + 3;
int n , m;
pair < pair < int , int > , pair < int , int > > edges[M];
int parent[N];
int ans = 0;
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
inline void join(int a , int b){
    parent[find(b)] = find(a);
}
inline void solve(int r){
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    for(int i = 1 ; i <= m ; ++i){
        if(edges[i].first.second >= r){
            join(edges[i].second.first , edges[i].second.second);
            if(find(1) == find(n)){
                ans = max(ans , r - edges[i].first.first + 1);
                break;
            }
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %d %d" , &edges[i].second.first , &edges[i].second.second , &edges[i].first.first , &edges[i].first.second);
    }
    sort(edges + 1 , edges + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        solve(edges[i].first.second);
    }
    if(ans){
        printf("%d\n" , ans);
    }
    else{
        printf("Nice work, Dima!");
    }
}