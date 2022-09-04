#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=998244353;
#define INF 1e9*2;
#define N 400000
#define MAX_V 900010
#define vec vector<int>
using namespace std;
ll modpow(ll x,ll n){
    if(n==0) return 1;
    ll res=modpow(x*x%MOD,n/2);
    if(n&1) res=res*x%MOD;
    return res;
}
main(){
    ll n,m,a;
    cin>>n>>m>>a;
    ll b[N];
    b[0]=0;
    rep2(i,1,m){
        cin>>b[i];
    }
    ll sum=1;
    rep2(i,1,m){
        ll t=b[i]-b[i-1];
        sum=sum*(modpow(a,t)*(modpow(a,t)+1)/2%MOD)%MOD;
    }
    sum=sum*modpow(a,n-b[m]*2)%MOD;
    cout<<sum;
}