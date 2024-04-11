#include "bits/stdc++.h"
using namespace std;
const int N = 2e3 + 3;
const int mod = 1e9 + 7;
int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int m , d;
int n;
string a;
string b;
int dp[N][2][2][2][N];
int solve(int pos , bool alarge , bool bsmall , bool even , int num){
    if(pos >= n){
        return (!num);
    }
    if(dp[pos][alarge][bsmall][even][num] != -1){
        return dp[pos][alarge][bsmall][even][num];
    }
    int res = 0;
    for(int i = 0 ; i < 10 ; ++i){
        if(!alarge && i < a[pos] - '0'){
            continue;
        }
        if(!bsmall && i > b[pos] - '0'){
            continue;
        }
        if(even){
            if(i == d){
                res = add(res , solve(pos + 1 , alarge || (i > a[pos] - '0') , bsmall || (i < b[pos] - '0') , !even , (num * 10 + i) % m));
            }
        }
        else if(i != d){
            res = add(res , solve(pos + 1 , alarge || (i > a[pos] - '0') , bsmall || (i < b[pos] - '0') , !even , (num * 10 + i) % m));
        }
    }
    return dp[pos][alarge][bsmall][even][num] = res;
}
int main(){
    cin >> m >> d;
    cin >> a;
    cin >> b;
    n = a.size();
    int ans = 0;
    memset(dp , -1 , sizeof(dp));
    for(int i = 0 ; i < 10 ; ++i){
        if(i < a[0] - '0'){
            continue;
        }
        if(i > b[0] - '0'){
            continue;
        }
        if(i == d){
            continue;
        }
        ans = add(ans , solve(1 , i > a[0] - '0' , i < b[0] - '0' , 1 , i % m));
    }
    cout << ans;
}