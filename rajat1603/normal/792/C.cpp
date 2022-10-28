#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
char str[N];
int n;
int dp[N][3];
int solve(int pos , int sum){
    if(pos > n){
        return sum * N;
    }
    if(dp[pos][sum] != -1){
        return dp[pos][sum];
    }
    int res = N;
    res = min(res , 1 + solve(pos + 1 , sum));
    res = min(res , solve(pos + 1 , (sum + str[pos] - '0') % 3));
    return dp[pos][sum] = res;
}
void go(int pos , int sum){
    if(pos > n){
        return;
    }
    if(1 + solve(pos + 1 , sum) == solve(pos , sum)){
        go(pos + 1 , sum);
    }
    else{
        printf("%c" , str[pos]);
        go(pos + 1 , (sum + str[pos] - '0') % 3);
    }
}
int main(){
    memset(dp , -1 , sizeof(dp));
    scanf("%s" , str + 1);
    n = strlen(str + 1);
    if(n == 1){
        if(str[1] == '0' || str[1] == '3' || str[1] == '6' || str[1] == '9'){
            cout << str[1] << endl;
        }
        else{
            cout << -1 << endl;
        }
        return 0;
    }
    int ans = N;
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] != '0'){
            ans = min(ans , i - 1 + solve(i + 1 , (str[i] - '0') % 3));
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] == '0'){
            if(ans >= n){
                cout << "0\n";
                return 0;
            }
        }
    }
    if(ans >= n){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] != '0'){
            if(i - 1 + solve(i + 1 , (str[i] - '0') % 3) == ans){
                printf("%c" , str[i]);
                go(i + 1 , (str[i] - '0') % 3);
                return 0;
            }
        }
    }
}