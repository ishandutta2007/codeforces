#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
const int N=300010;
struct query
{
	int v,x,typ;
};
vector<query>q[N];
vector<int>g[N];
int l[N],r[N],d[N],p[N],n,maxd,tot,m;
long long ans[N],c[N];
bool cmp(int x,int y){return d[x]<d[y];}
void modify(int x,int y){for(;x<=n;x+=x&(-x))c[x]+=y;}
long long get(int x){long long s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
void dfs(int p,int fa)
{
	maxd=max(maxd,d[p]);
	l[p]=++tot;
	for(auto i:g[p])if(i!=fa)d[i]=d[p]+1,dfs(i,p);
	r[p]=tot;
}
void insert(query j)
{
	modify(l[j.v],j.x*j.typ);
	modify(r[j.v]+1,j.x*j.typ*-1);
}
int main()
{
	scanf("%d",&n);
	rep(i,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(d[1]=1,0);
	scanf("%d",&m);
	rep(i,m)
	{
		int v,d,x;
		scanf("%d%d%d",&v,&d,&x);
		q[::d[v]].push_back({v,x,1});
		q[min(maxd,::d[v]+d)+1].push_back({v,x,-1});
	}
	rep(i,n)p[i]=i;
	sort(p+1,p+n+1,cmp);
	rep(i,n)
	{
		if(i==1||d[p[i]]!=d[p[i-1]])for(auto j:q[d[p[i]]])insert(j);
		ans[p[i]]=get(l[p[i]]);
	}
	rep(i,n)printf("%lld%c",ans[i]," \n"[i==n]);
	return 0;
}