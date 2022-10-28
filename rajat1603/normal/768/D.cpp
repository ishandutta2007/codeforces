#include "bits/stdc++.h"
using namespace std;
const int K = 1e3 + 3;
const int D = 9003;
int k , q;
int p;
double val[D];
double dp[2][K];
int main(){
    scanf("%d %d" , &k , &q);
    dp[0][k] = 1;
    for(int i = 0 ; i < k ; ++i){
        dp[0][i] = 0;
    }
    val[0] = 0;
    for(int days = 1 ; days < D ; ++days){
        dp[days & 1][k] = 1;
        for(int cur = 0 ; cur < k ; ++cur){
            double res = 0;
            res += dp[!(days & 1)][cur] * cur;
            res += dp[!(days & 1)][cur + 1] * (k - cur);
            res /= k;
            dp[days & 1][cur] = res;
        }
        val[days] = dp[days & 1][0];
    }
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d" , &p);
        int ans;
        for(int j = 0 ; j < D ; ++j){
            if(val[j] * 2000 >= p){
                ans = j;
                break;
            }
        }
        printf("%d\n" , ans);
    }
}