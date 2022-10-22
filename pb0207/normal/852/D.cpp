#include<bits/stdc++.h>

using namespace std;

const int N =  3e3+1;
const int inf = 1731312;

int cnt,head[N],d[N],v,n,k,m,s,t,X[N*10],Y[N*10],T[N*10],f[N][N],st[N];

struct nd{int ne,to,w;}e[N*N];

void in(int x,int y,int w)
{
	e[++cnt].to=y;e[cnt].ne=head[x];head[x]=cnt;e[cnt].w=w;
	e[++cnt].to=x;e[cnt].ne=head[y];head[y]=cnt;e[cnt].w=0;
}

bool bfs()
{
	queue<int>q;
	memset(d,-1,sizeof(d));
	q.push(s);d[s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].ne)
		{
			if(d[e[i].to]==-1&&e[i].w>0)
			{
				d[e[i].to]=d[x]+1;
				q.push(e[i].to);
			}
		}
	}
	return d[t]!=-1;
}

int dinic(int x,int mn)
{
	if(x==t||mn==0)return mn;
	int flow=0;
	for(int i=head[x];i;i=e[i].ne)
	{
		int maxf,y=e[i].to;
		if(d[y]==d[x]+1&&(maxf=dinic(y,min(e[i].w,mn)))>0)
		{
			flow+=maxf;mn-=maxf;
			e[i].w-=maxf;e[i^1].w+=maxf;
			if(mn==flow)break;
		}
	}
	if(!flow)d[x]=0;
	return flow;
}

bool can(int res)
{
	memset(head,0,sizeof(head));
	cnt=1;
	s=v+v+1,t=s+1;
	for(int i=1;i<=v;++i)in(s,i,st[i]);
	for(int i=1;i<=v;++i)
	for(int j=1;j<=v;++j)
	if(f[i][j]<=res)in(i,j+v,1);
	for(int j=1;j<=v;++j)in(j+v,t,1);
 	int ans=0;
	while(bfs())ans+=dinic(s,2e9);
	return (ans>=k);
}

void init()
{
	scanf("%d%d%d%d",&v,&m,&n,&k);
	for(int i=1,x;i<=n;++i)scanf("%d",&x),st[x]++;
	for(int i=1;i<=m;++i)scanf("%d%d%d",X+i,Y+i,T+i);
}

void floyed()
{
	memset(f,0x3f,sizeof(f));
	
	for(int i=1;i<=m;++i)f[X[i]][Y[i]]=f[Y[i]][X[i]]=min(T[i],f[X[i]][Y[i]]);
	for(int i=1;i<=v;++i)f[i][i]=0;
	
	for(int k=1;k<=v;++k)
	for(int i=1;i<=v;++i)
	for(int t=1;t<=v;++t)
	f[i][t]=min(f[i][t],f[i][k]+f[k][t]);
	return;
}

int solve()
{
	int l=0,r=inf,mid;
	while(l!=r)
	{
		mid=l+r>>1;
		if(can(mid))r=mid;
		else	l=mid+1;
	}
	cout<<(l>=inf?-1:l);
}

int main()
{
	init();
	floyed();
	solve();
	return 0;
}