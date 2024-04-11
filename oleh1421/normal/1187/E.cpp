#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int sz[300001];
vector<int>g[300001];
void dfs(int v,int pr){
     sz[v]=1;
     for (auto to:g[v]){
        if (to==pr) continue;
         dfs(to,v);
         sz[v]+=sz[to];
     }
}
int n;
ll f(int rt){
   dfs(rt,0);
   ll cur=0ll;
   for (int i=1;i<=n;i++){
       cur+=sz[i]*1ll;;
   }
   return cur;
}
int h[300001];
int h1[300001];
int p[300001];
void dfs1(int v,int cur,int pr){
      h1[v]=cur;
      p[v]=pr;
      for (auto to:g[v]){
           if (to==pr) continue;
           dfs1(to,cur+1,v);
      }
}
bool used[300001];
int sz1[300001];
int dp[300001];
ll x=0;
void dfs2(int v,int pr,ll cur){
     if (pr && g[v].size()==1){
        x=max(x*1ll,cur*1ll+n*1ll-1ll);
        return;
     }
     for (auto to:g[v]){
         if (to!=pr){
            dfs2(to,v,cur*1ll+(n-sz[v]-sz[to])*1ll);
         }
     }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for (int i=1;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(1,1,0);
    ll res=f(1);
    vector<int>v;
    for (int i=2;i<=n;i++) if (g[i].size()==1) v.push_back(i);
    dfs2(1,0,0);
    /*ll maxx=0ll;
    int cnt=0;
    for (auto i:v){

        int cur=i;
        vector<int>pass={i};
        while (p[cur]){
            cur=p[cur];
            pass.push_back(cur);
        }
        pass.pop_back();
        ll x=n-1;
        for (int j=1;j<pass.size();j++){
            int v=pass[j];
            int last=pass[j-1];
            x+=(n-sz[v]-sz[last]);
        }
        x-=sz[pass.back()];
        maxx=max(maxx,x);
    }*/
    cout<<res+x<<endl;
    return 0;
}