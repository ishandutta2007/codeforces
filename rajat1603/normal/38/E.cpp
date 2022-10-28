#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
const long long inf = 1e17 + 17;
int n;
pair < int , int > arr[N];
long long dp[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
    }
    sort(arr + 1 , arr + 1 + n);
    for(int i = n ; i >= 1 ; --i){
        long long sum = 0;
        dp[i] = inf;
        for(int j = i ; j <= n ; ++j){
            sum += arr[j].first - arr[i].first;
            dp[i] = min(dp[i] , dp[j + 1] + sum + arr[i].second);
        }
    }
    printf("%lld\n" , dp[1]);
}