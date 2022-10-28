#include "bits/stdc++.h"
using namespace std;
const int N = 1005;
char adj[N][N];
int k;
int cur = 2;
void addedge(int a , int b){
    adj[a][b] = 'Y';
    adj[b][a] = 'Y';
}
void make(int val){
    if(!val){
        addedge(1 , ++cur);
        addedge(cur , 4);
    }
    addedge(1 , ++cur);
    addedge(1 , ++cur);
    for(int i = 2 ; i <= val ; ++i){
        addedge(cur - 1 , cur + 1);
        addedge(cur - 1 , cur + 2);
        addedge(cur , cur + 1);
        addedge(cur , cur + 2);
        cur += 2;
    }
    addedge(cur - 1 , val + 3);
    addedge(cur , val + 3);
}
int main(){
    memset(adj , 'N' , sizeof(adj));
    cin >> k;
    addedge(1 , ++cur);
    for(int i = 0 ; i < 29 ; ++i){
        addedge(cur , cur + 1);
        ++cur;
    }
    addedge(cur , 2);
    --k;
    for(int i = 29 ; i >= 0 ; --i){
        if(k & (1 << i)){
            make(i);
        }
    }
    printf("%d\n" , cur);
    for(int i = 1 ; i <= cur ; ++i){
        for(int j = 1 ; j <= cur ; ++j){
            printf("%c" , adj[i][j]);
        }
        printf("\n");
    }
}