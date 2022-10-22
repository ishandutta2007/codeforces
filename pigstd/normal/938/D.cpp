#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+10;
const int M=1e6+10;
bool vis[N];
int dis[N],n,m,s;

struct node
{
	int id,w;
	bool operator < (const node &b)const{return b.w<w;}
};

priority_queue<node> q;

inline int read()
{
	char ch=getchar();int num=0;
	while(!(ch<='9'&&ch>='0'))ch=getchar();
	num=ch-'0';
	while(ch=getchar(),ch<='9'&&ch>='0')num=num*10+ch-'0';
	return num;
}

struct edge
{
	int to,next,w;
}e[M];int cnt,head[N];
void add(int u,int to,int w)
{
	e[++cnt].to=to,e[cnt].next=head[u],e[cnt].w=w,head[u]=cnt;
}

void dij(int s)
{
	memset(dis,0x3f,sizeof(dis));node a;a.id=s,a.w=0,dis[s]=0;q.push(a);
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

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read(),w=read();
		add(u,v,2*w),add(v,u,2*w);
	}
	for (int i=1;i<=n;i++)
	{
		int x=read();
		add(0,i,x),add(i,0,x);
	}
	dij(0);
	for (int i=1;i<=n;i++)cout<<dis[i]<<' ';
	return 0;
}