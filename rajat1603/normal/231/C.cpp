#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
long long sum[N];
int ans = 0 , ans2 = 0;
int l , r , mid;
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    sort(arr + 1 , arr + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        sum[i] = sum[i - 1] + arr[i];
        l = 1 , r = i;
        while(l < r){
            mid = l + r >> 1;
            (1LL * arr[i] * (i - mid + 1) - sum[i] + sum[mid - 1] <= k) ? r = mid : l = mid + 1;
        }
        if(i - l + 1 > ans){
            ans = i - l + 1;
            ans2 = arr[i];
        }
    }
    cout << ans << " " << ans2;
}