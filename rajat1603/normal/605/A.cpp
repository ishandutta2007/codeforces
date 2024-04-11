#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int inp;
int dp[N];
int main(){
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp);
        dp[inp] = dp[inp - 1] + 1;
    }
    printf("%d\n" , n - (*max_element(dp + 1 , dp + 1 + n)));
}