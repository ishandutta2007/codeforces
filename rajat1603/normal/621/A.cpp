#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
long long sum = 0;
long long ans = 0;
int main(){
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        sum += arr[i];
    }
    if(sum & 1){
        for(int i = 1 ; i <= n ; ++i){
            if(arr[i] & 1){
                ans = max(ans , sum - arr[i]);
            }
        }
    }
    else{
        ans = sum;
    }
    cout << ans;
}