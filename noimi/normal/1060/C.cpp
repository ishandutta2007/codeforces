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
ll MOD=1e9+7;
#define INF 2*1e9
#define N 3000
#define MAX_V 900010
#define vec vector<int>
using namespace std;

void print(ll x){
    printf("%lld",&x);return;
}

int sum(ll n){
    int res=0;
    while(n){
        res+=n%10;
        n/=10;
    }
    return res;
}
main(){
    int n,m;cin>>n>>m;
    ll a[N],b[N],x;
    rep2(i,1,n)cin>>a[i];
    rep2(i,1,m)cin>>b[i];
    cin>>x;
    ll sa[N],sb[N];
    sa[0]=sb[0]=0;
    rep2(i,1,max(n,m)){
        sa[i]=sa[i-1]+a[i];
        sb[i]=sb[i-1]+b[i];
    }
    ll ma[N],mb[N];
    rep2(i,1,n){
        ll M=1e17;
        rep2(j,1,n+1-i){
            M=min(M,sa[j+i-1]-sa[j-1]);
        }
        ma[i]=M;
    }
    rep2(i,1,m){
        ll M=1e17;
        rep2(j,1,m+1-i){
            M=min(M,sb[j+i-1]-sb[j-1]);
        }
        mb[i]=M;
    }
    int ans=0;
    rep2(i,1,n){
        int h=m;
        while(mb[h]*ma[i]>x&&h){
            h--;
        }
        ans=max(ans,h*i);
    }
    cout<<ans;
}