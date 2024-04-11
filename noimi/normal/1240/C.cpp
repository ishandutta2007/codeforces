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
using namespace std;
int in() {int x;scanf("%d",&x);return x;}
ll lin() {ll x;scanf("%lld",&x);return x;}

#define INF 1e9+7
#define LLINF 1e18+7
#define N 250000
ll MOD=998244353;

ll ans=0;
vector<vector<pll>> G;
ll dfs(int x,int p,int k){
    ll lost=0;
    vecll v;
    for(auto e:G[x]){
        if(e.first==p)continue;
        ll t=e.second-dfs(e.first,x,k);
        if(t>0)
        v.pb(t);
    }
    if(v.size()<k){
        for(auto e:v)ans+=e;
        return 0;
    }
    else{
        sort(all(v),greater<ll>());
        rep(i,k){
            ans+=v[i];
        }
        return v[k-1];
    }
}


main(){
    int q=in();
    rep(iii,q){
        int n=in();
        int k=in();
        G=vector<vector<pll>>(n+1);
        ans=0;
        rep(i,n-1){
            int a=in(),b=in();
            ll c=lin();
            G[a].pb({b,c});
            G[b].pb({a,c});
        }
        dfs(1,0,k);
        cout<<ans<<endl;
    }

}