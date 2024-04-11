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
ll MOD=998244353;
#define N 210000

main(){
    ll m=in(),a=in(),b=in();
    ll t[N]={};
    ll now=0;
    t[0]=1;
    ll l=0;
    int times=b;
    while(times--){   
        while(now<b){
            now+=a;
            l=max(l,now);
            if(t[now])t[now]=min(t[now],l);
            else t[now]=l;
        }
        l=max(l,now);
        if(now>m)break;
        //bool flag=false;
        while(now-b>=0){
            now-=b;
            if(t[now]){
                //flag=true;
            t[now]=min(t[now],l);
            }
            else t[now]=l;
        }
        //if(flag)break;
    }
    ll ans=0;
    rep(i,a){
        //cout<<t[i]<<endl;
        if(t[i]){
            now=i;
            if(i==0)t[i]=0;
            while(now<t[i]){
                ans+=m-t[i]+1;
                now+=a;
            }
            if(now>m)continue;
            ll n=(m-now+1)/a+1;
            ans+=(m-now+1+(m-now+1)%a)*n/2;
            //cout<<ans<<endl;
        }
    }
    cout<<ans;
}