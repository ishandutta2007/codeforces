#include<bits/stdc++.h>
using namespace std;

int x,Q,l,r,mid,ans,n,po[1000010][2],f[1000010],q[1000010],d[1000010],id[1000010],g[21][2000010],p[1000010],dep[1000010],lo[2000010],seq[2000010],cnt;
vector<int> v[1000010];

bool cmp(int a,int b) {return f[a]>f[b];}

void dfs(int x,int fa)
{
    seq[++cnt]=x,p[x]=cnt;
    for (int i=0,sz=v[x].size(); i<sz; i++)
        if (v[x][i]!=fa) dep[v[x][i]]=dep[x]+1,dfs(v[x][i],x),seq[++cnt]=x;
}

int dis(int x,int y)
{
    int nw=dep[x]+dep[y];
    x=p[x],y=p[y];
    if (x>y) swap(x,y);
    int len=lo[y-x+1];
    return nw-2*min(g[len][x],g[len][y-(1<<len)+1]);
}

int main()
{
    lo[1]=0;
    for (int i=2; i<=2000000; i++) lo[i]=lo[i>>1]+1;
    scanf("%d",&n);
    for (int i=2; i<=n; i++) scanf("%d",&x),v[x].push_back(i),v[i].push_back(x),d[i]++,d[x]++;
    cnt=0,dep[1]=0,dfs(1,0);
    for (int i=1; i<=cnt; i++) g[0][i]=dep[seq[i]];
    for (int j=1; j<=20; j++)
        for (int i=1; i+(1<<j)-1<=cnt; i++)
            g[j][i]=min(g[j-1][i],g[j-1][i+(1<<j-1)]);
    memset(f,-1,sizeof(f)),l=1,r=0;
    for (int i=1; i<=n; i++) if (d[i]==1) f[i]=0,q[++r]=i;
    while (l<=r)
    {
        x=q[l++];
        for (int i=0,sz=v[x].size(); i<sz; i++)
            if (f[v[x][i]]==-1) f[v[x][i]]=f[x]+1,q[++r]=v[x][i];
    }
    for (int i=1; i<=n; i++) id[i]=i;
    sort(id+1,id+1+n,cmp);
    po[n+1][0]=po[n+1][1]=-1;
    for (int i=n,t=0,la=-1; i>=0; i--)
    {
        po[i][0]=po[i+1][0],po[i][1]=po[i+1][1];
        while (t<n&&f[id[t+1]]==i)
        {
            x=id[++t];
            if (po[i][0]==-1) po[i][0]=po[i][1]=x,la=0; else
            {
                int d1=dis(po[i][0],x),d2=dis(po[i][1],x);
                if (max(d1,d2)>la) 
                {
                    la=max(d1,d2);
                    po[i][d1>d2]=x;
                }
            }
        }
    }
    scanf("%d",&Q);
    while (Q--)
    {
        scanf("%d",&x);
        l=1,r=n,ans=-1;
        while (l<=r)
        {
            int mid=(l+r)>>1;
            bool che=0;
            for (int i=1; i<=n; i++)
            {
                int d=max(mid-x-f[i],0);
                if (po[d][0]!=-1)
                {
                    if (dis(po[d][0],i)>=mid) {che=1; break;}
                    if (dis(po[d][1],i)>=mid) {che=1; break;}
                }
            }
            if (che) ans=mid,l=mid+1; else r=mid-1;
        }
        printf("%d ",ans);
    }
    return 0;
}