#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int MX = 1 << 22;
int n;
int arr[N];
int val[MX];
int main(){
    scanf("%d" , &n);
    memset(val , -1 , sizeof(val));
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        val[arr[i] ^ (MX - 1)] = arr[i];
    }
    for(int i = MX - 2 ; i >= 1 ; --i){
        for(int j = 0 ; j < 22 ; ++j){
            val[i] = max(val[i] , val[i | (1 << j)]);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , val[arr[i]] , " \n"[i == n]);
    }
}