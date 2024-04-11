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
void makegraph(int x,vector<vec> &v){rep(i,x-1){int a=in(),b=in();v[a].pb(b);v[b].pb(a);}}
template<typename A, size_t NNN, typename T>
void Fill(A (&array)[NNN], const T &val){
    fill( (T*)array, (T*)(array+NNN), val );
}
#define INF 1e9+7
#define LLINF 1e18+7
ll MOD=1e9+7;
#define N 255050

ll n,m,k;
ll a[N];
ll sum[N];
main(){
    n=in();k=in();
    rep(i,n)a[i]=in();
    string s;cin>>s;
    sum[0]=0;
    rep(i,n){
        sum[i+1]=sum[i]+a[i];
    }
    int now=0;
    ll ans=0;
    while(now<n){
        int next=now;
        while(next<n&&s[next]==s[now]){
            next++;
        }
        if(next-now<=k){
            ans+=sum[next]-sum[now];
        }
        else{
            priority_queue<ll> p;
            rep2(i,now,next-1){
                p.push(a[i]);
            }
            rep(i,k){
                ans+=p.top();
                p.pop();
            }
        }
        now=next;
    }
    cout<<ans;
    return 0;
}