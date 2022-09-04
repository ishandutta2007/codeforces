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
#define N 400000


main(){
    ll a=lin(),b=lin();
    ll d=abs(a-b);
    vector<ll> p;
    for(ll i=1;i*i<=d;i++){
        if(d%i==0){
            p.pb(i);
            if(i*i!=d)p.pb(d/i);
        }
    }
    ll MIN=2e18;
    //cout<<MIN<<endl;
    ll memk=0;
    for(ll x:p){
        ll k=(b+x-1ll)/x*x-b;
        //cout<<x<<" "<<k<<endl;
        if((a+k)*(b+k)/x<MIN){
            MIN=(a+k)*(b+k)/x;
            memk=k;
        }
    }
    cout<<memk;
}