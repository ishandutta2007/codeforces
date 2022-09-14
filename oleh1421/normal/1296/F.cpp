#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007ll;
#define endl '\n'
const int N=5010;
vector<int>g[N];
int p[N];
int tin[N];
int tout[N];
int timer=0;
void dfs(int v,int pr){
    p[v]=pr;
    tin[v]=++timer;
    for (auto to:g[v]){
        if (to==pr) continue;
        dfs(to,v);
    }
    tout[v]=timer;
}
bool upper(int a,int b){
    return (tin[a]<=tin[b] && tout[a]>=tout[b]);
}
vector<int> get(int x,int y){
    vector<int>v;
    while (!upper(x,y)){
        v.push_back(x);
        x=p[x];
    }
    while (!upper(y,x)){
        v.push_back(y);
        y=p[y];
    }
    return v;
}
map<pair<int,int>,int >mp;
vector<int>a[N];
int d[N];
int f[N];
int ans[N];
int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for (int i=1;i<n;i++){
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        mp[{x,y}]=i;
        mp[{y,x}]=i;
    }
    tin[0]=0;
    dfs(1,0);
    tout[0]=timer;
    int m;cin>>m;
    for (int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        a[i]=get(x,y);
        cin>>d[i];
    }
    for (int i=1;i<=n;i++) f[i]=1;
    for (int i=1;i<=m;i++){
        for (auto v:a[i]) f[v]=max(f[v],d[i]);
    }
    for (int i=1;i<=m;i++){
        int minx=100000001;
        for (auto v:a[i]) minx=min(minx,f[v]);
        if (minx!=d[i]){
            cout<<-1;
            return 0;
        }
    }
    for (int i=2;i<=n;i++) ans[mp[{p[i],i}]]=f[i];
    for (int i=1;i<n;i++) cout<<ans[i]<<" ";
    return 0;
}