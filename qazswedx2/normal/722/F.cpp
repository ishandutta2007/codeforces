#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cctype>
using namespace std;
char buf[30000005],*p1=buf,*p2=buf;
int len=29000000;
int gc()
{
	if(p1==p2)
	{
		p2=buf+fread(buf,1,len,stdin);
		p1=buf;
		if(p1==p2) return EOF;
	}
	return *(p1++);
}
int read()
{
	int x=0,ch=gc();
	while(!isdigit(ch)) ch=gc();
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=gc();
	}
	return x;
}
int n,m,fir[100005],a[5000005],nxt[5000005],b[5000005],vis[100005];
int f[15][45],cnt[15],sum[15],g[45][15],pw[15],prime[15],pt,mx,tans[100005],c[100005][2],ct;
int dfn[15],dt;
void del(int x,int v)
{
	for(int i=1;i<=pt;i++)
		if(g[x][i]!=1)
		{
			int s=v%g[x][i];
			cnt[i]--;
			for(int j=s;j<pw[i];j+=g[x][i])
			{
				f[i][j]--;
				sum[i]=max(sum[i],f[i][j]);
			}
			sum[i]=cnt[i];
		}
}
bool ins(int x,int v)
{
	int fl=1;
	for(int i=1;i<=pt;i++)
		if(g[x][i]!=1)
		{
			if(dfn[i]!=dt)
			{
				dfn[i]=dt;
				cnt[i]=sum[i]=0;
				for(int j=0;j<pw[i];j++)
					f[i][j]=0;
			}
			int s=v%g[x][i];
			cnt[i]++;
			for(int j=s;j<pw[i];j+=g[x][i])
			{
			//	printf("i=%d,j=%d,x=%d,g=%d\n",i,j,x,g[x][i]);
				f[i][j]++;
				sum[i]=max(sum[i],f[i][j]);
			}
			if(sum[i]!=cnt[i])
				fl=0;
		}
	if(!fl)
	{
		del(x,v);
		return 0;
	}
	return 1;
}
int solve()
{
	dt++;
	int ans=0,l=1;
//	printf("ct=%d\n",ct);
	for(int i=1;i<=ct;i++)
	{
		while(!ins(c[i][0],c[i][1]))
		{
		//	printf("i=%d,l=%d\n",i,l);
			del(c[l][0],c[l][1]);
			l++;
		}
	/*	printf("i=%d,c=%d,%d,l=%d\n",i,c[i][0],c[i][1],l);
		for(int j=1;j<=pt;j++)
		{
			printf("j=%d,sum=%d,cnt=%d,dfn=%d,f=",j,sum[j],cnt[j],dfn[j]);
			for(int k=0;k<pw[j];k++)
				printf("%d ",f[j][k]);
			printf("\n");
		}*/
		ans=max(ans,i-l+1);
	}
	return ans;
}
int main()
{
//	freopen("cycle.in","r",stdin);
//	freopen("cycle.out","w",stdout); 
	n=read(),m=read();
	int p=1;
	for(int i=1;i<=n;i++)
	{
		int len;
		len=read();
		fir[i]=p;
		p+=len;
		mx=max(mx,len);
		for(int j=0;j<len;j++)
		{
			a[fir[i]+j]=read();
			b[fir[i]+j]=i;
		}
	}
//	printf("---\n");
	for(int i=2;i<=mx;i++)
	{
		int fl=1;
		for(int j=2;j<i;j++)
			if(i%j==0) fl=0;
		if(fl)
		{
			prime[++pt]=i;
			pw[pt]=i;
			while(pw[pt]*i<=mx) pw[pt]*=i;
		}
	}
	for(int i=1;i<=mx;i++)
	{
		for(int j=1;j<=pt;j++)
		{
			g[i][j]=1;
			int nw=i;
			while(nw%prime[j]==0)
			{
				nw/=prime[j];
				g[i][j]*=prime[j];
			}
		}
	}
	fir[n+1]=p;
	for(int i=p-1;i;i--)
	{
		if(!vis[a[i]]) nxt[i]=p;
		else nxt[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int u=vis[i];
		if(!u) continue;
		ct=0;
	//	printf("i=%d\n",i);
		for(int j=u;j<p;j=nxt[j])
		{
		//	printf("j=%d\n",j);
			int len=fir[b[j]+1]-fir[b[j]],q=j-fir[b[j]];
			c[++ct][0]=len;
			c[ct][1]=q;
			if(nxt[j]>=p||b[nxt[j]]!=b[j]+1)
			{
				tans[i]=max(tans[i],solve());
				ct=0;
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",tans[i]);
	return 0;
}