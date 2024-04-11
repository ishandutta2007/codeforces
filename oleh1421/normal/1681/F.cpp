#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=500010;
const int Lg=20;
const ll mod=998244353;
const ll inv2=(mod+1)/2;
vector<pair<int,int> >g[N];
ll val[N];
map<int,int>mp[N];
int sz[N];
void dfs(int v,int pr,int x){
    sz[v]=1;
    for (auto cur:g[v]){
        int to=cur.first;
        if (to==pr) continue;
        dfs(to,v,cur.second);
        sz[v]+=sz[to];
        if (mp[to].size()>mp[v].size()) mp[v].swap(mp[to]);
        for (auto tp:mp[to]){
            mp[v][tp.first]+=tp.second;
        }
    }
    val[v]=sz[v]-mp[v][x];
    mp[v][x]=sz[v];
//    cout<<v<<" "<<val[v]<<endl;
}
int last[N];
ll ans[N];
void dfs1(int v,int pr,int x){
    int u=last[x];
    if (u==1){
        ans[v]=val[v]*(sz[1]-mp[1][x]);
    } else {
        ans[v]=val[v]*val[u];
    }
    last[x]=v;
    for (auto cur:g[v]){
        if (cur.first==pr) continue;
        dfs1(cur.first,v,cur.second);
    }
    last[x]=u;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int a,b,x;cin>>a>>b>>x;
        g[a].push_back({b,x});
        g[b].push_back({a,x});
    }
    dfs(1,0,0);
    for (int i=1;i<=n;i++) last[i]=1;
    for (auto cur:g[1]){
        dfs1(cur.first,1,cur.second);
    }
    ll res=0ll;
    for (int i=2;i<=n;i++){
        res+=ans[i];
    }
    cout<<res<<endl;

    return 0;
}
/*
3
1 5
2 6
3 4
*/