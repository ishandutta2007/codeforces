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
#define N 200010
using namespace std;
main(){
    ll n,t;cin>>n>>t;
    ll a[N],x[N],b[N];
    rep(i,n)cin>>a[i];
    rep(i,n){
        cin>>x[i];
        x[i]--;
        if((i>0&&x[i]<x[i-1])||x[i]<i){
            cout<<"No";return 0;
        }
    }
    int c[N]={};
    rep(i,n){
        ll temp=x[i];
        c[x[i]]=1;
        if(temp==i){
            if(i>0)
            b[i]=max(a[i]+t,b[i-1]+1);
            else b[i]=a[i]+t;
            if(i<n-1&&b[i]>=a[i+1]+t){
                cout<<"No";return 0;
            }
        }
        else{
            if(i>0)
            b[i]=max(a[i+1]+t,b[i-1]+1);
            else b[i]=a[i+1]+t;
        }
        if(i<n-1&&c[i]&&b[i]>=a[i+1]+t){
            cout<<"No";return 0;
        }
    }
    cout<<"Yes"<<endl;
    rep(i,n){
        printf("%lld ",b[i]);
    }
    return 0;
}