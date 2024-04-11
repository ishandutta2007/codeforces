#include<bits/stdc++.h>
using namespace std;

const int N=10000010;
int fail[N],ch[N][2],q[N],l,r,st[761],n,len,nw,tot,x,f[N],p[1510],col[1510];
unsigned long long t[761][13];
char s[N],str[N];

namespace Dinic
{
	int n,cnt,hd[1510],cur[1510],q[1510],l,r,dis[1510];
	struct node{int to,next,c;}e[2000010];
	void init(int N) {cnt=1,n=N;}
	void addedge(int x,int y,int c)
	{
		e[++cnt]=(node){y,hd[x],c},hd[x]=cnt;
		e[++cnt]=(node){x,hd[y],0},hd[y]=cnt;
	}
	bool bfs()
	{
		for (int i=1; i<=n; i++) dis[i]=-1;
		dis[q[l=r=1]=1]=0;
		while (l<=r)
		{
			int x=q[l++];
			for (int i=hd[x]; i; i=e[i].next)
				if (e[i].c&&dis[e[i].to]==-1) dis[q[++r]=e[i].to]=dis[x]+1;
		}
		return dis[n]!=-1;
	}
	int dfs(int x)
	{
		if (x==n) return 1;
		for (int &i=cur[x]; i; i=e[i].next)
			if (e[i].c&&dis[e[i].to]==dis[x]+1)
				if (dfs(e[i].to)) return e[i].c--,e[i^1].c++,1;
		return 0;
	}
	int solve()
	{
		int ans=0;
		while (bfs())
		{
			for (int i=1; i<=n; i++) cur[i]=hd[i];
			while (dfs(1)) ans++;
		}
		return ans;
	}
}

int main()
{
	scanf("%d",&n),len=0,tot=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%s",str),nw=strlen(str),st[i]=len+1,len+=nw,x=0;
		for (int j=0; j<nw; j++) 
		{
			s[st[i]+j]=str[j];
			if (ch[x][str[j]-'a']) x=ch[x][str[j]-'a'];
			else ch[x][str[j]-'a']=(++tot),x=tot;
		}
		f[x]=i;
	}
	st[n+1]=len+1,q[l=r=1]=0,fail[0]=f[0]=0;
	while (l<=r)
	{
		x=q[l++];
		if (!x)
		{
			for (int i=0; i<2; i++)
				if (ch[x][i]) fail[q[++r]=ch[x][i]]=0;
				else ch[x][i]=0;
		} else
		{
			if (!f[x]) f[x]=f[fail[x]];
			for (int i=0; i<2; i++)
				if (ch[x][i]) fail[q[++r]=ch[x][i]]=ch[fail[x]][i];
				else ch[x][i]=ch[fail[x]][i];
		}
	}
	memset(t,0,sizeof(t));
	for (int i=1; i<=n; i++)
	{
		x=0;
		for (int j=st[i],y; j<st[i+1]; j++)
		{
			x=ch[x][s[j]-'a'],y=(f[x]==i?f[fail[x]]:f[x]);
			if (y) t[i][y>>6]|=(1ull<<(y&63));
		}
	}
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++) if (t[i][k>>6]>>(k&63)&1)
			for (int j=0; j<12; j++) t[i][j]|=t[k][j];
	Dinic::init(2*n+2);
	for (int i=1; i<=n; i++) Dinic::addedge(1,i+1,1),Dinic::addedge(i+n+1,2*n+2,1);
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (t[i][j>>6]>>(j&63)&1) Dinic::addedge(i+1,j+n+1,1);
	printf("%d\n",n-Dinic::solve());
	for (int i=1; i<=n; i++)
		for (int j=Dinic::hd[i+1]; j; j=Dinic::e[j].next)
			if (Dinic::e[j].to!=1&&!Dinic::e[j].c) p[i]=Dinic::e[j].to-1,p[Dinic::e[j].to-1]=i;
	memset(col,0,sizeof(col));
	for (int i=1; i<=2*n; i++) if (!p[i]) col[i]=1;
	while (1)
	{
		bool bo=0;
		for (int i=1; i<=2*n; i++) if (!col[i]) {bo=1; break;}
		if (!bo) break;
		for (int i=1; i<=2*n; i++) if (col[i]==1)
		{
			col[i]=3;
			for (int j=Dinic::hd[i+1]; j; j=Dinic::e[j].next)
				if (Dinic::e[j].to!=1&&Dinic::e[j].to!=2*n+2)
					col[Dinic::e[j].to-1]=2;
		}
		for (int i=1; i<=n; i++) if (p[i])
		{
			if (col[i]==2&&!col[p[i]]) col[p[i]]=1,bo=0; else
			if (col[p[i]]==2&&!col[i]) col[i]=1,bo=0;
		}
		if (bo)
		{
			for (int i=1; i<=n; i++) 
				if (!col[i]&&!col[p[i]]) {col[i]=1,col[p[i]]=2; break;}
		}
	}
	for (int i=1; i<=n; i++) if ((col[i]&1)&&(col[i+n]&1)) printf("%d ",i);
	return puts(""),0;
}