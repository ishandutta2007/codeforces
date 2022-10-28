#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int mn , mx;
int main(){
    scanf("%d" , &n);
    mn = 1e9 + 9;
    mx = -1e9 - 9;
    int ans = 0; 
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        mn = min(mn , arr[i]);
        mx = max(mx , arr[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        if(arr[i] > mn && arr[i] < mx){
            ++ans;
        }
    }
    printf("%d\n" , ans);
}