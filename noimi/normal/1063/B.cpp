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
#define INF 1e9+7
#define N 1100000
#define MAX_V 900010
#define vec vector<int>
using namespace std;
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
#define umap unordered_map<ll,int,custom_hash>
struct querry{
    int xx,yy,pp,qqq;
};
int visited[2100][2100];
pii t[2100][2100];
int a[2100][2100];
queue<querry> q1;
void dfs(querry qq){
    int x=qq.xx,y=qq.yy,p=qq.pp,q=qq.qqq;
    if(!a[p][q])return;
    visited[p][q]=1;
    if(t[p][q].first>=x&&t[p][q].second>=y)return;
    else{
        if(t[p][q].first<=x&&t[p][q].second<=y)
        t[p][q]={x,y};
        if(x&&q)q1.push(querry{x-1,y,p,q-1});
        if(p)q1.push(querry{x,y,p-1,q});
        q1.push(querry{x,y,p+1,q});
        if(y)q1.push(querry{x,y-1,p,q+1});
    }
}

main(){
    rep(i,2010)rep(j,2010)t[i][j]={-1,-1};
    int n,m;
    cin>>n>>m;
    int r,c;cin>>r>>c;
    int x,y;cin>>x>>y;

    rep(i,n)rep(j,m){
        char c;cin>>c;
        if(c=='*')a[i][j]=0;
        else a[i][j]=1;
    }
    q1.push({x,y,r-1,c-1});
    while(!q1.empty()){
        dfs(q1.front());
        q1.pop();
    }
    int ans=0;
    rep(i,n)rep(j,m)
        ans+=visited[i][j];
    cout<<ans;
}