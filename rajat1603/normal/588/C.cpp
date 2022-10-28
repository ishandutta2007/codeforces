#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
int n;
int arr[N];
int ans = 0;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        int temp;
        scanf("%d" , &temp);
        ++arr[temp];
    }
    for(int i = 0 ; i < N ; ++i){
        if(arr[i]){
            arr[i + 1] += (arr[i] >> 1);
            arr[i] &= 1;
            ans += arr[i];
        }
    }
    printf("%d\n" , ans);
}