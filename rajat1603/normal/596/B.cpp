#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;;
int n;
int arr[N];
long long mark[N];
long long ans;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
    }
    memset(mark , 0 , sizeof(mark));
    for(int i = 1 ; i <= n ; ++i){
        mark[i] += mark[i - 1];
        ans += abs(arr[i] - mark[i]);
        mark[i] += arr[i] - mark[i];
    }
    cout << ans;
}