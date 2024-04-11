#include<bits/stdc++.h>

using namespace std;

#define N 300000
#define INF 0x3f3f3f3f

int n,m,l,r,mid,ans,ans1,ans2,tmp1,tmp2,tmp,p1,p2,rt,x,y,z,lim,sz[N],f[N],g[N],q[N],qq[N][4],mx[N],deep[N];
bool vis[N];
struct edge{
    int v,l;
    bool operator < (const edge ee){return deep[v]<deep[ee.v];}
};
vector<edge> e[N];

int getint(){
    char ch; int sum=0,fh=1;
    for (ch=getchar();ch<'0' || ch>'9';ch=getchar()) fh=ch=='-'?-1:1;
    for (;ch>='0' && ch<='9';ch=getchar()) sum=sum*10+ch-'0';
    return sum*fh;
}

void add(int x,int y,int z){e[x].push_back((edge){y,z});}

void getdeep(int u,int fa){
    sz[u]=1; deep[u]=1;
    for (int i=0,v;i<(int)e[u].size();i++) if (!vis[v=e[u][i].v] && v!=fa){getdeep(v,u); sz[u]+=sz[v];}
    for (int i=0,v;i<(int)e[u].size();i++) if (!vis[v=e[u][i].v]) deep[u]=max(deep[u],deep[v]+1);
}

void getroot(int u,int fa,int sum){
    mx[u]=0;
    for (int i=0,v;i<(int)e[u].size();i++)
        if (!vis[v=e[u][i].v] && v!=fa){getroot(v,u,sum); mx[u]=max(mx[u],sz[v]);}
    for (int i=0;i<(int)e[u].size();i++) deep[u]=max(deep[u],deep[e[u][i].v]);
    mx[u]=max(mx[u],sum-sz[u]);
    if (mx[u]<mx[rt]) rt=u;
}

void getmx(int u,int val){
    int tt=0,ww=1; qq[1][0]=u; qq[1][1]=0; qq[1][2]=1; qq[1][3]=val;
    int t=1,w=0; int i; for (i=lim;i>=p1;i--){while (f[i]>f[q[w]] && t<=w) w--; q[++w]=i;}
    while (tt<ww){
        int u=qq[++tt][0],fa=qq[tt][1],len=qq[tt][2],val=qq[tt][3];
        if (len>p2) break;
        if (t<=w && q[t]+len>p2) t++;
        while (i+len>=p1 && i>=0){while (t<=w && f[i]>f[q[w]]) w--; q[++w]=i; i--;}
        //cout<<len<<' '<<t<<' '<<w<<' '<<q[t]<<endl;
        if (t<=w) tmp=max(tmp,val+f[q[t]]); if (tmp>=0){tmp1=u; tmp2=g[q[t]]; return;}
        for (int i=0,v;i<(int)e[u].size();i++)
            if (!vis[v=e[u][i].v] && v!=fa){qq[++ww][0]=v; qq[ww][1]=u; qq[ww][2]=len+1; qq[ww][3]=val+(e[u][i].l>=mid?1:-1);}
    }
}

void update(int u,int fa,int len,int val){
    if (len>p2) return;
    if (val>f[len]){f[len]=val; g[len]=u;}
    for (int i=0,v;i<(int)e[u].size();i++)
        if (!vis[v=e[u][i].v] && v!=fa) update(v,u,len+1,val+(e[u][i].l>=mid?1:-1));
}

void solve(int u){// cout<<u<<endl;
    vis[u]=1;
    for (int i=0,v;i<(int)e[u].size();i++) if (!vis[v=e[u][i].v]) getdeep(v,0);
    sort(e[u].begin(),e[u].end());
    l=0,r=1000000000;
    while (l<=r){
        f[0]=0; g[0]=u;
        mid=(l+r)>>1; tmp=-INF; lim=0;// cout<<"++++++++++"<<mid<<endl;
        for (int i=0,v;i<(int)e[u].size();i++)
            if (!vis[v=e[u][i].v]){
                getmx(v,e[u][i].l>=mid?1:-1); if (tmp>=0) break;
                update(v,0,1,e[u][i].l>=mid?1:-1); lim=min(deep[v],p2);
            }
        memset(f,0xcf,sizeof(int)*(lim+1));
        if (tmp>=0){l=mid+1; if (mid>ans) ans=mid,ans1=tmp1,ans2=tmp2;} else r=mid-1;
    }
    for (int i=0,v;i<(int)e[u].size();i++)
        if (!vis[v=e[u][i].v]){rt=0; getroot(v,0,sz[v]); solve(rt);}
}

int main(){
    n=getint(); p1=getint(); p2=getint();
    for (int i=1;i<n;i++){
        x=getint(); y=getint(); z=getint();
        add(x,y,z); add(y,x,z);
    }
    memset(f,0xcf,sizeof f); mx[rt=0]=INF;
    ans=-1; getdeep(1,0); getroot(1,0,n); solve(rt);
    printf("%d %d\n",ans1,ans2);

    return 0;
}