#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
int arr[N];
long long dp[N];
bool k;
int n;
int last = 1;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    k = arr[2] >= arr[1];
    for(int i = 2 ; i <= n ; ++i){
        if(k && arr[i] <= arr[i - 1] || !k && arr[i] >= arr[i - 1]){
            last = i - 1;
            k ^= 1;
        }
        dp[i] = max(fabs(arr[i] - arr[last]) + dp[last - 1] , fabs(arr[i] - arr[last + 1]) + dp[last]);
    }
    printf("%lld\n" , dp[n]);
}