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

vector<vec> IN;
vector<ll> mem;

main(){
    int n=in(),m=in();
    G.resize(n+1);
    IN.resize(n+1);
    rep(i,m){
        int a=in(),b=in();
        G[a].pb(b);G[b].pb(a);
        if(a<b)swap(a,b);
        IN[b].pb(a);
    }
    int dp[N]={};
    ll ans=0;
    rep3(i,n,1){
        for(auto e:G[i]){
            dp[e]++;
        }
        ans+=(ll)dp[i]*(G[i].size()-IN[i].size());
    }
    int q=in();
    cout<<ans<<endl;
    rep(iii,q){
        int v=in();
        ll out=G[v].size()-IN[v].size();
        ll come=IN[v].size();
        ans-=come*out;
        for(auto e:IN[v]){
            ans-=IN[e].size();
            ans+=(G[e].size()-IN[e].size()-1);
            IN[e].pb(v);
        }
        IN[v]=vector<int>();
        cout<<ans<<endl;
    }
}