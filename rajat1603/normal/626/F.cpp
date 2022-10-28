#include "bits/stdc++.h"
using namespace std;
const int N = 2e2 + 2;
const int K = 1e3 + 3;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int mult(int a , int b){
    long long res = 1LL * a * b;
    if(res >= mod){
        return res % mod;
    }
    return res;
}
int n , k;
int arr[N];
int dp[2][N + 5 >> 1][K];
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    arr[0] = arr[1];
    for(int sum = 0 ; sum <= k ; ++sum){
        dp[(n + 1) & 1][0][sum] = 1;
    }
    for(int pos = n ; pos >= 1 ; --pos){
        for(int open = n >> 1 ; open >= 0 ; --open){
            int tmp = open * (arr[pos] - arr[pos - 1]);
            for(int sum = 0 ; sum + tmp <= k ; ++sum){
                int res = 0;
                res = add(res , dp[(pos + 1) & 1][open][sum + tmp]);
                res = add(res , dp[(pos + 1) & 1][open + 1][sum + tmp]);
                res = add(res , mult(open , dp[(pos + 1) & 1][open - 1][sum + tmp]));
                res = add(res , mult(open , dp[(pos + 1) & 1][open][sum + tmp]));
                dp[pos & 1][open][sum] = res;
            }
            for(int sum = k - tmp + 1 ; sum <= k ; ++sum){
                dp[pos & 1][open][sum] = 0;
            }
        }
    }
    printf("%d\n" , dp[1][0][0]);
}