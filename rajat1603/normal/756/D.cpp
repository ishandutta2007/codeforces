#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const int C = 27; 
const int mod = 1e9 + 7;
int n;
char str[N];
vector < int > v;
int nxt[N];
int lst[N];
int dp[N][N];
int solve(int pos , int cur){
    if(pos > n){
        return 1;
    }
    if(dp[pos][cur] != -1){
        return dp[pos][cur];
    }
    int res = 0;
    if(cur + 1 < v.size()){
        res += solve(pos , cur + 1);
    }
    res += solve(pos + 1 , cur);
    res %= mod;
    if(nxt[cur] != -1){
        res -= solve(pos + 1 , nxt[cur]);
        if(res < 0){
            res += mod;
        }
    }
    return dp[pos][cur] = res;
}
int main(){
    memset(dp , -1 , sizeof(dp));
    scanf("%d" , &n);
    scanf("%s" , str + 1);
    v.clear();
    str[0] = '$';
    for(int i = 1 ; i <= n ; ++i){
        if(str[i] != str[i - 1]){
            v.emplace_back(str[i] - 'a' + 1);
        }
    }
    memset(nxt , -1 , sizeof(nxt));
    memset(lst , 0 , sizeof(lst));
    for(int i = v.size() - 1 ; i >= 0 ; --i){
        int x = v[i];
        if(lst[x]){
            nxt[i] = lst[x];
        }
        lst[x] = i;
    }
    printf("%d\n" , solve(1 , 0));
}