#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
int n;
long long l;
int k;
vector < pair < int , int > > a;
int ans;
vector < vector < int > > dp;
vector < int > prv , nxt;
int solve(int cnt , int pos){
    if(pos < 0){
        return 0;
    }
    if(!cnt){
        return 1;
    }
    if(dp[cnt][pos] != -1){
        return dp[cnt][pos];
    }
    return dp[cnt][pos] = (1LL * solve(cnt - 1 , pos) * (nxt[pos] - prv[pos] - 1) + solve(cnt , prv[pos])) % mod;
}
int main(){
    scanf("%d %lld %d" , &n , &l , &k);
    a.clear();
    a.resize(n);
    for(int i = 0 ; i < n ; ++i){
        scanf("%d" , &a[i].first);
        a[i].second = i;
    }
    dp.resize(k , vector < int > (n , -1));
    sort(a.begin() , a.end());
    nxt.resize(n);
    prv.resize(n);
    prv[0] = -1;
    for(int i = 1 ; i < n ; ++i){
        if(a[i].first == a[i - 1].first){
            prv[i] = prv[i - 1];
        }
        else{
            prv[i] = i - 1;
        }
    }
    nxt[n - 1] = n;
    for(int i = n - 2 ; i >= 0 ; --i){
        if(a[i].first == a[i + 1].first){
            nxt[i] = nxt[i + 1];
        }
        else{
            nxt[i] = i + 1;
        }
    }
    int val = (l / n) % mod;
    for(int i = 0 ; i < k && i < l / n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            ans = (ans + 1LL * solve(i , j) * (val + mod - i)) % mod;
        }
    }
    for(int i = 0 ; i < k && i <= l / n ; ++i){
        for(int j = 0 ; j < n ; ++j){
            if(a[j].second < (l % n)){
                ans = (ans + solve(i , j)) % mod;
            }
        }
    }
    printf("%d\n" , ans);
}