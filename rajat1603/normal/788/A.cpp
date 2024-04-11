#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
long long arr[N];
long long val[N];
long long ans;
int main(){
    scanf("%d" , &n);
    ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , arr + i);
    }
    for(int i = 1 ; i < n ; ++i){
        val[i] = max(arr[i + 1] - arr[i] , arr[i] - arr[i + 1]);
    }
    --n;
    long long sum1 = 0;
    long long sum2 = 0;
    long long mx1 , mx2;
    mx1 = 0;
    mx2 = 0;
    long long mx3 , mx4;
    mx3 = 0;
    mx4 = 0;
    for(int i = 1 ; i <= n ; ++i){
        ans = max(ans , val[i]);
        if(i & 1){
            sum1 += val[i];
            sum2 -= val[i];
            ans = max(ans , sum1 - mx2);
            ans = max(ans , sum2 - mx1);
        }
        else{
            sum1 -= val[i];
            sum2 += val[i];
            ans = max(ans , sum2 - mx1);
            ans = max(ans , sum1 - mx2);
        }
        if(i & 1){
            mx1 = min(mx1 , sum2);
        }
        else{
            mx2 = min(mx2 , sum1);
        }
    }
    printf("%lld\n" , ans);
}