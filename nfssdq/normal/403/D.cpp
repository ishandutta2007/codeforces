#include<bits/stdc++.h>

using namespace std;
#define mod 1000000007ll
#define LL long long

LL dp[51][1001], res[51][1001], ncr[2001][2001], fact[101];
main(){
    LL a,b,c,d,e,f,g,h,x,y,z;
    ncr[0][0] = 1;
    for(int i = 1; i <= 2000; i++){
        ncr[i][0] = 1;
        for(int j = 1; j <= i; j++) ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % mod;
    }
    dp[0][0] = 1;
    for(int k = 1; k <= 50; k++){
        dp[k][0] = 1;
        for(int lft = 1; lft <= 1000; lft++){
            for(int i = 1; i <= min(lft, k); i++){
                dp[k][lft] = (dp[k][lft] + dp[i][lft - i]) % mod;
            }
        }
    }
    res[0][0] = 1;
    for(int k = 1; k <= 50; k++){
        for(int lft = 0; lft <= 1000; lft++){
            for(int i = 0; i <= lft; i++){
                res[k][lft] = (res[k][lft] + dp[k][i]*ncr[k + 1 + lft - i - 1][k]) % mod;
            }
        }
    }
    fact[0] = 1;
    for(LL i = 1; i <= 55; i++) fact[i] = (fact[i - 1] * i) % mod;
    cin >> a;
    for(int ts = 1; ts <= a; ts++){
        cin >> b >> c;
        d = c * (c + 1) / 2;
        b -= d;
        if(b < 0)cout << 0 << endl;
        else cout << (res[c][b] * fact[c]) % mod << endl;
    }
}