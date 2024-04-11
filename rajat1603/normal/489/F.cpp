#include "bits/stdc++.h"
using namespace std;
const int N = 505;
int n , m , mod;
char str[N];
int sum[N];
int dp[N][N];
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = a;
    res *= b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int nc2(int n){
    return n * (n - 1) / 2;
}
int solve(int row , int cnt0 , int cnt1){
    if(row > n){
        return 1;
    }
    if(dp[cnt0][cnt1] != -1){
        return dp[cnt0][cnt1];
    }
    int res = 0;
    if(cnt0 >= 2){
        res = add(res , mult(solve(row + 1 , cnt0 - 2 , cnt1 + 2) , nc2(cnt0)));
    }
    if(cnt1 >= 2){
        res = add(res , mult(solve(row + 1 , cnt0 , cnt1 - 2) , nc2(cnt1)));
    }
    if(cnt0 >= 1 && cnt1 >= 1){
        res = add(res , mult(solve(row + 1 , cnt0 - 1 , cnt1) , mult(cnt0 , cnt1)));
    }
    return dp[cnt0][cnt1] = res;
}
int main(){
    scanf("%d %d %d" , &n , &m , &mod);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%s" , str + 1);
        for(int j = 1 ; j <= n ; ++j){
            sum[j] += str[j] - '0';
        }
    }
    int cnt0 = 0;
    int cnt1 = 0;
    for(int i = 1 ; i <= n ; ++i){
        cnt0 += !sum[i];
        cnt1 += !(sum[i] - 1);
    }
    memset(dp , -1 , sizeof(dp));
    printf("%d\n" , solve(m + 1 , cnt0 , cnt1));
}