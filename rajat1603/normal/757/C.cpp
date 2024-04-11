#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int M = 1e6 + 6;
const int mod = 1e9 + 7;
int n , m;
int g;
int inp;
int fact[M];
int cnt[M];
vector < int > arr[N];
vector < pair < int , int > > v[M];
map < vector < pair < int , int > > , int > mp;
int main(){
    scanf("%d %d" , &n , &m);
    memset(cnt , 0 , sizeof(cnt));
    fact[0] = 1;
    for(int i = 1 ; i <= m ; ++i){
        fact[i] = (1LL * fact[i - 1] * i) % mod;
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &g);
        arr[i].clear();
        arr[i].resize(g);
        for(int j = 1 ; j <= g ; ++j){
            scanf("%d" , &inp);
            arr[i][j - 1] = inp;
            ++cnt[inp];
        }
        for(int x : arr[i]){
            if(cnt[x]){
                v[x].emplace_back(make_pair(i , cnt[x]));
            }
            cnt[x] = 0;
        }
    }
    mp.clear();
    for(int i = 1 ; i <= m ; ++i){
        ++mp[v[i]];
    }
    int ans = 1;
    for(auto it : mp){
        ans = (1LL * ans * fact[it.second]) % mod;
    }
    printf("%d\n" , ans);
}