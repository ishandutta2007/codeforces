#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
struct edge
{
    int v,w,nxt;
}e[2000005];
struct edge1
{
    int u,v;
    edge1(int u=0,int v=0):u(u),v(v){}
}e1[2000005];
int n,m=6,h[500005],dis[500005],cur[500005],q[500005],mp[15][15],head,tail,s,t,tp=0,tot=1,tt=0,et=0,cnt[15];
int fr[15],idm[15][15],idt[15][15][2];
edge1 tans[500005][7];
int add(int u,int v,int w)
{
	//if(w!=99999999) printf("%d %d %d\n",u,v,w);
	//else printf("%d %d -1\n",u,v);
    e[++tot].v=v;
    e[tot].w=w;
    e[tot].nxt=h[u];
    h[u]=tot;
    e[++tot].v=u;
    e[tot].w=0;
    e[tot].nxt=h[v];
    h[v]=tot;
    return tot-1;
}
bool bfs()
{
    for(int i=1;i<=tp;i++)
        dis[i]=0;
    head=0,tail=1;
    q[1]=s;
    dis[s]=1;
    while(head<tail)
    {
        head++;
        int u=q[head];
        //printf("u=%d\n",u);
        for(int i=h[u];i;i=e[i].nxt)
        {
            int v=e[i].v,w=e[i].w;
            if(!w||dis[v]) continue;
            dis[v]=dis[u]+1;
            q[++tail]=v;
        }
    }
    return dis[t];
}
int dfs(int u,int flow)
{
    if(u==t) return flow;
    int ans=0,nw;
    for(int i=cur[u];i;i=e[i].nxt)
    {
        int v=e[i].v,w=e[i].w;
        if(!w||dis[v]!=dis[u]+1) continue;
        if(flow==ans) break;
        nw=dfs(v,min(w,flow-ans));
        ans+=nw;
        e[i].w-=nw;
        e[i^1].w+=nw;
        cur[u]=i;
    }
    return ans;
}
int dinic()
{
    int ans=0;
    while(bfs())
    {
        for(int i=1;i<=tp;i++)
            cur[i]=h[i];
        ans+=dfs(s,99999999);
    }
     ///   printf("dinic:ans=%d\n",ans);
    return ans;
}
edge1 a[15];
int vvis[105];
void check()
{
    for(int i=1;i<=m;i++)
        vvis[i]=0;
    head=0,tail=1;
    q[1]=1;
    vvis[1]=1;
    while(head<tail)
    {
        head++;
        int u=q[head];
        for(int i=1;i<m;i++)
        {
            int nwu=a[i].u,nwv=a[i].v;
            if(nwv==u) swap(nwu,nwv);
            if(vvis[nwv]) continue;
            if(nwu!=u) continue;
            vvis[nwv]=1;
            q[++tail]=nwv;
        }
    }
    if(tail==m)
    {
        tt++;
        for(int i=1;i<m;i++)
        {
            tans[tt][i]=a[i];
            //printf("tt=%d,u=%d,v=%d\n",tt,a[i].u,a[i].v);
		}
    }
}
void cfs(int x,int y,int dep)
{
	//printf("x=%d,y=%d,dep=%d\n",x,y,dep);
    if(dep>m) return;
    if(x==m&&dep!=m) return;
    if(x==m)
    {
        check();
        return;
    } 
    int xx=x,yy=y+1;
    if(yy>m)
    {
        xx++;
        yy=xx+1;
    }
    cfs(xx,yy,dep);
    if(mp[x][y])
    {
        a[dep]=edge1(x,y);
        cfs(xx,yy,dep+1);
    }
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
    scanf("%d",&n);
    int nw=1;
    m=0;
    while(nw<=n) nw*=10,m++;
    for(int i=1;i<n;i++)
    {
        int ch=getchar(),u=0,v=0;
        while(isspace(ch)) ch=getchar();
        while(!isspace(ch)) u++,ch=getchar();
        while(isspace(ch)) ch=getchar();
        while(!isspace(ch)) v++,ch=getchar();
        if(u>v) swap(u,v);
        //printf("u=%d,v=%d\n",u,v);
        mp[u][v]++;
    }
    cnt[1]=2;
    fr[1]=1;
    for(int i=2;i<=m+1;i++)
    {
        cnt[i]=(cnt[i-1]-1)*10+1;
        fr[i]=cnt[i]-1;
    }
    for(int i=1;i<=m;i++)
        if(mp[i][i])
        {
            for(int j=1;j<=mp[i][i];j++)
            {
                e1[++et].u=fr[i];
                e1[et].v=cnt[i];
                cnt[i]++;
                //printf("i=%d,j=%d,cnt=%d\n",i,j,cnt[i]);
                if(cnt[i]>=min(fr[i+1],n+1)+1)
                {
                    printf("-1");
                    return 0;
                }
            }
        }
    int net=et;
    cfs(1,2,1);
    //printf("------\n");
    for(int i=1;i<=tt;i++)
    {
        et=net;
        for(int j=1;j<=m-1;j++)
        {
            mp[tans[i][j].u][tans[i][j].v]--;
            e1[++et].u=fr[tans[i][j].u];
            e1[et].v=fr[tans[i][j].v];
        }
        for(int j=1;j<=tp;j++)
            h[j]=0;
        tot=1;tp=m;
        int sum=0;
        for(int j=1;j<=m;j++)
            for(int k=j+1;k<=m;k++)
            {
                tp++;
                idm[j][k]=tp;
                idt[j][k][0]=add(j,tp,99999999);
                idt[j][k][1]=add(k,tp,99999999);
            }
        s=++tp;
        t=++tp;
        for(int j=1;j<=m;j++)
        {
            add(s,j,min(fr[j+1],n+1)-cnt[j]);
            //printf("j=%d,cnt=%d\n",j,min(fr[j+1],n)-cnt[j]+1);
		}
		for(int j=1;j<=m;j++)
            for(int k=j+1;k<=m;k++)
            	add(idm[j][k],t,mp[j][k]),sum+=mp[j][k];
        if(dinic()==sum)
        {
        	//printf("b---\n");
        	for(int j=1;j<=m;j++)
        		for(int k=j+1;k<=m;k++)
        		{
        			int u=idt[j][k][0]^1,w;
        			w=e[u].w;
        			//printf("j=%d,k=%d,w=%d,",j,k,w);
        			//printf("w=%d\n",w);
        			for(int l=1;l<=w;l++)
        			{
        				e1[++et].u=fr[k];
        				e1[et].v=cnt[j];
        				cnt[j]++;
					}
					u=idt[j][k][1]^1;
        			w=e[u].w;
        			//printf("%d\n",w);
        			for(int l=1;l<=w;l++)
        			{
        				e1[++et].u=fr[j];
        				e1[et].v=cnt[k];
        				cnt[k]++;
					}
        			//printf("w=%d\n",w);
				}
        	//printf("e---\n");
        	/*for(int i=1;i<=m;i++)
        	{
        		printf("cnt[%d]=%d\n",i,cnt[i]);
			}*/
			for(int i=1;i<=et;i++)
			{
				printf("%d %d\n",e1[i].u,e1[i].v);
			}
			return 0;
		}
        for(int j=1;j<=m-1;j++)
            mp[tans[i][j].u][tans[i][j].v]++;
    }
    printf("-1");
	return 0;
}