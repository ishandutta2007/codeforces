#include "bits/stdc++.h"
using namespace std;
const int N = 512;
const int mod = 1e9 + 7;
int n , m;
char arr[N][N] = {NULL};
int dp[2][N][N] = {0};
int dpp(int x1 , int y1 , int x2){
    if(x1 > n || x1 < 1 || y1 > m || y1 < 1 || x2 > n || x2 < 1 || (n + m - x1 - y1 + 2 - x2) > m || (n + m - x1 - y1 + 2 - x2) < 1){
        return 0;
    }
    return dp[x1 & 1][y1][x2];
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , arr[i] + 1);
    }
    for(int i = n + m ; i >= 2 ; --i){
        for(int x1 = n ; x1 >= 1 ; --x1){
            int y1 = i - x1;
            for(int x2 = n ; x2 >= 1 ; --x2){
                int y2 = n + m - x2 - i + 2;
                if(x1 > n || x1 < 1 || y1 > m || y1 < 1 || x2 > n || x2 < 1 || y2 < 1 || y2 > m){
                    continue;
                }
                else if(arr[x1][y1] != arr[x2][y2]){
                    dp[x1 & 1][y1][x2] = 0;
                }
                else if(abs(x2 - x1) + abs(y2 - y1) <= 1){
                    dp[x1 & 1][y1][x2] = 1;
                }
                else if(x2 < x1 || y2 < y1){
                    dp[x1 & 1][y1][x2] = 0;
                }
                else{
                    int res = 0;
                    res += dpp(x1 + 1 , y1 , x2 - 1);
                    res += dpp(x1 + 1 , y1 , x2);
                    if(res >= mod){
                        res -= mod;
                    }
                    res += dpp(x1 , y1 + 1 , x2 - 1);
                    if(res >= mod){
                        res -= mod;
                    }
                    res += dpp(x1 , y1 + 1 , x2);
                    if(res >= mod){
                        res -= mod;
                    }
                    dp[x1 & 1][y1][x2] = res;
                }
            }
        }
    }
    printf("%d\n" , dp[1][1][n]);
}