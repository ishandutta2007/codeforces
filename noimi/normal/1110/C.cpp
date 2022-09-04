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
ll d[N];
ll ans;
vector<ll> divisor[30];
main(){
    int q=in();
    rep(i,26){
        ll t=1ll<<i;
        t--;
        for(ll j=2;j*j<=t;j++){
            if(t%j==0){
                divisor[i].pb(j);
                divisor[i].pb(t/j);
            }
        }
        divisor[i].pb(t);
        sort(ALL(divisor[i]),greater<ll>());
    }
    rep(iii,q){
        n=in();
        ll t=1;
        ll s=0;
        while(t<=n){
            t*=2;s++;
        }
        ll as=1;
        rep(i,divisor[s].size()){
            if((n&divisor[s][i]==divisor[s][i])&&(divisor[s][i]!=n)){
                as=divisor[s][i];
                break;
            }
            if((n^divisor[s][i])>0ll&&n^divisor[s][i]<n){
                as=divisor[s][i];
                break;
            }
        }
        cout<<as<<endl;
    }
}