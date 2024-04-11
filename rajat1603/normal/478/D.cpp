#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
int a , b;
int height;
int check(int val){
    int cur = val;
    int aa = a , bb = b;
    while(cur){
        if(aa > bb){
            aa -= cur;
        }
        else{
            bb -= cur;
        }
        --cur;
    }
    return (min(aa , bb) >= 0);
}
int getheight(){
    int l = 0;
    int r = max(a , b) + 1;
    while(l < r){
        int mid = l + r >> 1;
        if(check(mid)){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l - 1;
}
int dp[2][200005];
int getb(int aa , int cur){
    int x = 0;
    x += (height * (height + 1)) / 2;
    x -= (cur * (cur + 1)) / 2;
    return a + b - x - aa;
}
int main(){
    cin >> a >> b;
    height = getheight();
    for(int i = 0 ; i <= height ; ++i){
        for(int j = 0 ; j <= a ; ++j){
            if(i == 0){
                dp[i & 1][j] = 1;
                continue;
            }
            dp[i & 1][j] = 0;
            int k = getb(j , i);
            if(k < 0){
                continue;
            }
            if(j >= i){
                dp[i & 1][j] += dp[!(i & 1)][j - i];
            }
            if(k >= i){
                dp[i & 1][j] += dp[!(i & 1)][j];
            }
            if(dp[i & 1][j] >= mod){
                dp[i & 1][j] -= mod;
            }
        }
    }
    cout << dp[height & 1][a];
}