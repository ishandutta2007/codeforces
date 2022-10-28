#include "bits/stdc++.h"
using namespace std;
const int N = 1e3 + 3;
const int C = 26;
const int mod = 1e9 + 7;
int n;
char a[N];
int arr[C];
int dp[N];
int solve1(int pos){
    if(pos > n){
        return 1;
    }
    if(dp[pos] != -1){
        return dp[pos];
    }
    int res = 0;
    int mn = n + 1;
    for(int i = pos ; i <= n ; ++i){
        mn = min(mn , arr[a[i] - 'a']);
        if(i - pos + 1 <= mn){
            res += solve1(i + 1);
            if(res >= mod){
                res -= mod;
            }
        }
        else{
            break;
        }
    }
    return dp[pos] = res;
}
int solve2(int pos){
    if(pos > n){
        return 0;
    }
    if(dp[pos] != -1){
        return dp[pos];
    }
    int res = 0;
    int mn = n + 1;
    for(int i = pos ; i <= n ; ++i){
        mn = min(mn , arr[a[i] - 'a']);
        if(i - pos + 1 <= mn){
            res = max(res , max(i - pos + 1 , solve2(i + 1)));
        }
        else{
            break;
        }
    }
    return dp[pos] = res;
}
int solve3(int pos){
    if(pos > n){
        return 0;
    }
    if(dp[pos] != -1){
        return dp[pos];
    }
    int res = n + 1;
    int mn = n + 1;
    for(int i = pos ; i <= n ; ++i){
        mn = min(mn , arr[a[i] - 'a']);
        if(i - pos + 1 <= mn){
            res = min(res , 1 + solve3(i + 1));
        }
        else{
            break;
        }
    }
    return dp[pos] = res;
}
int main(){
    scanf("%d" , &n);
    scanf("%s" , a + 1);
    for(int i = 0 ; i < 26 ; ++i){
        scanf("%d" , arr + i);
    }
    memset(dp , -1 , sizeof(dp));
    printf("%d\n" , solve1(1));
    memset(dp , -1 , sizeof(dp));
    printf("%d\n" , solve2(1));
    memset(dp , -1 , sizeof(dp));
    printf("%d\n" , solve3(1));
}