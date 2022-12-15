#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
const long long inf=1000000000000000000ll;
set<pair<long long,int> > h;
pair<long long,pair<int,int> > nw;
set<pair<long long,pair<int,int> > > s;
int n,m,hd[100001],x,y,val,fr[100001],fa[100001],cnt;
struct node{int to,next,val;}e[200001];
struct Edge{int x,y; long long val;}E[300010];
long long dis[100001],ans;

void addedge(int x,int y,int val)
{
	e[++cnt]=(node){y,hd[x],val},hd[x]=cnt;
	e[++cnt]=(node){x,hd[y],val},hd[y]=cnt;
}

int ask(int x) {return fa[x]==x?x:fa[x]=ask(fa[x]);}
bool cmp(Edge a,Edge b) {return a.val<b.val;}

int main()
{
	scanf("%d%d",&n,&m),cnt=0,memset(hd,0,sizeof(hd));
	for (int i=1; i<=m; i++) scanf("%d%d%d",&x,&y,&val),addedge(x,y,val);
	scanf("%d",&m),s.clear(),h.clear(),dis[1]=ans=0,cnt=0;
	for (int i=1; i<=m; i++) scanf("%d",&x),fr[x]=x,s.insert(mp(0,mp(x,x)));
	for (int i=1; i<=n; i++) fa[i]=i;
	for (int i=2; i<=n; i++) dis[i]=inf; 
	for (int i=1; i<=n; i++) h.insert(mp(dis[i],i));
	while (1)
	{
		x=(*h.begin()).second;
		if (fr[x]) {ans=dis[x]; break;}
		h.erase(h.begin());
		for (int i=hd[x]; i; i=e[i].next)
			if (dis[e[i].to]>dis[x]+e[i].val) 
				h.erase(mp(dis[e[i].to],e[i].to)),dis[e[i].to]=dis[x]+e[i].val,h.insert(mp(dis[e[i].to],e[i].to));
	}
	memset(dis,0,sizeof(dis));
	while (s.size())
	{
		nw=(*s.begin()),s.erase(s.begin());
		x=nw.second.first,y=nw.second.second;
		if (!fr[x]) dis[x]=nw.first,fr[x]=y; else 
		{
			E[++cnt]=(Edge){fr[x],y,dis[x]+nw.first}; 
			if (x!=y) continue;
		}
		for (int i=hd[x]; i; i=e[i].next)
			if (e[i].to!=y) s.insert(mp(e[i].val+nw.first,mp(e[i].to,y)));
	}
	sort(E+1,E+1+cnt,cmp);
	for (int i=1; i<=cnt; i++)
	{
		E[i].x=ask(E[i].x),E[i].y=ask(E[i].y);
		if (E[i].x==E[i].y) continue;
		fa[E[i].x]=E[i].y,ans+=E[i].val;
	}
	printf("%I64d\n",ans);
	return 0;
}