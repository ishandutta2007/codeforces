#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int mn = 1e9 + 9;
int pre[N];
int suf[N];
long long ans;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
        mn = min(mn , arr[i]);
    }
    pre[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        pre[i] = pre[i - 1];
        if(arr[i] == mn && pre[i] == 0){
            pre[i] = i;
        }
    }
    suf[n + 1] = n + 1;
    for(int i = n ; i >= 1 ; --i){
        suf[i] = suf[i + 1];
        if(arr[i] == mn){
            suf[i] = i;
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        long long temp = mn;
        temp *= n;
        if(arr[i] != mn){
            if(suf[i] != n + 1){
                temp += suf[i] - i;
            }
            else{
                temp += n - i + pre[i];
            }
        }
        ans = max(ans , temp);
    }
    cout << ans;
}