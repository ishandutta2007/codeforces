#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n;
int arr[N + N];
int main(){
    scanf("%d" , &n);
    if(n & 1){
        for(int i = 1 ; i <= n ; i += 2){
            printf("%d " , i);
        }
        for(int i = n - 2 ; i >= 1 ; i -= 2){
            printf("%d " , i);
        }
        for(int i = 2 ; i <= n ; i += 2){
            printf("%d " , i);
        }
        for(int i = n - 1 ; i >= 2 ; i -= 2){
            printf("%d " , i);
        }
    }
    else{
        for(int i = 1 ; i <= n ; i += 2){
            printf("%d " , i);
        }
        for(int i = n - 1 ; i >= 1 ; i -= 2){
            printf("%d " , i);
        }
        for(int i = 2 ; i <= n ; i += 2){
            printf("%d " , i);
        }
        for(int i = n - 2 ; i >= 2 ; i -= 2){
            printf("%d " , i);
        }
    }
    printf("%d\n" , n);
}