#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int MX = 8;
int n;
int arr[N];
int freq[N][8];
int when[N + N][8];
int ans;
int dp[N][1 << MX];
int solve(int sz){
    for(int i = 0 ; i < 256 ; ++i){
        if(sz > 0){
            dp[n + 1][i] = -1e9;
        }
        else{
            dp[n + 1][i] = 0;
        }
    }
    dp[n + 1][0] = 0;
    dp[n + 1][255] = 0;
    for(int pos = n ; pos >= 1 ; --pos){
        int val = arr[pos];
        int nxt1 = when[freq[pos - 1][val] + sz][val];
        int nxt2 = when[freq[pos - 1][val] + sz + 1][val];
        for(int mask = 0 ; mask < 256 ; ++mask){
            int res = dp[pos + 1][mask];
            if(!(mask & (1 << val))){
                if(nxt1){
                    res = max(res , dp[nxt1 + 1][mask | (1 << val)] + sz);
                }
                if(nxt2){
                    res = max(res , dp[nxt2 + 1][mask | (1 << val)] + sz + 1);
                }
            }
            dp[pos][mask] = res;
        }
    }
    return dp[1][0];
}
int main(){
    scanf("%d" , &n);
    memset(freq , 0 , sizeof(freq));
    memset(when , 0 , sizeof(when));
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        --arr[i];
        for(int j = 0 ; j < 8 ; ++j){
            freq[i][j] = freq[i - 1][j];
        }
        ++freq[i][arr[i]];
        when[freq[i][arr[i]]][arr[i]] = i;
    }
    ans = 0;
    int l = 0;
    int r = n;
    while(r - l > 5){
        int mid = l + r >> 1;
        int val = solve(mid);
        ans = max(ans , val);
        if(val > 0){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    for(int i = l ; i <= r ; ++i){
        ans = max(ans , solve(i));
    }
    printf("%d\n" , ans);
}