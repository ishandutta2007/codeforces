#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 9;
int n , m;
int a , b;
int par[N];
int ans;
int find(int node){
    if(par[node] != node){
        par[node] = find(par[node]);
    }
    return par[node];
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        par[i] = i;
    }
    ans = 1;
    while(m--){
        scanf("%d %d" , &a , &b);
        int x = find(a);
        int y = find(b);
        if(x == y){
            ans += ans;
            if(ans >= mod){
                ans -= mod;
            }
        }
        else{
            par[y] = x;
        }
        printf("%d\n" , ans - 1);
    }
}