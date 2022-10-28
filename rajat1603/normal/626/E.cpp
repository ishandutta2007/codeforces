#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
long long sum[N];
int ansidx;
int anslen;
double ans = -1.0;
double solve(int idx , int len){
    double ret = sum[idx] - sum[idx - len - 1];
    ret += sum[n] - sum[n - len];
    ret /= len + len + 1;
    ret -= arr[idx];
    if(ret > ans){
        ans = ret;
        ansidx = idx;
        anslen = len;
    }
    return ret;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    sort(arr + 1 , arr + 1 + n);
    sum[0] = 0LL;
    for(int i = 1 ; i <= n ; ++i){
        sum[i] = sum[i - 1] + arr[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        int l = 0;
        int r = min(i - 1 , n - i);
        while(l + 3 < r){
            int mid1 = (l + l + r) / 3;
            int mid2 = (l + r + r) / 3;
            if(solve(i , mid1) < solve(i , mid2)){
                l = mid1;
            }
            else{
                r = mid2;
            }
        }
        while(l <= r){
            solve(i , l++);
        }
    }
    printf("%d\n" , anslen + anslen + 1);
    for(int i = ansidx ; i >= ansidx - anslen ; --i){
        printf("%d " , arr[i]);
    }
    for(int i = n ; i > n - anslen ; --i){
        printf("%d " , arr[i]);
    }
}