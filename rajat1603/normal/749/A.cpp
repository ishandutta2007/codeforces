#include "bits/stdc++.h"
using namespace std;
int n;
int main(){
    cin >> n;
    if(n & 1){
        n >>= 1;
        printf("%d\n" , n);
        for(int i = 0 ; i < n ; ++i){
            if(i){
                printf("2 ");
            }
            else{
                printf("3 ");
            }
        }
    }
    else{
        n >>= 1;
        printf("%d\n" , n);
        for(int i = 0 ; i < n ; ++i){
            printf("2 ");
        }
    }
    printf("\n");
}