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
#define N 310000
#define MAX_V 900010
#define vec vector<int>
using namespace std;

void print(ll x){
    printf("%lld",&x);return;
}
ll a[N][3];
vector<int> G[N];
ll sum;
void dfs(int t,int s){
    ll p=0,q=0,r=0,one=0,two=0;
    ll f=0;
    rep(i,G[t].size()){
        if(G[t][i]==s)continue;
        dfs(G[t][i],t);
        f+=q*(a[G[t][i]][0]+1)+p*(a[G[t][i]][0]+1+a[G[t][i]][1]);
        f+=(r*a[G[t][i]][2]+(p-r)*(a[G[t][i]][0]-a[G[t][i]][2]+1));
        p+=a[G[t][i]][0]+1;
        q+=a[G[t][i]][1]+a[G[t][i]][0]+1;
        r+=a[G[t][i]][0]-a[G[t][i]][2]+1;
    }
    a[t][0]=p;
    a[t][1]=q;
    a[t][2]=r;
    sum+=f;
}
main(){
    int n;cin>>n;
    ll ans=0;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        G[a].pb(b);G[b].pb(a);
    }
    dfs(1,0);
    rep2(i,1,n){
        ans+=a[i][2]+a[i][1];
    }
    cout<<(ans+sum)/2;
}