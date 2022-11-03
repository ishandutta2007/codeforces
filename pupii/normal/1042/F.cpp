#include<bits/stdc++.h>
#define il inline
#define vd void
#define int long long
#define ll long long
il int gi(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x*f;
}
int fir[2000010],dis[4000010],nxt[4000010],id;
il vd link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int n,k,f[2000010],g[2000010],ans; 
il vd dfs(int x,int fa=-1){
    f[x]=1e18,g[x]=(nxt[fir[x]]==0?0:-1e18);
    for(int i=fir[x];i;i=nxt[i]){
        if(dis[i]==fa)continue;
        dfs(dis[i],x);
        if(f[dis[i]]+g[x]<k)g[x]=-1e18;
        if(f[x]+g[dis[i]]>=k)g[x]=std::max(g[x],g[dis[i]]+1);
        f[x]=std::min(f[x],f[dis[i]]+1);
    }
    if(g[x]>=k)f[x]=0,++ans;
    if(f[x]+g[x]<=k)g[x]=-1e18;
}
main(){
    n=gi(),k=gi();
    int a,b;
    for(int i=1;i<n;++i)a=gi(),b=gi(),link(a,i+n),link(i+n,a),link(i+n,b),link(b,i+n);
    dfs(1);
    printf("%lld\n",ans+(f[1]+g[1]>k));
    return 0;
}