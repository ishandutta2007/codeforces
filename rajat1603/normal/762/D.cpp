#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const long long inf = 1e15 + 15;
int n;
long long arr[4][N];
long long dp[4][N];
bool calc[4][N];
long long solve(int row , int col){
    if(calc[row][col]){
        return dp[row][col];
    }
    long long res = -inf;
    if(col == n){
        if(row == 3){
            res = arr[row][col];
        }
        else{
            res = arr[row][col] + solve(row + 1 , col);
        }
    }
    else{
        res = max(res , solve(row , col + 1));
        if(row + 1 <= 3){
            res = max(res , solve(row + 1 , col + 1) + arr[row + 1][col]);
        }
        if(row + 2 <= 3){
            res = max(res , solve(row + 2 , col + 1) + arr[row + 1][col] + arr[row + 2][col]);
        }
        if(row - 1 >= 1){
            res = max(res , solve(row - 1 , col + 1) + arr[row - 1][col]);
        }
        if(row - 2 >= 1){
            res = max(res , solve(row - 2 , col + 1) + arr[row - 1][col] + arr[row - 2][col]);
        }
        if(row == 3){
            if(col < n - 1){
                res = max(res , arr[row][col + 1] + arr[row - 1][col + 1] + arr[row - 1][col] + arr[row - 2][col] + arr[row - 2][col + 1] + solve(row - 2 , col + 2));
            }
        }
        if(row == 1){
            if(col == n - 1){
                res = max(res , arr[row][col + 1] + arr[row + 1][col + 1] + arr[row + 1][col] + arr[row + 2][col] + arr[row + 2][col + 1]);
            }
            else{
                res = max(res , arr[row][col + 1] + arr[row + 1][col + 1] + arr[row + 1][col] + arr[row + 2][col] + arr[row + 2][col + 1] + solve(row + 2 , col + 2));
            }
        }
        res += arr[row][col];
    }
    calc[row][col] = 1;
    return dp[row][col] = res;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= 3 ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            scanf("%lld" , &arr[i][j]);
        }
    }
    printf("%lld\n" , solve(1 , 1));
}