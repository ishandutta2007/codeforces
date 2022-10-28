#include "bits/stdc++.h"
using namespace std;
const int N = 5e3 + 3;
const int I = 1e4 + 4;
const int Q = 3e4 + 4;
const int K = 1e3 + 3;
const int logQ = 16;
const int mod = 1e9 + 7;
const int p = 1e7 + 19;
int n , k;
int v[N + I];
int w[N + I];
int idx;
int q;
int type[Q];
int val[Q];
int tin[N + I];
int tout[N + I];
int dp[logQ * K];
void print(int l , int r){
    int cur = 1;
    int res = 0;
    for(int i = l ; i <= r ; ++i){
        res = (res + 1LL * cur * dp[i]) % mod;
        cur = (1LL * cur * p) % mod;
    }
    printf("%d\n" , res);
}
void solve(int l , int r , int pl , int pr , int last){
    bool ok = 0;
    for(int i = l ; i <= r ; ++i){
        if(type[i] == 3){
            ok = 1;
            break;
        }
    }
    if(!ok){
        return;
    }
    for(int i = 1 ; i <= k ; ++i){
        dp[last + i] = dp[last + i - k];
    }
    int mid = pl + pr >> 1;
    if(l == pl){
        for(int i = mid + 1 ; i <= pr ; ++i){
            if(type[i] == 2 && tin[val[i]] < l){
                int who = val[i];
                for(int j = k ; j >= w[who] ; --j){
                    dp[j + last] = max(dp[j + last] , ((j > w[who]) ? dp[j + last - w[who]] : 0) + v[who]);
                }
            }
        }
    }
    else{
        for(int i = pl ; i <= mid ; ++i){
            if(type[i] == 1 && tout[val[i]] > r){
                int who = val[i];
                for(int j = k ; j >= w[who] ; --j){
                    dp[j + last] = max(dp[j + last] , ((j > w[who]) ? dp[j + last - w[who]] : 0) + v[who]);
                }
            }
        }
    }
    if(l < r){
        int mid = l + r >> 1;
        solve(l , mid , l , r , last + k);
        solve(mid + 1 , r , l , r , last + k);
    }
    else{
        print(last + 1 , last + k);
    }
}
int main(){
    scanf("%d %d" , &n , &k);
    idx = 0;
    for(int i = 1 ; i <= n ; ++i){
        ++idx;
        scanf("%d %d" , v + idx , w + idx);
        tin[idx] = 0;
        tout[idx] = Q;
    }
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d" , type + i);
        if(type[i] == 1){
            ++idx;
            scanf("%d %d" , v + idx , w + idx);
            val[i] = idx;
            tin[idx] = i;
            tout[idx] = Q;
        }
        else if(type[i] == 2){
            scanf("%d" , val + i);
            tout[val[i]] = i;
        }
    }
    for(int i = 1 ; i <= idx ; ++i){
        if(tout[i] == Q && tin[i] == 0){
            for(int j = k ; j >= w[i] ; --j){
                dp[j] = max(dp[j] , dp[j - w[i]] + v[i]);
            }
        }
    }
    if(q == 1){
        print(1 , k);
    }
    else{
        solve(1 , 1 + q >> 1 , 1 , q , k);
        solve((1 + q >> 1) + 1 , q , 1 , q , k);
    }
}