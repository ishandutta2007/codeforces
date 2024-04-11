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
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep3(i,a,b) for(int i=a;i>=b;i--)
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
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 610000
ll n,m,k;
ll inv[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,500000){
        inv[i]=((-(MOD/i)*inv[MOD%i])%MOD+MOD)%MOD;
    }
    return;
}
ll dp[60][30000];
int main(){
    calc_inv();
    n=lin();
    k=lin();
    ll s[30000]={};
    int temp=-1;
    ll p[30000]={};
    ll nn=n;
    for(ll i=2;i*i<=nn;i++){
        if(nn%i==0){
            temp++;p[temp]=i;
        }
        while(nn%i==0){
            s[temp]++;
            nn/=i;
        }
    }
    if(nn!=1){s[++temp]=1;p[temp]=nn;}
    temp++;
    ll ans=0;
    rep(i,temp){
        dp[s[i]][i]=(ll)1;
        rep(ii,k){
            ll rui[60]={};
            rep(iii,s[i]+1){
                rui[0]=(rui[0]+inv[iii+1]*dp[iii][i]%MOD)%MOD;
                rui[iii+1]=(rui[iii+1]-inv[iii+1]*dp[iii][i]%MOD+MOD)%MOD;
            }
            dp[0][i]=rui[0];
            rep(iii,s[i]){
                dp[iii+1][i]=(dp[iii][i]+rui[iii+1])%MOD;
            }
        }
    }
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            ll now[30000]={};
            ll t=i;
            ll tempans=1;
            rep(j,temp){
                while(t%p[j]==0){
                    now[j]++;
                    t/=p[j];
                }
                tempans=tempans*dp[s[j]-now[j]][j]%MOD;
            }
            t=n/i;
            ans=(ans+tempans*((n/i)%MOD)%MOD)%MOD;
            tempans=1;
            if(t==i)continue;
            ll now2[30000]={};
            rep(j,temp){
                while(t%p[j]==0&&t){
                    now2[j]++;
                    t/=p[j];
                }
                tempans=tempans*dp[s[j]-now2[j]][j]%MOD;
            }
            ans=(ans+tempans*(i%MOD)%MOD)%MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}