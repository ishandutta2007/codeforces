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

vector<vec> G(N);
main(){
    int n=in(),m=in();
    vector<pii> v;
    rep(i,m){
        int a=in(),b=in();
        G[a].pb(b);
        G[b].pb(a);
        v.pb({a,b});
    }
    rep2(i,1,n)sort(ALL(G[i]));
    vec p;
    int nn=n;
    p.pb(1);
    for(int i=2;i*i<=nn;i++){
        if(n%i==0){
            p.pb(i);
            if(n!=i*i)p.pb(n/i);
        }

    }
    for(auto u:p){
        //cout<<u<<endl<<endl;
        bool flag=true;
        for(auto c:v){
            int a=c.first+u,b=c.second+u;
            if(a>n)a-=n;
            if(b>n)b-=n;
            //cout<<a<<" "<<b<<endl;
            if(find(ALL(G[a]),b)==G[a].end()){
                flag=false;
            }
        }
        if(flag){
            cout<<"Yes";return 0;
        }
    }
    cout<<"No";
}