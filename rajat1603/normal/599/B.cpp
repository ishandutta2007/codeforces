#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , m;
int f[N];
int b[N];
int cnt[N];
int idx[N];
int main(){
    scanf("%d %d" , &n , &m);
    memset(cnt , 0 , sizeof(cnt));
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , f + i);
        ++cnt[f[i]];
        idx[f[i]] = i;
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , b + i);
    }
    for(int i = 1 ; i <= m ; ++i){
        if(!cnt[b[i]]){
            puts("Impossible");
            return 0;
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        if(cnt[b[i]] > 1){
            puts("Ambiguity");
            return 0;
        }
    }
    puts("Possible");
    for(int i = 1 ; i <= m ; ++i){
        printf("%d " , idx[b[i]]);
    }
}