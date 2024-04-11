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
#define N 810000 
#define M 300000
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");
int par[N],grade[N];
void init(int n){
    rep(i,n){
        par[i]=i;
        grade[i]=0;
    }
}
int root(int x){
    return par[x]==x?x:par[x]=root(par[x]);
}
bool same(int x,int y){
    return root(x)==root(y);
}
void unite(int x,int y){
    x=root(x); y=root(y);
    if(x==y)return;
    if(grade[x]<grade[y]){
        par[x]=y;
    }
    else{
        par[y]=x;
        if(grade[x]==grade[y]) grade[x]++;
    }
}

main(){
    int n,m,q;cin>>n>>m>>q;
    init(N);
    int ans=n+m-1;
    rep(i,q){
        int x,y;cin>>x>>y;
        y+=M;
        if(same(x,y)) continue;
        ans--;
        unite(x,y);
    }
    cout<<ans;
    return 0;
}