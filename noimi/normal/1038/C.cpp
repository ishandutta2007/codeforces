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
    int a[N],b[N];
    rep(i,n){
        cin>>a[i];
    }
    rep(i,n){
        cin>>b[i];
    }
    sort(a,a+n);sort(b,b+n);
    ll ans=0;
    int p1=n-1,p2=n-1;
    rep(i,n){
        if(p1==-1)p2--;
        else if(p2==-1){
            ans+=a[p1];p1--;
        }
        else if(a[p1]>b[p2]){
            ans+=a[p1];
            p1--;
        }
        else if(a[p1]<=b[p2]){
            p2--;
        }
        if(p1==-1){
            ans-=b[p2];p2--;
            
        }
        else if(p2==-1)p1--;
        else if(a[p1]>b[p2])p1--;
        else if(a[p1]<=b[p2]){
            ans-=b[p2];p2--;
        }
    }
    cout<<ans;
    return 0;

}