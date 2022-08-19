#include<iostream>
#include<stdio.h>

using namespace std;

int n,tot=0;
int v[200005],nxt[200005],h[100005],dep[100005];

void addedge(int x,int y){
    v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
    v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs(int u,int fa){
    for(int p=h[u];p;p=nxt[p]){
        if(v[p]==fa)
            continue;
        dep[v[p]]=dep[u]+1;
        dfs(v[p],u);
    }
}

int main(){
    cin>>n;
    int x,y;
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
        addedge(x,y);
    }
    dep[1]=1;
    dfs(1,-1);
    double ans=0;
    for(int i=1;i<=n;i++)
        ans+=1.0/dep[i];
    printf("%.10lf\n",ans);
    return 0;
}