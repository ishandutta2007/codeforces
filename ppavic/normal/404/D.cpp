#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

using namespace std;

const int N = 1e6 + 50;
const int MOD = 1e9 + 7;

int n;
string s;
int dp[N][4][4];

int f(int i,int l1,int l2){
    //printf("%d %d %d\n",i,l1,l2);
    if(l1 != -1 && l2 != -1 && dp[i][l1][l2] != -1) return dp[i][l1][l2];
    if(i == n) {
        if((l2 == 1 && l1 != 3) || (l2 == 0 && l1 == 3) || l2 == 2 || (l1 == 0 && l2 == 3)) return dp[i][l1][l2] = 0;
        return 1;
    }
    if(s[i] != '?'){
        if(s[i] == '0' && l2 == 3)                          return dp[i][l1][l2] = 0;
        if(s[i] == '1' && l2 == 2)                          return dp[i][l1][l2] = 0;
        if(s[i] == '2' && l2 != 3)                          return dp[i][l1][l2] = 0;
        if(s[i] != '*' && l2 == 1 && l1 != 3)               return dp[i][l1][l2] = 0;
        if(s[i] != '*' && l2 == 2)                          return dp[i][l1][l2] = 0;
        if(s[i] == '*' && l2 == 0)                          return dp[i][l1][l2] = 0;
        if(s[i] == '*' && l1 == 3 && (l2 != 2 && l2 != 3))  return dp[i][l1][l2] = 0;
        if(s[i] == '0')                                     return dp[i][l1][l2] = f(i + 1, l2 ,0);
        if(s[i] == '1')                                     return dp[i][l1][l2] = f(i + 1, l2, 1);
        if(s[i] == '2')                                     return dp[i][l1][l2] = f(i + 1, l2, 2);
        if(s[i] == '*')                                     return dp[i][l1][l2] = f(i + 1, l2, 3);
    }
    else{
        int ret = 0;
        if(l2 == 2)                                         return dp[i][l1][l2] = f(i + 1 , l2, 3);
        if(l2 == 1 && l1 != 3)                              return dp[i][l1][l2] = f(i + 1, l2, 3);
        if(l2 != 3)                                         ret = (ret + f(i + 1, l2, 0)) % MOD;
        if(l2 == 3)                                         ret = (ret + f(i + 1, l2 , 2)) % MOD;
        if(l2 != 2)                                         ret = (ret + f(i + 1, l2, 1)) % MOD;
        if((l2 != 0) && (l2 != 1 || l1 != 3))               ret = (ret + f(i + 1, l2 ,3)) % MOD;
                                                            return dp[i][l1][l2] = ret;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp,-1,sizeof(dp));
    cin >> s;
    n = s.size();
    cout << f(0, -1 , -1);
}