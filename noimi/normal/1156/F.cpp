#include <stdio.h>  
#include <algorithm>  
#include <assert.h>
#include <bitset>
#include <cmath>  
#include <complex>  
#include <deque>  
#include <functional>  
#include <iostream>  
#include <limits.h>  
#include <map>  
#include <math.h>  
#include <queue>  
#include <set>  
#include <stdlib.h>  
#include <string.h>  
#include <string>  
#include <time.h>  
#include <unordered_map>  
#include <unordered_set>  
#include <vector>  
#include <chrono>
#include <random>
#include <time.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define REP(e,v) for(auto e:v)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
#define MAX_V 400010
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define ALL(c) (c).begin(),(c).end()
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 310000
ll MOD=998244353;

ll int inv[N],comb[N],prd[N],invprd[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N-1){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
int a[5100];
ll dp[5100][5100];
main(){
    calc_inv();
    int n=in();
    rep(i,n){
        int x=in();
        a[x]++;
    }
    dp[0][0]=1;
    ll ans=0;
    rep2(i,1,n){
        rep(j,n+1){
            dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            dp[i][j+1]=(dp[i][j+1]+dp[i-1][j]*a[i]%MOD*inv[n-j]%MOD)%MOD;
            if(a[i]>1){
                ans=(ans+dp[i-1][j]*a[i]%MOD*(a[i]-1)%MOD*inv[n-j]%MOD*inv[n-j-1]%MOD)%MOD;
            }
        }
    }
    cout<<ans;
}