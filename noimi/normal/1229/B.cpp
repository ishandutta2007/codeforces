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


#define LLINF 1e18+7
#define N 250000
ll MOD=1e9+7;
vector<vec> G;
vector<ll> x;
ll ans=0;
ll gcd(ll x,ll y){
    if(x==0)return y;
    else return gcd(y%x,x);
}
void  dfs(int y,int p,map<ll,int> mp){
    mp[x[y]]++;
    map<ll,int> mp2;
    for(auto g:mp){
        ll h=gcd(g.first,x[y]);
        ans=(ans+h*g.second)%MOD;
        mp2[h]+=g.second;
    }
    for(auto e:G[y]){
        if(e==p)continue;
        dfs(e,y,mp2);
    }
    return ;
} 


main(){
    int n=in();
    x.pb(0);
    rep(i,n)x.pb(lin());
    G.resize(n+1);
    rep(i,n-1){
        int a=in(),b=in();
        G[a].pb(b);G[b].pb(a);
    }
    map<ll,int> mp;
    dfs(1,0,mp);
    cout<<ans<<endl;
}