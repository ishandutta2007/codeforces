#include<bits/stdc++.h>
#define int long long
using namespace std;

const int M=8e5+10;
int n,m;

inline int read()
{
	char ch=getchar();int num=0;
	while(!(ch<='9'&&ch>='0'))ch=getchar();
	num=ch-'0';
	while(ch=getchar(),ch<='9'&&ch>='0')num=num*10+ch-'0';
	return num;
}


struct graph
{
	struct edge
	{
		int to,next,w;
	}e[18*200010];int cnt,head[M];
	struct node
	{
		int id,w;
		bool operator < (const node &b)const{return b.w<w;}
	};
	void adde(int u,int to,int w)
	{
		e[++cnt].to=to,e[cnt].next=head[u],e[cnt].w=w,head[u]=cnt;
	}
	void add(int u,int v,int w)
	{
		adde(u,v,w),adde(u,v+n,0),adde(u,v+2*n,2*w),adde(u,v+3*n,w);
		adde(u+n,v+n,w),adde(u+n,v+3*n,w*2);
		adde(u+2*n,v+2*n,w),adde(u+2*n,v+3*n,0);
		adde(u+3*n,v+3*n,w);
	}
	int dis[M];
	bool vis[M];
	priority_queue<node> q;
	void dij(int s)
	{
		memset(dis,0x3f,sizeof(dis));
		node a;a.id=s,a.w=0,dis[s]=0;q.push(a);
		while(!q.empty())
		{
			node k=q.top();q.pop();
			if (vis[k.id])continue;
			vis[k.id]=1;
			for (int i=head[k.id];i;i=e[i].next)
			{
				int to=e[i].to;
				if (dis[to]>dis[k.id]+e[i].w)
				{
					dis[to]=dis[k.id]+e[i].w;
					if (!vis[to])
					{
						node p;p.id=to,p.w=dis[to];
						q.push(p);
					}
				}
			}
		}
	}
}G;

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int a=read(),b=read(),w=read();
		G.add(a,b,w);G.add(b,a,w);
	}
	G.dij(1);
	for (int i=2;i<=n;i++)cout<<G.dis[i+n*3]<<' ';
	return 0;
}