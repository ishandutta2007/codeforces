#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct edge
{
	int v,w,nxt;
}e[2000005];
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt p) const
	{
		return val>p.val;
	}
};
priority_queue<pt> pq;
int T,n,m,h[1000005],t,dis[1000005],vis[1000005],pn,s,s2;
int a[1005][1005][2];
void add(int u,int v,int w)
{
	e[++t].v=v;
	e[t].w=w;
	e[t].nxt=h[u];
	h[u]=t;
//	printf("add:u=%d,v=%d,w=%d\n",u,v,w);
}
int dij()
{
	while(!pq.empty()) pq.pop();
	dis[s]=0;
	pq.push(pt(dis[s],s));
	while(!pq.empty())
	{
		while(!pq.empty()&&dis[pq.top().id]!=pq.top().val)
			pq.pop();
		if(pq.empty()) break;
		int u=pq.top().id;
		pq.pop();
		vis[u]=1;
		for(int i=h[u];i;i=e[i].nxt)
		{
			int v=e[i].v,w=e[i].w;
			if(vis[v]||dis[v]<=dis[u]+w) continue;
			dis[v]=dis[u]+w;
			pq.push(pt(dis[v],v));
		}
	}
	return dis[s2];
}
inline int F(int x,int y)
{
	if(x<1||x>=n||y<1||y>=n) return s;
	return (x-1)*(n-1)+y;
}
void getans(int x,int y,int xx,int yy)
{
	if(x==xx)
	{
		if(y>yy) swap(y,yy);
		a[x][y][0]++;
	}
	if(y==yy)
	{
		if(x>xx) swap(x,xx);
		a[x][y][1]++;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		t=0;
		scanf("%d%d",&m,&n);
		pn=(n-1)*(n-1)+1;
		s=pn;
		s2=F(n/2,n/2);
	//	printf("s=%d,s2=%d\n",s,s2);
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=n+1;j++)
				a[i][j][0]=a[i][j][1]=0;
		for(int i=0;i<=pn+1;i++)
			h[i]=0,dis[i]=1e9,vis[i]=0;
		for(int i=1;i<=m;i++)
		{
			int x,y,xx,yy;
			scanf("%d%d%d%d",&x,&y,&xx,&yy);
			getans(x,y,xx,yy);
			getans(n-x+1,n-y+1,n-xx+1,n-yy+1);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<n;j++)
			{
				add(F(i-1,j),F(i,j),a[i][j][0]);
				add(F(i,j),F(i-1,j),a[i][j][0]);
			}
		for(int i=1;i<n;i++)
			for(int j=1;j<=n;j++)
			{
				add(F(i,j-1),F(i,j),a[i][j][1]);
				add(F(i,j),F(i,j-1),a[i][j][1]);
			}
		printf("%d\n",m-dij());
	}
	return 0; 
}