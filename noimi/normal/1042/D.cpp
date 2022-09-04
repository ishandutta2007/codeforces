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
#define MAX_V 900010
using namespace std;
ll bit[N*2],BIT[N*2];

ll sum(int i){
    ll s=0;
    while(i>0){
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
ll sum2(int i){
    ll s=0;
    while(i>0){s+=BIT[i];i-=i&-i;}return s;
}
void add(int i,ll x){
    while(i<=N){
        bit[i]+=x;
        i+=i&-i;
    }
}
void add2(int i,ll x){
    while(i<=N){
        BIT[i]+=x;
        i+=i&-i;
    }
}
main(){
    ll n,t;
    cin>>n>>t;
    ll a[N];
    rep2(i,2,n+1){
        cin>>a[i];add(i,a[i]);
    }
    pair<ll,int> p[N];
    rep(i,n+1){
        p[i].first=sum(i+1);
        p[i].second=i+1;
    }
    sort(p,p+(n+1),greater<pair<ll,ll>>());
    int r=0,l=0;
    ll ans=0;
    while(r<n+1){
        while((ll)(p[l].first+t)>(ll)p[r].first&&l<n+1){
            add2(p[l].second,1);
            l++;
        }
        ans+=sum2(p[r].second-1);
        r++;
      
    }
    cout<<ans;
}