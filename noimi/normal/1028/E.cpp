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
#define N 410000
using namespace std;
main(){
    int n;
    cin>>n;
    ll b[N];
    ll m=0,mem;
    rep(i,n){
        cin>>b[i];
        m=max(m,b[i]);
        if(b[i]==m) mem=i;
    }
    for(int i=n-1;i>=0;i--) if(b[i]==m) mem=i;
    int flag=1;
    rep(i,n){
        if(b[i]!=m) flag=0;
    }
    if(flag&&m){
        cout<<"NO";return 0;
    }
    else if(flag){
        cout<<"YES"<<endl;
        rep(i,n)cout<<1<<" ";
        return 0;
    }
    cout<<"YES"<<endl;
    ll a[N]={};
    a[mem]=b[mem];
    if(mem==0&&b[n-1]==m){
        mem=n-1;
        while(b[mem]==m)mem--;
        mem++;
        a[mem]=b[mem];
    }
    if(mem==0){
        a[n-1]=m+b[n-1];
        if(b[n-1]==0)a[n-1]*=2;
        for(int i=n-2;i>0;i--){
            a[i]=a[i+1]+b[i];
        }
        rep(i,n)cout<<a[i]<<" ";
    }
    else{
        a[mem-1]=m+b[mem-1];
        if(b[mem-1]==0) a[mem-1]*=2;
        for(int i=mem-2;i>=0;i--){
            a[i]=b[i]+a[i+1];
        }
        if(mem!=n-1)
        {a[n-1]=b[n-1]+a[0];
        }
        for(int i=n-2;i>mem;i--){
            a[i]=b[i]+a[i+1];
        }
        if(mem<n-1&&a[mem+1]==m)a[mem+1]*=2;
        if(mem==n-1&&a[0]==m) a[0]*=2;
        rep(i,n)cout<<a[i]<<" ";
    }
}