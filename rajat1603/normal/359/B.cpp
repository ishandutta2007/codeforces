#include "bits/stdc++.h"
using namespace std;
int n , k;
int a , b;
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        if(i <= k){
            printf("%d %d " , 2 * i - 1 , 2 * i);
        }
        else{
            printf("%d %d " , 2 * i , 2 * i - 1);
        }
    }
}