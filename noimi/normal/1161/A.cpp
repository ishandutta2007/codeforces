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

int a[1100][1100];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int U[N],D[N],R[N],L[N];
main(){
    ll n=in(),k=in();
    int x[N];
    vector<ll> last(N,-1),first(N,INF);
    rep(i,k){
        x[i]=in();
        last[x[i]]=max(last[x[i]],i);
        first[x[i]]=min(first[x[i]],i);
    }
    int ans=0;
    rep2(i,1,n){
        if(last[i]<=first[i+1]&&i+1!=n+1)ans++;
        if(last[i]<=first[i-1]&&i-1)ans++;
        if(last[i]==-1)ans++;
    }
    cout<<ans;
}