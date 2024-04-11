#include<bits/stdc++.h>

using namespace std;

#define N 1200

int n,mn,a[N];
long long ans;

map<int,int> vis,pre,lst,nxt;

void dfs(int u){
    vis[u]=1;
    for (int v=u;v<=mn;v+=u){
        if (!pre.count(v)){
            mn=min(mn,v);
            lst[v]=u;
            return;
        }
        else if (!vis[pre[v]]){
            nxt[pre[v]]=v;
            lst[v]=u;
            dfs(pre[v]);
        }
    }
}

void match(int x){
    vis.clear();
    nxt.clear();
    mn=1000000*(n+1);
    dfs(x);
    ans+=mn;
    for (int u=mn;u;u=nxt[lst[u]]){
        pre[u]=lst[u];
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    for (int i=1;i<=n;++i) match(a[i]);
    cout<<ans<<'\n';
    
    return 0;
}