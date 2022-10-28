#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int sum;
long long mx;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        sum += arr[i];
    }
    mx = sum;
    for(int i = n - 1 ; i >= 2 ; --i){
        sum -= arr[i + 1];
        mx = max(mx , sum - mx);
    }
    printf("%lld\n" , mx);
}