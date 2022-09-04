#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
#define edge(v,a,b) v[a].pb(b);v[b].pb(a);
ll MOD=1e9+7;
#define INF 2*1e9
#define N 600010
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)return b;
    return gcd(b%a,a);
}
main(){
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    ll g=gcd(x,y);
    x/=g;
    y/=g;
    cout<<min(a/x,b/y);
    
    return 0;
}