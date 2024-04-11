#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
char s[N];
char t[N];
int n , m;
int dp[N][N];
int solve(int x , int y){
    if(x > n){
        return m - y + 1;
    }
    if(y > m){
        return n - x + 1;
    }
    if(dp[x][y] != -1){
        return dp[x][y];
    }
    int res = N * N;
    res = min(res , solve(x + 1 , y + 1) + (s[x] != t[y]));
    res = min(res , solve(x , y + 1) + 1);
    res = min(res , solve(x + 1 , y) + 1);
    return dp[x][y] = res;
}
void go(int x , int y){
    if(x > n){
        for(int i = y ; i <= m ; ++i){
            printf("INSERT %d %c\n" , i , t[i]);
        }
    }
    else if(y > m){
        for(int i = x ; i <= n ; ++i){
            printf("DELETE %d\n" , y);
        }
    }
    else{
        int res1 = solve(x + 1 , y + 1) + (s[x] != t[y]);
        int res2 = solve(x , y + 1) + 1;
        int res3 = solve(x + 1 , y) + 1;
        int res = min(res1 , min(res2 , res3));
        if(res1 == res){
            if(s[x] == t[y]){
                go(x + 1 , y + 1);
            }
            else{
                printf("REPLACE %d %c\n" , y , t[y]);
                go(x + 1 , y + 1);
            }
        }
        else if(res2 == res){
            printf("INSERT %d %c\n" , y , t[y]);
            go(x , y + 1);
        }
        else{
            printf("DELETE %d\n" , y);
            go(x + 1 , y);
        }
    }
}
int main(){
    scanf("%s" , s + 1);
    scanf("%s" , t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    memset(dp , -1 , sizeof(dp));
    printf("%d\n" , solve(1 , 1));
    go(1 , 1);
}