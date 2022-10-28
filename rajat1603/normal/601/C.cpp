#include "bits/stdc++.h"
using namespace std;
const int N = 101;
const int M = 1001;
const int SUM = N * M;
int n , m;
int sum = 0;
int arr[N];
double dp1[N][SUM];
double dp2[N][SUM];
double solve(int pos , int sum);
double g(int pos , int sum){
    if(sum < 0){
        return 0;
    }
    if(dp1[pos][sum] > -1.0){
        return dp1[pos][sum];
    }
    if(!sum){
        return dp1[pos][sum] = solve(pos , 0);
    }
    return dp1[pos][sum] = g(pos , sum - 1) + solve(pos , sum);
}
double solve(int pos , int sum){
    if(!pos){
        return !sum;
    }
    if(dp2[pos][sum] > -1.0){
        return dp2[pos][sum];
    }
    double res = g(pos - 1 , sum - 1) - g(pos - 1 , sum - m - 1) - solve(pos - 1 , sum - arr[pos]);
    res /= m - 1;
    return dp2[pos][sum] = res;
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &arr[i]);
        sum += arr[i];
    }
    if(m == 1){
        puts("1");
        return 0;
    }
    for(int i = 0 ; i <= n ; ++i){
        for(int j = 0 ; j <= sum ; ++j){
            dp1[i][j] = -2.0;
            dp2[i][j] = -2.0;
        }
    }
    printf("%.9lf" , 1 + (g(n , sum - 1) * (m - 1.0)));
}