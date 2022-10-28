#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 5;
bool pal[N][N] = {0};
int dp[N][N] = {0};
string str;
int q;
int n;
int l , r;
int main(){
    cin >> str;
    str = " " + str;
    n = str.size() - 1;
    for(int i = 1 ; i <= n ; ++i){
        pal[i][i] = 1;
        dp[i][i] = 1;
    }
    for(int i = 1 ; i < n ; ++i){
        pal[i][i + 1] = (str[i] == str[i + 1]);
        dp[i][i + 1] = dp[i][i] + pal[i][i + 1] + dp[i + 1][i + 1];
    }
    for(int i = 3 ; i <= n ; ++i){
        for(int j = 1 ; j + i - 1 <= n ; ++j){
            pal[j][i + j - 1] = (pal[j + 1][i + j - 2] & (str[j] == str[j + i - 1]));
            dp[j][j + i - 1] = dp[j][j + i - 2] + dp[j + 1][j + i - 1] - dp[j + 1][j + i - 2] + pal[j][j + i - 1];
        }
    }
    cin >> q;
    while(q--){
        scanf("%d %d" , &l , &r);
        printf("%d\n" , dp[l][r]);
    }
}