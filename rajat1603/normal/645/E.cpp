#include "bits/stdc++.h"
using namespace std;
const int N = 2e6 + 6;
const int mod = 1e9 + 7;
inline int add(int a , int b){
    int res = a + b;
    if(res >= mod){
        return res - mod;
    }
    return res;
}
int n , k;
int m;
char str[N];
int lst[36];
int dp[N];
vector < int > v;
int main(){
    scanf("%d %d" , &n , &k);
    scanf("%s" , str + 1);
    m = strlen(str + 1);
    memset(lst , 0 , sizeof(lst));
    dp[0] = 1;
    for(int i = 1 ; i <= m ; ++i){
        dp[i] = add(dp[i - 1] , dp[i - 1]);
        if(lst[str[i] - 'a' + 1]){
            dp[i] = add(dp[i] , mod - dp[lst[str[i] - 'a' + 1] - 1]);
        }
        lst[str[i] - 'a' + 1] = i;
    }
    for(int i = 1 ; i <= k ; ++i){
        v.emplace_back(i);
    }
    sort(v.begin() , v.end() , [](int a , int b){
        return lst[a] < lst[b];
    });
    int l = 0;
    for(int i = m + 1 ; i <= n + m ; ++i){
        str[i] = v[l] + 'a' - 1;
        l = (l + 1) % k;
    }
    for(int i = m + 1 ; i <= n + m ; ++i){
        dp[i] = add(dp[i - 1] , dp[i - 1]);
        if(lst[str[i] - 'a' + 1]){
            dp[i] = add(dp[i] , mod - dp[lst[str[i] - 'a' + 1] - 1]);
        }
        lst[str[i] - 'a' + 1] = i;
    }
    printf("%d\n" , dp[n + m]);
}