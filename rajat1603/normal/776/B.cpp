#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int prime(int x){
    for(int i = 2 ; i * i <= x ; ++i){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}
int main(){
    scanf("%d" , &n);
    if(n == 1){
        printf("1\n1\n");
        return 0;
    }
    if(n == 2){
        printf("1\n1 1\n");
        return 0;
    }
    printf("2\n");
    for(int i = 1 ; i <= n ; ++i){
        printf("%d%c" , 2 - prime(i + 1) , " \n"[i == n]);
    }
}