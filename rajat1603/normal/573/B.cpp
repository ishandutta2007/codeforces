#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int arr[N];
int res[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
    }
    res[1] = 0;
    res[n] = 0;
    for(int i = 2 ; i < n ; ++i){
        res[i] = min(res[i - 1] + 1 , arr[i] - 1);
    }
    for(int i = n - 1 ; i >= 2 ; --i){
        res[i] = min(res[i] , res[i + 1] + 1);
    }
    printf("%d\n" , *max_element(res + 1 , res + 1 + n) + 1);
}