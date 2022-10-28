#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int dp[N];
long long ans;
map < int , int > mp;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    ans = 0;
    mp.clear();
    for(int i = 1 ; i <= n ; ++i){
        for(long long num = 1 ; num <= 2e9 ; num += num){
            ans += mp[num - arr[i]];
        }
        ++mp[arr[i]];
    }
    cout << ans;
}