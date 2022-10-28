#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n;
int inp;
int parent[N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
int ans;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
    }
    ans = n;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp);
        if(find(inp) != find(i)){
            parent[find(inp)] = find(i);
            --ans;
        }
    }
    printf("%d\n" , ans);
}