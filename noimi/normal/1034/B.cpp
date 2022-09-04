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
#define INF 2*1e9
#define N 600010
#define MAX_V 900010
using namespace std;

main(){
    ll n,m;cin>>n>>m;
    if(m==1)swap(n,m);
    if(n==1){
        if(m%6<=3)cout<<(m/6)*6;
        else if(m%6==4)cout<<m-2;
        else if(m%6==5)cout<<m-1;
        return 0;
    }
    if(m==2)swap(n,m);
    if(n==2){
        if(m<=2)cout<<0;
        else if(m==3)cout<<4;
        else if(m==7)cout<<12;
        else cout<<n*m;
        return 0;
    }
    if(n%2&&m%2)cout<<n*m-1;
    else cout<<n*m;
}