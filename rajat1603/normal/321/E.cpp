#include "bits/stdc++.h"
using namespace std;
const int N = 4e3 + 3;
const int K = 8e2 + 2;
int n , k;
int arr[N][N];
int dp[K][N];
int cost(int i , int j){
    return (arr[j][j] - arr[i - 1][j] - arr[j][i - 1] + arr[i - 1][i - 1]) >> 1;
}
void compute(int i , int l , int r , int ql , int qr){
    if(r < l){
        return;
    }
    int mid = l + r >> 1;
    int idx = -1;
    int val = 1e9;
    for(int j = ql ; j <= min(qr , mid) ; ++j){
        int tmp = dp[i - 1][j - 1] + cost(j , mid);
        if(tmp <= val){
            val = tmp;
            idx = j;
        }
    }
    dp[i][mid] = val;
    compute(i , l , mid - 1 , ql , idx);
    compute(i , mid + 1 , r , idx , qr);
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            char c = '#';
            while(!isdigit(c)){
                c = getchar();
            }
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + c - '0';
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        dp[1][i] = cost(1 , i);
    }
    for(int i = 2 ; i <= k ; ++i){
        compute(i , 1 , n , 1 , n);
    }
    printf("%d\n" , dp[k][n]);
}