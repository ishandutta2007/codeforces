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
    if(n==1){
        int a;cin>>a;cout<<a;return 0;
    }
    int count=0;
    ll ans=0;
    int a[N];
    rep(i,n){
        scanf("%d",&a[i]);
        if(a[i]>0){
            count++;ans+=a[i];
        }
        else ans-=a[i];
    }
    if(count==0){
        int m=-INF;
        rep(i,n){
            m=max(m,a[i]);
        }
        ans+=2*m;
    }
    else if(count==n){
        int m=INF;
        rep(i,n)m=min(m,a[i]);
        ans-=m*2;
    }
    cout<<ans;
    return 0;

}