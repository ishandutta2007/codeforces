#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int > pp;
int const N=1e6+10,oo=1e9;
int mod=oo+7;
ll const OO=1e18;
int n,m,dep[N],ch[N],ex[N],in[N],pos[N];
vector<int > adj[N],an;
void dfs(int u,int mx){
    if(mx>dep[ch[u]]){
        cout<<"-1\n";
        exit(0);
    }
    mx=max(dep[ch[u]],mx);
    for(auto v:adj[u]){
        dep[v]=dep[u]+1;
        dfs(v,mx);
    }
    if(ex[u]) an.push_back(u);
}
 
void dfs2(int u,int idx){
    if(idx&&idx<pos[ch[u]]){
        cout<<-1<<endl;
        exit(0);
    }
    if(pos[u]){
        if(idx)idx=min(idx,pos[u]);
        else idx=pos[u];
    }
    for(auto v:adj[u])dfs2(v,idx);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        in[b]=1;
    }
    for(int i=1;i<=n;i++){
        cin>>ch[i];
        ex[ch[i]]=1;
    }
    for(int i=1;i<=n;i++) if (!in[i]) dfs(i,-1);
    for(int i=0;i<an.size();i++) pos[an[i]]=i+1;
    for(int i=1;i<=n;i++) if(!in[i]) dfs2(i,0);
    cout<<an.size()<<endl;
    for(auto e:an) cout<<e<<'\n';
}