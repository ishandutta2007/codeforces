#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
long long dp[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    dp[0] = 0;
    int ninety = 90;
    int wtf = 1440;
    int ptr1 = 1;
    int ptr2 = 1;
    for(int i = 1 ; i <= n ; ++i){
        dp[i] = dp[i - 1] + 20;
        while(arr[i] - arr[ptr1] >= ninety){
            ++ptr1;
        }
        while(arr[i] - arr[ptr2] >= wtf){
            ++ptr2;
        }
        dp[i] = min(dp[i] , dp[ptr1 - 1] + 50);
        dp[i] = min(dp[i] , dp[ptr2 - 1] + 120);
        printf("%lld\n" , dp[i] - dp[i - 1]);
    }
}