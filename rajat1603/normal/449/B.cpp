#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
vector<vector<pair<int,int> > > v;
int n,m,k,M,K,c=1,parent[100005];
long long edge[400010],d[100005];
bool used[400010]={0};
int main(){
    scanf("%d%d%d",&n,&m,&k);
    v.resize(n+10);
    M=m;
    K=k;
    while(m--){
        int x,y;
        long long w;
        scanf("%d%d%I64d",&x,&y,&w);
        v[x].pb(mp(y,c));
        v[y].pb(mp(x,c));
        edge[c++]=w;
    }
    while(k--){
        int x;
        long long y;
        scanf("%d%I64d",&x,&y);
        v[1].pb(mp(x,c));
        v[x].pb(mp(1,c));
        edge[c++]=y;
    }
    for(int i=1;i<=n;d[i++]=999999999999999LL);
    d[1]=0;
    priority_queue<pair<long long,int> > q;
    q.push(mp(0,1));
    memset(parent,-1,sizeof(parent));
    while(!q.empty()){
        int node=q.top().second;
        long long w = -q.top().first;
        q.pop();
        if(w>d[node])continue;
        int x=v[node].size();
        for(int i=0;i<x;i++){
            int next=v[node][i].first;
            int e = v[node][i].second;
            if(d[next]>w+edge[e]){
                parent[next]=e;
                d[next]=w+edge[e];
                q.push(mp(-d[next],next));
            }
            else if(d[next]==w+edge[e]){
                if(e<=M){
                    parent[next]=e;
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(parent[i]!=-1){
            used[parent[i]]=1;
        }
    }
    int ans=0;
    for(int i=M+1;i<=M+K;i++){
        if(!used[i]){
            ans++;
        }
    }
    printf("%d",ans);
}