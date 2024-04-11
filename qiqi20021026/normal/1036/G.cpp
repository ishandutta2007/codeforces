#include<bits/stdc++.h>

using namespace std;

#define N 1200000

int n,m,x,y,s,t,tot,d1[N],d2[N],num[N],head[N],f[30];
bool vis[N];
struct edge{int v,nxt;}e[N];

void add(int x,int y){e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;}

void dfs(int u,int k){
    vis[u]=1;
    if (num[u]) f[num[u]]|=1<<(k-1);
    for (int i=head[u],v;i;i=e[i].nxt)
        if (!vis[v=e[i].v]) dfs(v,k);
}

int main(){
    scanf("%d%d",&n,&m);
    while (m--){
        scanf("%d%d",&x,&y);
        ++d1[x]; ++d2[y];
        add(x,y);
    }
    for (int i=1;i<=n;++i)
        if (!d1[i]) num[i]=++t;
    for (int i=1;i<=n;++i)
        if (!d2[i]){
            memset(vis,0,sizeof vis);
            dfs(i,++s);
        }
    for (int i=1;i<(1<<t)-1;++i){
        int tmp=0,cnt=0;
        for (int j=i;j;j>>=1) cnt+=j&1;
        for (int j=1;j<=t;++j) if (i>>(j-1)&1) tmp|=f[j];
        for (;tmp;tmp>>=1) cnt-=tmp&1;
        if (cnt>=0){puts("NO"); return 0;}
    }
    puts("YES");

    return 0;
}