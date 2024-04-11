#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=998244353;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
int fpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		y/=2;
	}
	return ans;
}
struct pt
{
	int id,val,fl;
	pt(int id=0,int val=0,int fl=0):id(id),val(val),fl(fl){}
	bool operator<(const pt x) const
	{
		return val<x.val;
	}
}p[1000005];
struct edge
{
	int v,nxt;
}e[105];
struct poly
{
	int v[45],len;
	poly(){len=0,memset(v,0,sizeof(v));}
};
poly operator*(poly x,poly y)
{
	poly z;
	z.len=x.len+y.len-1;
	for(int i=0;i<x.len;i++)
		for(int j=0;j<y.len;j++)
			z.v[i+j]=addmod(z.v[i+j]+1ll*x.v[i]*y.v[j]%mod);
	return z;
}
int n,m,h[500005],tot,e2[105][2],t,vis[500005],a[500005],at,e3[105][2],et;
int f[22][3000005],cnt[3000005],ppn=3e6,gid[22][45],gt[22],ctt,visa[500005][2];
int fr[500005],infr[500005],pn=5e5;
poly g[22][45],pans;
void add(int u,int v)
{
	e[++tot].v=v;
	e[tot].nxt=h[u];
	h[u]=tot;
}
void dfs(int u)
{
	vis[u]=1;
	a[++at]=u;
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfs(v);
	}
}
int lim;
void fwt(int *a)
{
/*	printf("fwt:a=");
	for(int i=0;i<lim;i++)
		printf("%d ",a[i]);
	printf("\n");*/
	for(int k=1;k<lim;k<<=1)
		for(int i=0,r=k*2;i<lim;i+=r)
			for(int j=0;j<k;j++)
				a[i+j+k]+=a[i+j];
}
void solve()
{
	sort(a+1,a+at+1);
	for(int i=1;i<=et;i++)
	{
		e3[i][0]=lower_bound(a+1,a+at+1,e3[i][0])-a-1;
		e3[i][1]=lower_bound(a+1,a+at+1,e3[i][1])-a-1;
	}
	for(int j=0;j<=at;j++)
		for(int i=0;i<(1<<at);i++)
			f[j][i]=0;
	for(int i=0;i<(1<<at);i++)
	{
		int fl=1;
		for(int j=1;j<=et;j++)
			if((i&(1<<e3[j][0]))&&(i&(1<<e3[j][1])))
			{
				fl=0;
				break;
			}
		if(fl) f[cnt[i]][i]=1;
	}
	lim=(1<<at);
	for(int i=0;i<=at;i++)
		fwt(f[i]);
	//for(int i=0;i<=at;i++)
	//	for(int j=0;j<(1<<at);j++)
	//		if(i==5&&f[i][j])printf("i=%d,j=%d,f=%d\n",i,j,f[i][j]);
	for(int j=0;j<=gt[ctt];j++)
	{
		int bs=gid[ctt][j];
	//	printf("j=%d,bs=%d\n",j,bs);
		for(int k=0;k<=at;k++)
			g[ctt][j].v[k]=f[k][bs];
		g[ctt][j].len=at+1;
	}
}
inline int C(int x,int y)
{
	if(x<0||y<0||x<y) return 0;
	return 1ll*fr[x]*infr[y]%mod*infr[x-y]%mod;
}
int main()
{
	fr[0]=infr[0]=1;
	for(int i=1;i<=pn;i++)
	{
		fr[i]=1ll*fr[i-1]*i%mod;
		infr[i]=fpow(fr[i],mod-2);
	}
	for(int i=1;i<=ppn;i++)
		cnt[i]=cnt[i/2]+i%2;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		p[++t]=pt(i,l,1);
		p[++t]=pt(i,r+1,-1);
	}
	sort(p+1,p+t+1);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e2[i][0]=u,e2[i][1]=v;
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			at=et=0;
			dfs(i);
			if(at==1) continue;
			ctt++;
			sort(a+1,a+at+1);
			for(int j=1;j<=at;j++)
				visa[a[j]][0]=ctt,visa[a[j]][1]=j;
		}
	int nw=1;
	for(int i=1;i<=n;i++)
	{
		while(nw<=t&&p[nw].val==i)
		{
			if(visa[p[nw].id][0])
			{
				int u=visa[p[nw].id][0],ps=visa[p[nw].id][1];
				gid[u][gt[u]+1]=gid[u][gt[u]]^(1<<(ps-1));
				gt[u]++;
			}
			nw++;
		}
	}
	ctt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			at=et=0;
			dfs(i);
			if(at==1) continue;
			ctt++;
			for(int j=1;j<=m;j++)
				if(visa[e2[j][0]][0]==ctt&&visa[e2[j][1]][0]==ctt)
				{
					e3[++et][0]=e2[j][0];
					e3[et][1]=e2[j][1];
				}
			solve();
		}
	nw=1;
	memset(gt,0,sizeof(gt));
	int cct=0,ans=0;
	pans=poly();
	pans.len=1,pans.v[0]=1;
	for(int i=1;i<=n;i++)
	{
		while(nw<=t&&p[nw].val==i)
		{
			if(visa[p[nw].id][0])
			{
				int u=visa[p[nw].id][0];
				gt[u]++;
				pans=poly();
				pans.len=1,pans.v[0]=1;
		//		printf("u=%d,gt=%d\n",u,gt[u]);
				for(int j=1;j<=ctt;j++)
					pans=pans*g[j][gt[j]];
			}
			else
			{
			//	printf("p[nw].id=%d\n",p[nw].id);
				cct+=p[nw].fl;
			}
			nw++;
		}
		/*printf("i=%d,cct=%d,ctt=%d,pans=%d\n",i,cct,ctt,pans.len);
		for(int j=0;j<pans.len;j++)
			printf("%d ",pans.v[j]);
		printf("\n");*/
		for(int j=0;j<pans.len;j++)
			ans=addmod(ans+1ll*pans.v[j]*C(cct,i-j)%mod);
	}
	printf("%d\n",ans);
	return 0;
}