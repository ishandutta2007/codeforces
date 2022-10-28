#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int col[N];
int nxt[N];
int a[N] , b[N];
void dfs(int node){
    for(int i = 0 ; i < 2 ; ++i){
        if(col[nxt[node]] < 0){
            col[nxt[node]] = col[node] ^ 1;
            dfs(nxt[node]);
        }
        nxt[node] = node - 1 + 2 * (node & 1);
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , a + i  , b + i);
        nxt[a[i]] = b[i];
        nxt[b[i]] = a[i];
    }
    memset(col , -1 , sizeof(col));
    for(int i = 1 ; i <= n + n ; ++i){
        if(col[i] < 0){
            col[i] = 0;
            dfs(i);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d %d\n" , col[a[i]] + 1 , col[b[i]] + 1);
    }
}