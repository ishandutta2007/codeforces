#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
#define int long long
using namespace std;
vector<int>g[200001];
int tin[200001];
int fup[200001];
int timer=0;
bool used[200001];
bool used1[200001];
int w[200001];
bool ok[200001];
void dfs(int v,int pr){
     used[v]=true;
     for (auto to:g[v]){
         if (to==pr) continue;
         if (used[to]) ok[v]=true;
         else {
            dfs(to,v);
            ok[v]|=ok[to];
         }
     }
}
int dfs_get(int v){
    int maxx=0;
    used1[v]=true;
    for (auto to:g[v]){
        if (!used1[to]) maxx=max(maxx,dfs_get(to));
    }
    return maxx+w[v];
}
int sum=0;
int maxx=0;
void dfs1(int v){
     used1[v]=true;
     if (ok[v]){
        sum+=w[v];
        for (auto to:g[v]){
            if (!used1[to]) dfs1(to);
        }
        return;
     }
     maxx=max(maxx,dfs_get(v));
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>w[i];
    vector<pair<int,int> >q;
    for (int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        q.push_back({a,b});
    }
    int s;cin>>s;
    dfs(s,0);
    dfs1(s);
    cout<<sum+maxx;
    return 0;
}