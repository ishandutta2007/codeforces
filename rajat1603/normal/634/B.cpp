#include "bits/stdc++.h"
using namespace std;
long long a , b;
long long dp[60][2][2][2];
long long solve(int pos , bool carry , bool x , bool y){
    if(pos > 55){
        return x && y && (!carry);
    }
    if(dp[pos][carry][x][y] != -1){
        return dp[pos][carry][x][y];
    }
    long long res = 0;
    for(int i = 0 ; i < 2 ; ++i){
        for(int j = 0 ; j < 2 ; ++j){
            int tmp = i ^ j;
            bool bit = ((b >> pos) & 1);
            if(tmp != bit){
                continue;
            }
            tmp = (i + j + carry) % 2;
            int xtra = (i + j + carry) / 2;
            bit = ((a >> pos) & 1);
            if(tmp != bit){
                continue;
            }
            res += solve(pos + 1 , xtra , x | (i > 0) , y | (j > 0));
        }
    }
    return dp[pos][carry][x][y] = res;
}
int main(){
    memset(dp , -1 , sizeof(dp));
    cin >> a >> b;
    cout << solve(0 , 0 , 0 , 0);
}