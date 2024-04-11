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
    int n,h;cin>>n>>h;
    pii x[N];
    rep(i,n){
        cin>>x[i].first>>x[i].second;
    }
    sort(x,x+n);
    ll b[N];
    b[0]=x[0].first;
    rep2(i,1,n-1){
        b[i]=b[i-1]+x[i].first-x[i-1].second;
    }
    ll M=0;
    rep(i,n){
        ll m=0;
        m+=x[i].second-x[i].first;
        if(b[n-1]-b[i]<h){
            m+=(h-b[n-1]+b[i])+x[n-1].second-x[i].second;
            M=max(m,M);
        }
        else{
            int l=i,r=n;
            while(l+1<r){
                int mid=(l+r)/2;
                if(b[mid]-b[i]<h){
                    l=mid;
                }
                else r=mid;
            }
            m+=(h-b[l]+b[i])+x[l].second-x[i].second;
            M=max(m,M);
        }
    }
    cout<<M;
    
    return 0;
}