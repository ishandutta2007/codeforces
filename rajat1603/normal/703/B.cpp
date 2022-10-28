#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
int arr[N];
long long ans;
long long sum;
int nodes[N];
bool mark[N];
int main(){
    scanf("%d %d" , &n , &k);
    sum = 0;
    ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        sum += arr[i];
    }
    for(int i = 1 ; i <= k ; ++i){
        scanf("%d" , nodes + i);
    }
    for(int i = 1 ; i < n ; ++i){
        ans += 1LL * arr[i] * arr[i + 1];
    }
    ans += 1LL * arr[n] * arr[1];
    for(int i = 1 ; i <= k ; ++i){
        ans += 1LL * arr[nodes[i]] * (sum - arr[nodes[i]]);     
    }
    long long sum2 = 0;
    for(int i = 1 ; i <= k ; ++i){
        ans -= 1LL * sum2 * arr[nodes[i]];
        sum2 += arr[nodes[i]];
    }
    for(int i = 1 ; i <= k ; ++i){
        if(nodes[i] == n){
            ans -= 1LL * arr[n] * arr[1];
        }
        else{
            ans -= 1LL * arr[nodes[i]] * arr[nodes[i] + 1];
        }
        if(nodes[i] == 1){
            ans -= 1LL * arr[1] * arr[n];
        }
        else{
            ans -= 1LL * arr[nodes[i]] * arr[nodes[i] - 1];
        }
    }
    for(int i = 1 ; i <= k ; ++i){
        mark[nodes[i]] = 1;
    }
    for(int i = 1 ; i < n ; ++i){
        if(mark[i] && mark[i + 1]){
            ans += 1LL * arr[i] * arr[i + 1];
        }
    }
    if(mark[n] && mark[1]){
        ans += 1LL * arr[1] * arr[n];
    }
    cout << ans;
}