#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=2e5+10;
int dis[M],low[M],m,q[M],T,n;

struct edge
{
	int to,next;
}e[M<<1];int cnt,head[M];
void add(int u,int to)
{
	e[++cnt].to=to,e[cnt].next=head[u],head[u]=cnt;
}

int read()// 
{
	int a;cin>>a;return a;
}

signed main()
{
	T=read();memset(dis,-1,sizeof(dis));
	while(T--)
	{
		n=read(),m=read();
		for (int i=1;i<=m;i++)
		{
			int u=read(),to=read();
			add(u,to);
		}
		int l=1,r=1;q[r]=1,dis[1]=0;
		while(l<=r)
		{
			int k=q[l++];
			for (int i=head[k];i;i=e[i].next)
				if (dis[e[i].to]==-1)
					low[e[i].to]=dis[e[i].to]=dis[k]+1,q[++r]=e[i].to;
		}
		for (int i=n;i>=1;i--)
			for (int k=head[q[i]];k;k=e[k].next)
				if (dis[e[k].to]<=dis[q[i]])low[q[i]]=min(low[q[i]],dis[e[k].to]);
		for (int i=n;i>=1;i--)
			for (int k=head[q[i]];k;k=e[k].next)
				if (dis[e[k].to]>dis[q[i]])low[q[i]]=min(low[q[i]],low[e[k].to]);
		for (int i=1;i<=n;i++)cout<<low[i]<<' ';puts("");
		for (int i=1;i<=n;i++)low[i]=head[i]=q[i]=0,dis[i]=-1;cnt=0;
	}
	return 0;
}