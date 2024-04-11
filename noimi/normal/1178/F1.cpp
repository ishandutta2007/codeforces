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




vector<vector<ll> > mem(600,vector<ll>(600));
vector<int> v;
ll dfs(int x,int y){
    if(x<0||y<0)return 1ll;
    if(mem[x][y]!=0)return mem[x][y];
    if(x>=y)return 1ll;
    pii p={INF,0};
    rep2(i,x,y)if(v[i]<p.first){p={v[i],i};}
    ll ansl=0,ansr=0;
    rep2(i,x,p.second){
        ansl+=dfs(x,i-1)*dfs(i,p.second-1)%MOD;
        ansl%=MOD;
        //if(x==0&&y==2)cout<<dfs(x,i-1).a<<" "<<dfs(i,p.second-1).a<<endl;
    }
    rep2(i,p.second,y){
        ansr+=dfs(p.second+1,i)*dfs(i+1,y)%MOD;
        ansr%=MOD;
    }
    //cout<<x<<y<<" "<<ansl.a<<" "<<ansr.a<<endl;
    return mem[x][y]=ansl*ansr%MOD;
}
main(){
    int n=in(),m=in();
    rep(i,n)v.pb(in());
    cout<<dfs(0,n-1);
}