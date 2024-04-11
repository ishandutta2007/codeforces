#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

typedef long long ll;

const double eps=1e-10,INF=1e16;

const int N=1e5+1e3+7,M=5e6+1e3+7;

int n,a,b,head[N],flow,cnt=1,s,t,inq[N],pre[N];

double cost,p[N],u[N],g[N],d[N];

struct node{
	int ne,to,w;
	double f;
}edg[M];

void build(int u,int v,int w,double f)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].w=w;
	edg[cnt].f=f;
	edg[cnt].ne=head[u];
	head[u]=cnt;
	++cnt;
	edg[cnt].to=u;
	edg[cnt].w=0;
	edg[cnt].f=-f;
	edg[cnt].ne=head[v];
	head[v]=cnt;
}

queue<int>q;

bool spfa()
{
	for(int i=1;i<=t;i++)
		d[i]=-1;
	memset(inq,0,sizeof(inq));
	q.push(s);
	d[s]=0;
	inq[s]=true;
	while(!q.empty())
	{
		int i=q.front();
		q.pop();
		inq[i]=false;
		for(int tmp=head[i];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(d[v]<d[i]+edg[tmp].f-eps&&edg[tmp].w>0)
			{
				d[v]=d[i]+edg[tmp].f;
				pre[v]=tmp;
				if(!inq[v])
				{
					inq[v]=true;
					q.push(v);
				}
			}
		}
	}
	return d[t]!=-1;
}

void ek()
{
	int mn=0x7fffffff;
	int x=t;
	while(x!=s)
	{
		mn=min(mn,edg[pre[x]].w);
		x=edg[pre[x]^1].to;
	}
	x=t;
	while(x!=s)
	{
		edg[pre[x]].w-=mn;
		edg[pre[x]^1].w+=mn;
		x=edg[pre[x]^1].to;
	}
	flow+=mn;
	cost+=d[t]*(double)mn;
}


int main()
{
	cin>>n>>a>>b;
	s=0,t=n+3;
	for(int i=1;i<=n;i++)
		scanf("%lf",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%lf",&u[i]);
	build(s,n+1,a,0);
	build(s,n+2,b,0);
	for(int i=1;i<=n;i++)
	{
		build(n+1,i,1,p[i]);
		build(n+2,i,1,u[i]);
		build(i,t,1,0);
		build(i,t,1,-p[i]*u[i]);
	}
	while(spfa())
		ek();
	printf("%.8lf",cost);
}