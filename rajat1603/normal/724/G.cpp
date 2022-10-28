#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int K = 60;
const int mod = 1e9 + 7;
int n , m;
int a , b;
long long c;
int cnt[K][2];
long long basis[K];
long long bor;
int sz;
vector < pair < int , long long > > v[N];
bool visited[N];
long long val[N];
long long ans;
int pw2[N + K];
void add(long long val){
    for(int i = 0 ; i < K ; ++i){
        ++cnt[i][(val >> i) & 1];
    }
}
void addcycle(long long val){
    bor |= val;
    for(int i = K - 1 ; i >= 0 ; --i){
        if((val >> i) & 1){
            if(basis[i] == 0){
                basis[i] = val;
                ++sz;
                break;
            }
            else{
                val ^= basis[i];
            }
        }
    }
}
void dfs(int node , int baap){
    visited[node] = 1;
    add(val[node]);
    for(auto it : v[node]){
        if(it.first != baap){
            if(!visited[it.first]){
                val[it.first] = val[node] ^ it.second;
                dfs(it.first , baap);
            }
            else{
                addcycle(val[node] ^ val[it.first] ^ it.second);
            }
        }
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d %lld" , &a , &b , &c);
        v[a].push_back({b , c});
        v[b].push_back({a , c});
    }
    pw2[1] = 1;
    for(int i = 2 ; i <= n + K ; ++i){
        pw2[i] = (pw2[i - 1] + pw2[i - 1]) % mod;
    }
    for(int i = 1 ; i <= n ; ++i){
        if(!visited[i]){
            memset(cnt , 0 , sizeof(cnt));
            memset(basis , 0 , sizeof(basis));
            bor = 0;
            sz = 0;
            dfs(i , 0);
            for(int i = 0 ; i < K ; ++i){
                if(bor & (1LL << i)){
                    (ans += ((1LL * (cnt[i][0] + cnt[i][1]) * (cnt[i][0] + cnt[i][1] - 1LL) / 2LL) % mod) * pw2[i + sz]) %= mod;
                }
                else{
                    (ans += ((1LL * cnt[i][0] * cnt[i][1]) % mod) * pw2[i + sz + 1]) %= mod;
                }
            }
        }
    }
    printf("%lld\n" , ans);
}