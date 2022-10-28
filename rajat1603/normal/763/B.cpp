#include "bits/stdc++.h"
using namespace std;
int n;
int a , b , c , d;
int main(){
    printf("YES\n");
    scanf("%d" , &n);
    while(n--){
        scanf("%d %d %d %d" , &a , &b , &c , &d);
        printf("%d\n" , (c & 1) + 2 * (b & 1) + 1);
    }
}