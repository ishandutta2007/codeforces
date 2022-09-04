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
ll MOD=924844033;
#define N 355050

ll n,m,k;
ll a[N];
ll b[N];
ll d[N];
ll d2[N];
ll ans;
vector<ll> divisor[30];
main(){
    n=in();
    rep(i,n)a[i]=in();
    rep(i,n)b[i]=in();
    if(a[0]!=b[0]||a[n-1]!=b[n-1]){
        cout<<"No";
        return 0;
    }
    rep(i,n-1){
        d[i]=(a[i+1]-a[i]);
        d2[i]=(b[i+1]-b[i]);
    }
    sort(d,d+(n-1));
    sort(d2,d2+(n-1));
    bool flag=true;
    rep(i,n-1){
        if(d[i]!=d2[i])flag=false;
    }
    cout<<(flag?"Yes":"No");
}