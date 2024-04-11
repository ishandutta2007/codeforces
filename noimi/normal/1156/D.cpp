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
ll MOD=1e9+7;


struct UnionFind{
    vector<ll int> par,sizes;
    UnionFind(int n):par(n+1),sizes(n+1,1){
        rep2(i,1,n)par[i]=i;
    }
    int find(int x){
        return (x==par[x]?x:par[x]=find(par[x]));
    }
    void unite(int x,int y){
        x=find(x);y=find(y);
        if(x==y)return ;
        if(sizes[x]<sizes[y]){
            swap(x,y);
        }
        par[y]=x;
        sizes[x]+=sizes[y];
    }
    bool same(int x,int y) {return (find(x)==find(y));}
    ll int size(int x) {return sizes[find(x)];}
};
vector<vec> G(N);
bool used[N][2];
main(){
    int n=in();
    UnionFind u0(n),u1(n);
    rep(i,n-1){
        int x=in(),y=in(),z=in();
        if(z){
            u1.unite(x,y);
        }
        else u0.unite(x,y);
    }
    ll ans=0;
    rep2(i,1,n){
        u0.size(i);
        u1.size(i);
    }
    rep2(i,1,n){
        //cout<<i<<" "<<u0.par[i]<<" "<<u0.size(i)<<" "<<u1.par[i]<<" "<<u1.size(i)<<" "<<endl;
        if(!used[u0.par[i]][0]){
            ans+=(u0.size(i)*(u0.size(i)-1));
            used[u0.par[i]][0]=1;
        }
        if(!used[u1.par[i]][1]){
            ans+=(u1.size(i)*(u1.size(i)-1));
            used[u1.par[i]][1]=1;
        }
        ans+=(u0.size(i)-1)*(u1.size(i)-1);
    }
    cout<<ans;
}