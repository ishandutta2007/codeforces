#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int last;
char str[N];
int n;
int dp[N][2];
int main(){
    scanf("%s" , str);
    n = strlen(str);
    for(int i = n - 1 ; i >= 0 ; --i){
        if(str[i] == '1'){
            last = i;
            break;
        }
    }
    dp[last][0] = 1;
    dp[last][1] = 1;
    for(int i = last - 1 ; i >= 0 ; --i){
        if(str[i] == '1'){
            dp[i][0] = min(dp[i + 1][0] , dp[i + 1][1]) + 1;
            dp[i][1] = dp[i + 1][1];
        }
        else{
            dp[i][0] = dp[i + 1][0];
            dp[i][1] = min(dp[i + 1][1] , dp[i + 1][0]) + 1;
        }
    }
    printf("%d\n" , dp[0][0]);
}