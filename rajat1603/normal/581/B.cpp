#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int suf[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
    }
    suf[n + 1] = -1;
    for(int i = n ; i >= 1 ; --i){
        suf[i] = max(suf[i + 1] , arr[i]);
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d " , max(0 , suf[i + 1] + 1 - arr[i]));
    }
}