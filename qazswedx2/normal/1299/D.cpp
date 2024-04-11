#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge
{
	int v,w,vis,nxt;
}e[500005];
struct pt
{
	int val[5],ans;
	//int nxt;
	pt(){memset(val,0,sizeof(val)),ans=0;}
	bool operator==(const pt x) const
	{
		for(int i=0;i<=4;i++)
			if(val[i]!=x.val[i])
				return 0;
		return 1;
	}
}p[2][3000005];
const int mod=1e9+7;
int f[2][33][17][9][5][2],tvis[2][33][17][9][5][2],ct[2],nw;
int n,m,h[100005],t=1,d[100005],a[105],b[100005][6],bt,vis[100005],fl;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
/*inline int gethsh(pt x)
{
	int ans=0;
	for(int i=0;i<=4;i++)
		ans=(ans*bs+x.val[i])%md;
	return ans;
}*/
void tins(pt x,int w)
{
	///printf("tins:w=%d\n",w);
//	printf("%d %d %d %d %d\n",x.val[0],x.val[1],x.val[2],x.val[3],x.val[4]);
	int &y=f[nw][x.val[4]][x.val[3]][x.val[2]][x.val[1]][x.val[0]];
	int &v=tvis[nw][x.val[4]][x.val[3]][x.val[2]][x.val[1]][x.val[0]];
	y=addmod(y+w);
	if(!v)
	{
		p[nw][++ct[nw]]=x;
		p[nw][ct[nw]].ans=w;
		v=ct[nw];
	}
	else
	{
		p[nw][v].ans=y;
	}
}
void clr()
{
	for(int i=1;i<=ct[nw];i++)
	{
		pt x=p[nw][i];
		f[nw][x.val[4]][x.val[3]][x.val[2]][x.val[1]][x.val[0]]=0;
		tvis[nw][x.val[4]][x.val[3]][x.val[2]][x.val[1]][x.val[0]]=0;
	}
}
int ins(int u,int *a)
{
	for(int i=4;i>=0;i--)
		if(u&(1<<i))
		{
			if(a[i]==0)
			{
				a[i]=u;
				for(int j=i-1;j>=0;j--)
					if((a[i]&(1<<j))&&a[j])
						a[i]^=a[j];
				for(int j=i+1;j<=4;j++)
					if(a[j]&(1<<i))
						a[j]^=a[i];
				return 1;
			}
			else u^=a[i];
		}
	return 0;
}
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
}
void dfs(int u,int fa,int dep)
{
	d[u]=dep;
	vis[u]=1;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa) continue;
		if(e[i].vis) continue;
		if(vis[v])
		{
			int nw=d[u]^d[v]^e[i].w;
		//	printf("u=%d,v=%d,nw=%d\n",u,v,nw);
			if(v==1) b[bt][0]=nw;
			else
			{
				if(!ins(nw,a))
				{
					fl=0;
				//	return;
				}
			}
			e[i].vis=e[i^1].vis=1;
			continue;
		}
		dfs(v,u,dep^e[i].w);
		//if(!fl) return;
	}
}
int main()
{
//	freopen("CF1299.in","r",stdin);
	//freopen("CF1299.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	vis[1]=1;
	for(int i=h[1];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(e[i].vis) continue;
		++bt;
		b[bt][0]=-1;
		fl=1;
		for(int i=0;i<=4;i++)
			a[i]=0;
		dfs(v,1,e[i].w);
		if(!fl)
		{
			bt--;
			continue;
		}
		for(int i=0;i<=4;i++)
			b[bt][i+1]=a[i];
	}
/*	for(int i=1;i<=bt;i++)
	{
		for(int j=0;j<=5;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}*/
	nw=0;
	pt ft;
	tins(ft,1);
	for(int i=1;i<=bt;i++)
	{
		nw^=1;
		clr();
		ct[nw]=0;
		//printf("i=%d\n",i);
		for(int j=1;j<=ct[nw^1];j++)
		{
			pt x=p[nw^1][j];
			tins(x,x.ans);
			if(b[i][0]==-1)
			{
				int fl=1;
				for(int k=0;k<=4;k++)
					if(b[i][k+1])
					{
						if(!ins(b[i][k+1],x.val))
							fl=0;
					}
				if(!fl) continue;
				tins(x,x.ans);
			}
			else
			{
				int fl=1;
				for(int k=0;k<=4;k++)
					if(b[i][k+1])
					{
						if(!ins(b[i][k+1],x.val))
							fl=0;
					}
				if(!fl) continue;
				tins(x,2*x.ans%mod);
				//printf("----");
				if(ins(b[i][0],x.val))
					tins(x,x.ans);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=ct[nw];i++)
		ans=addmod(ans+p[nw][i].ans);
	printf("%d",ans);
	return 0;
}