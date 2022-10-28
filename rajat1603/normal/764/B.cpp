#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n;
int arr[N];
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n - i + 1 ; ++i){
        if(i & 1){
            swap(arr[i] , arr[n - i + 1]);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , arr[i] , " \n"[i == n]);
    }
}