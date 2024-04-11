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
#define N 510000
ll MOD=1e9+7;
ll inv[N];
ll a[N];
vector<vec> G(N);
ll b[N],g[N];
main(){
    ll n=in(),m=in();
    rep(i,n)b[i]=in();
    rep(i,m)g[i]=in();
    sort(b,b+n);sort(g,g+m);
    if(g[0]<b[n-1]){
        cout<<-1;return 0;
    }
    ll ans=0;
    ll B=b[n-1];
    rep(i,n){
        ans+=b[i]*m;
    }
    rep(i,m){
        ans+=(g[i]-B);
    }
    if(g[0]!=B)
    ans+=B-b[n-2];
    cout<<ans;
}