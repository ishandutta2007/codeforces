#include "bits/stdc++.h"
using namespace std;
const int N = 205;
int n;
string str;
int cnt1 = 0;
int cnt2 = 0;
int cnt3 = 0;
int dp[N][N][N];
int solve(int a , int b , int c){
    if(a < 0 || b < 0 || c < 0){
        return 0;
    }
    if(a + b + c == 1){
        if(a){
            return 1;
        }
        if(b){
            return 2;
        }
        if(c){
            return 4;
        }
    }
    if(dp[a][b][c] != -1){
        return dp[a][b][c];
    }
    int res = solve(a - 1 , b - 1 , c + 1) | solve(a - 1 , b + 1 , c - 1) | solve(a + 1 , b - 1 , c - 1);
    if(a > 1){
        res |= solve(a - 1 , b , c);
    }
    if(b > 1){
        res |= solve(a , b - 1 , c);
    }
    if(c > 1){
        res |= solve(a , b , c - 1);
    }
    return dp[a][b][c] = res;
}
int main(){
    cin >> n;
    memset(dp , -1 , sizeof(dp));
    cin >> str;
    for(char c : str){
        if(c == 'R'){
            ++cnt1;
        }
        else if(c == 'B'){
            ++cnt2;
        }
        else{
            ++cnt3;
        }
    }
    int ans = solve(cnt1 , cnt2 , cnt3);
    if(ans & 2){
        printf("B");
    }
    if(ans & 4){
        printf("G");
    }
    if(ans & 1){
        printf("R");
    }
}