#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=1000000000;
struct datas
{
	int id,x,y;
}data[10010];
bool cmp1(datas a,datas b)
{
	if(a.x!=b.x)return a.x<b.x;
	else return a.y<b.y;
}
bool cmp2(datas a,datas b)
{
	if(a.y!=b.y)return a.y<b.y;
	else return a.x<b.x;
}
bool cmp3(datas a,datas b){return a.id<b.id;}
int head[30010],nxt[180010],size[180010],to[180010],dis[30010],que[10000010],S,T,n,m,k,t,w,num;
bool in[30010];
int from[30010];
void add(int x,int y,int z)
{
	nxt[++num]=head[x];
	to[head[x]=num]=y;
	size[num]=z;
}
void SPFA()
{
	for(int i=1;i<=k+n+m;i++)dis[i]=INF;
	dis[S]=0;
	in[que[w=1]=S]=1;
	for(;t<w;)
	{
		int u=que[++t];
		in[u]=0;
		for(int i=head[u];i;i=nxt[i])
		if(dis[to[i]]>dis[u]+size[i])
		{
			dis[to[i]]=dis[u]+size[i];
			from[to[i]]=u;
			if(!in[to[i]])in[que[++w]=to[i]]=1;
		}
	}
	if(dis[T]==INF)printf("-1");
	else printf("%d",dis[T]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=k;i++)
	{
		scanf("%d%d",&data[i].x,&data[i].y);
		if(data[i].x==1&&data[i].y==1)S=i;
		data[i].id=i;
		if(data[i].x>1)
		{
			add(i,k+data[i].x-1,1);
			add(k+data[i].x-1,i,0);
		}
		add(i,k+data[i].x,1);
		add(k+data[i].x,i,0);
		if(data[i].x<n)
		{
			add(i,k+data[i].x+1,1);
			add(k+data[i].x+1,i,0);
		}
		if(data[i].y>1)
		{
			add(i,k+n+data[i].y-1,1);
			add(k+n+data[i].y-1,i,0);
		}
		add(i,k+n+data[i].y,1);
		add(k+n+data[i].y,i,0);
		if(data[i].y<m)
		{
			add(i,k+n+data[i].y+1,1);
			add(k+n+data[i].y+1,i,0);
		}
	}
	sort(data+1,data+k+1,cmp1);
	for(int i=2;i<=k;i++)
	if(data[i].x==data[i-1].x&&data[i].y==data[i-1].y+1)
	{
		add(data[i-1].id,data[i].id,0);
		add(data[i].id,data[i-1].id,0);
	}
	sort(data+1,data+k+1,cmp2);
	for(int i=2;i<=k;i++)
	if(data[i].y==data[i-1].y&&data[i].x==data[i-1].x+1)
	{
		add(data[i-1].id,data[i].id,0);
		add(data[i].id,data[i-1].id,0);
	}
	if(data[k].x!=n||data[k].y!=m)
	{
		add(k+n,k+n+m+1,0);
		add(k+n+m,k+n+m+1,0);
		k++;
		T=n+m+k;
	}
	else T=data[k].id;
	SPFA();
	return 0;
}