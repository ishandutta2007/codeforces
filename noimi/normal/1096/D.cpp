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
#define N 110100
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=998244353;

ll n,a[N];
ll dp[N][4];
main(){
    n=lin();
    string s;cin>>s;
    rep(i,n){
        a[i]=lin();
    }
    ll ans=0;
    rep2(i,1,110000){
        rep(j,4)dp[i][j]=10000000000000000;
    }
    rep(i,n){
        int check=-1;
        if(s[i]=='h')check=1;
        if(s[i]=='a')check=2;
        if(s[i]=='r')check=3;
        if(s[i]=='d')check=4;        
        if(check==1){
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]+a[i]);
            dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
        }
        else{
            dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
        }
        if(check==2){
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]+a[i]);
            dp[i+1][2]=min(dp[i][1],dp[i+1][2]);
        }
        else{
            dp[i+1][1]=min(dp[i+1][1],dp[i][1]);
        }
        if(check==3){
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]+a[i]);
            dp[i+1][3]=dp[i][2];
        }
        else{
            dp[i+1][2]=min(dp[i+1][2],dp[i][2]);
        }
        if(check==4){
            dp[i+1][3]=min(dp[i+1][3],dp[i][3]+a[i]);
        }
        else{
            dp[i+1][3]=min(dp[i+1][3],dp[i][3]);
        }
    }
    ans=min({dp[n][0],dp[n][1],dp[n][2],dp[n][3]});
    cout<<ans<<endl;
}