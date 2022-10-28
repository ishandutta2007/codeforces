#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int suf[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    suf[n + 1] = INT_MAX;
    for(int i = n ; i >= 1 ; --i){
        suf[i] = min(suf[i + 1] , arr[i]);
    }
    int mn = -1;
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        mn = max(mn , arr[i]);
        if(mn <= suf[i + 1]){
            ++ans;
            mn = -1;
        }
    }
    printf("%d\n" , ans);
}