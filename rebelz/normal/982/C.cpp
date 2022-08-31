#include<iostream>

using namespace std;

int n,tot=0;
int size[100005],d[100005],v[200005],nxt[200005],h[100005];

void addedge(int x,int y){
    v[++tot]=y; nxt[tot]=h[x]; h[x]=tot;
    v[++tot]=x; nxt[tot]=h[y]; h[y]=tot;
}

void dfs1(int u,int fa){
    size[u]=1;
    for(int p=h[u];p;p=nxt[p]){
        if(v[p]==fa)
            continue;
        dfs1(v[p],u);
        size[u]+=size[v[p]];
    }
}

void dfs2(int u,int fa){
    for(int p=h[u];p;p=nxt[p]){
        if(v[p]==fa)
            continue;
        dfs2(v[p],u);
        d[u]+=d[v[p]];
    }
    if(size[u]%2==0)
        d[u]++;
}

int main(){
    cin>>n;
    int x,y;
    for(int i=1;i<=n-1;i++){
        cin>>x>>y;
        addedge(x,y);
    }
    if(n%2==1){
        cout<<-1<<endl;
        return 0;
    }
    dfs1(1,-1);
    dfs2(1,-1);
    cout<<d[1]-1<<endl;
    return 0;
}