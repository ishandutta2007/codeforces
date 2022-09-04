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

main(){
    int n;
    cin>>n;
    int a[N]={};
    if(n==1||n==2) {
        cout<<"No";
        return 0;
    }
    int flag=1;
    ll m=n*(n+1)/2;
    rep2(i,1,n){
        if(flag&&m%i==0&&i>1){
            a[i]=1;flag=0;
        }
    }
    if(flag==1){
        cout<<"No";return 0;
    }
    cout<<"Yes"<<endl;
    cout<<1<<" ";
    rep2(i,1,n){
        if(a[i])cout<<i<<endl;
    }
    cout<<n-1<<" ";
    rep2(i,1,n){
        if(!a[i])cout<<i<<" ";
    }
    
    return 0;
}