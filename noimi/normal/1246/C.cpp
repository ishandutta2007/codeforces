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
#include <fstream>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define endl "\n"
#define all(c) begin(c),end(c)
#define setp(n) setprecision(n)<<fixed
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}
void print(vec v){for(auto e:v)cout<<e<<" ";cout<<endl;}
void print(map<int,int> mp){for(auto e:mp)cout<<e.first<<" "<<e.second<<endl;cout<<endl;}


#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;


main(){
    int n=in(),m=in();
    vector<string> v;
    rep(i,n){
        string s;cin>>s;
        v.pb(s);
    }
    vector<vec> r(n+1),d(n+1);
    rep(i,n){
        r[i].resize(m+1);
        d[i].resize(m+1);
        rep3(j,m-2,0){
            r[i][j]=r[i][j+1]+(v[i][j+1]=='R');
        }
    }
    rep(j,m){
        rep3(i,n-2,0){
            d[i][j]=d[i+1][j]+(v[i+1][j]=='R');
        }
    }
    vector<vecll> dp(n+1,vecll(m+1));
    dp[0][0]=1;
    vector<vecll>dp2(n+1,vecll(m+1));
    dp2[0][0]=1;
    vector<vecll> dp3(n+1,vecll(m+1));
    rep(i,n){
        vecll tmp(m+1);
        rep(j,m){
            if(i!=0)
            dp3[i][j]=(dp3[i][j]+dp3[i-1][j])%MOD;
            dp[i][j]=(dp[i][j]+dp3[i][j])%MOD;
            ll D=dp[i][j];
            tmp[j+1]=(tmp[j+1]+D)%MOD;
            tmp[m-r[i][j]]=(tmp[m-r[i][j]]-D+MOD)%MOD;

            // if(d[i][j]==n-1-i)
            // dp[i+1][j+1]=(dp[i+1][j+1]+dp[i][j])%MOD;
            // else
            // dp[i+1][j]=(dp[i+1][j]+dp[i][j])%MOD;

            // dp[i+1][m-r[i][j]]=(dp[i+1][m-r[i][j]]-dp[i][j]+MOD)%MOD;
            // dp2[]
            
        }
        rep(j,m) tmp[j+1]=(tmp[j+1]+tmp[j])%MOD;
        rep(j,m) dp2[i][j]=(dp2[i][j]+tmp[j])%MOD;
        // cout<<i<<":";
        // rep(j,m)cout<<dp2[i][j]<<" ";
        // rep(j,m) cout<<dp[i+1][j]<<" ";
        // cout<<endl;
        rep(j,m){
            ll D=dp2[i][j];
            dp3[i+1][j]=(dp3[i+1][j]+D)%MOD;
            dp3[n-d[i][j]][j]=(dp3[n-d[i][j]][j]+MOD-D)%MOD;
        }
    }
    ll ans=(dp[n-1][m-1]+dp2[n-1][m-1])%MOD;
    if(n==1&&m==1)cout<<1<<endl;
    else cout<<ans<<endl;
}