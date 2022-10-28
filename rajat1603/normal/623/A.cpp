#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n , m;
int a[N * N];
int b[N * N];
int deg[N];
int ans[N];
int edge[N][N];
int myans[N][N];
int main(){
    memset(ans , -1 , sizeof(ans));
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , a + i , b + i);
        ++deg[a[i]];
        ++deg[b[i]];
        edge[a[i]][b[i]] = 1;
        edge[b[i]][a[i]] = 1;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(deg[i] == n - 1){
            ans[i] = 1;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(ans[i] == -1){
            ans[i] = 0;
            for(int j = 1 ; j <= n ; ++j){
                if(!edge[i][j]){
                    if(ans[j] == -1){
                        ans[j] = 2;
                    }
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(ans[i] != -1){
            for(int j = i + 1 ; j <= n ; ++j){
                if(ans[j] != -1){
                    if(abs(ans[i] - ans[j]) <= 1){
                        myans[i][j] = 1;
                        myans[j][i] = 1;
                    }
                }
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            if(edge[i][j] != myans[i][j]){
                printf("No\n");
                return 0;
            }
        }
    }
    printf("Yes\n");
    for(int i = 1 ; i <= n ; ++i){
        printf("%c" , 'a' + ans[i]);
    }
}