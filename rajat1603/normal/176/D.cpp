#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int C = 26;
const int S = 1e6 + 6;
int n;
char inp[S];
int nxt1[S][C];
int cur;
int start[N];
int finish[N];
int m;
int arr[N];
pair < int , int > nxt2[N][C];
pair < int , int > dp[N][N];
char str[N];
int len;
int main(){
    scanf("%d" , &n);
    cur = 0;
    memset(nxt1 , -1 , sizeof(nxt1));
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , inp);
        len = strlen(inp);
        start[i] = cur + 1;
        finish[i] = cur + len;
        for(int i = len ; i >= 1 ; --i){
            for(int j = 0 ; j < C ; ++j){
                nxt1[cur + i][j] = nxt1[cur + i + 1][j];
            }
            nxt1[cur + i][inp[i - 1] - 'a'] = cur + i;
        }
        cur += len;
    }
    scanf("%d" , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 0 ; i < C ; ++i){
        nxt2[m + 1][i] = make_pair(m , cur + 1);
    }
    for(int i = m ; i >= 1 ; --i){
        for(int j = 0 ; j < C ; ++j){
            nxt2[i][j] = nxt2[i + 1][j];
            if(nxt1[start[arr[i]]][j] != -1){
                nxt2[i][j] = make_pair(i , nxt1[start[arr[i]]][j]);
            }
        }
    }
    for(int i = 0 ; i < C ; ++i){
        nxt2[0][i] = nxt2[1][i];
    }
    scanf("%s" , str + 1);
    len = strlen(str + 1);
    dp[0][0] = make_pair(0 , 0);
    for(int i = 1 ; i <= len ; ++i){
        dp[0][i] = make_pair(m , cur + 1);
    }
    for(int i = 1 ; i <= len ; ++i){
        int c = str[i] - 'a';
        dp[i][0] = make_pair(0 , 0);
        for(int j = 1 ; j <= i ; ++j){
            dp[i][j] = dp[i - 1][j];
            auto idx = dp[i - 1][j - 1];
            auto idx2 = nxt2[idx.first + 1][c];
            if(nxt1[idx.second + 1][c] != -1 && idx.second + 1 <= finish[arr[idx.first]]){
                idx2 = make_pair(idx.first , nxt1[idx.second + 1][c]);
            }
            dp[i][j] = min(dp[i][j] , idx2);
        }
        for(int j = i + 1 ; j <= len ; ++j){
            dp[i][j] = make_pair(m , cur + 1);
        }
    }
    for(int i = len ; i >= 0 ; --i){
        if(dp[len][i].second <= cur){
            printf("%d\n" , i);
            break;
        }
    }
}