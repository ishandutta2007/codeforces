#include "bits/stdc++.h"
using namespace std;
const int N = 33;
const int K = 205;
int n , k;
int arr[N];
double ans;
double dp[N][N][K];
double solve(int i , int j , int k){
    if(!k){
        return i > j;
    }
    if(i > j){
        return 1 - solve(j , i , k);
    }
    if(dp[i][j][k] > -1){
        return dp[i][j][k];
    }
    double res = 0;
    for(int l = 1 ; l <= n ; ++l){
        for(int r = l ; r <= n ; ++r){
            if(r < i){
                res += solve(i , j , k - 1);
            }
            else if(l > j){
                res += solve(i , j , k - 1);
            }
            else if(l > i && r < j){
                res += solve(i , j , k - 1);
            }
            else if(l <= i && r < j){
                res += solve(l + r - i , j , k - 1);
            }
            else if(l > i && r >= j){
                res += solve(i , l + r - j , k - 1);
            }
            else{
                res += solve(l + r - i , l + r - j , k - 1);
            }
        }
    }
    res *= 2;
    res /= n;
    res /= n + 1;
    return dp[i][j][k] = res;
}
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            for(int l = 1 ; l <= k ; ++l){
                dp[i][j][l] = -5;
            }
        }
    }
    ans = 0;
    for(int i = 1 ; i < n ; ++i){
        for(int j = i + 1 ; j <= n ; ++j){
            if(arr[i] < arr[j]){
                ans += solve(i , j , k);
            }
            else{
                ans += 1 - solve(i , j , k);
            }
        }
    }
    printf("%.9lf\n" , ans);
}