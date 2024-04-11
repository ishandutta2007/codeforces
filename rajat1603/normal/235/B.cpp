#include "bits/stdc++.h"
int n;
double arr , ans , dp;
int main(){
    scanf("%d" , &n);
    while(n--){
        scanf("%lf" , &arr);
        dp = (dp + 1) * arr;
        ans += 2 * dp - arr;
    }
    printf("%lf\n" , ans);
}