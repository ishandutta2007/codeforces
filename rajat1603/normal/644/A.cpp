#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n , a , b;
int arr[N][N];
int cur = 1;
int tot = 0;
int main(){
    scanf("%d %d %d" , &n , &a , &b);
    memset(arr , 0 , sizeof(arr));
    for(int i = 1 ; i <= a ; ++i){
        for(int j = 2 - (i & 1) ; j <= b ; j += 2){
            if(cur > n){
                break;
            }
            else{
                arr[i][j] = cur;
                cur += 2;
                ++tot;
            }
        }
    }
    cur = 2;
    for(int i = 1 ; i <= a ; ++i){
        for(int j = 1 + (i & 1) ; j <= b ; j += 2){
            if(cur > n){
                break;
            }
            else{
                ++tot;
                arr[i][j] = cur;
                cur += 2;
            }
        }
    }
    if(tot < n){
        printf("-1\n");
    }
    else{
        for(int i = 1 ; i <= a ; ++i){
            for(int j = 1 ; j <= b ; ++j){
                printf("%d " , arr[i][j]);
            }
            printf("\n");
        }
    }
}