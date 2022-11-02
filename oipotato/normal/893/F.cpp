#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> g[100010];
int ls[2000010],rs[2000010],num[2000010],size[100010],deep[100010],dfn[100010],root[100010],p[100010],r[100010],a[100010],tot,times,n,m,x,y,ans,R;
bool cmp(int x,int y){return deep[x]<deep[y];}
void dfs(int p,int fa)
{
	size[p]=1;
	dfn[p]=++times;
	int cnt=g[p].size();
	for(int i=0;i<cnt;i++)
	{
		if(g[p][i]!=fa)
		{
			deep[g[p][i]]=deep[p]+1;
			dfs(g[p][i],p);
			size[p]+=size[g[p][i]];
		}
	}
}
void modify(int p1,int p2,int le,int ri,int x,int y)
{
	num[p2]=min(num[p1],y);
	ls[p2]=ls[p1];
	rs[p2]=rs[p1];
	if(le==ri)
	{
		return;
	}
	int mid=(le+ri)>>1;
	if(x<=mid)
	{
		ls[p2]=++tot;
		modify(ls[p1],ls[p2],le,mid,x,y);
	}
	else
	{
		rs[p2]=++tot;
		modify(rs[p1],rs[p2],mid+1,ri,x,y);
	}
}
int get(int p,int le,int ri,int ll,int rr)
{
	if(le==ll&&ri==rr)
	{
		return num[p];
	}
	int mid=(le+ri)>>1;
	if(rr<=mid)
	{
		return get(ls[p],le,mid,ll,rr);
	}
	else if(ll>mid)
	{
		return get(rs[p],mid+1,ri,ll,rr);
	}
	else
	{
		return min(get(ls[p],le,mid,ll,mid),get(rs[p],mid+1,ri,mid+1,rr));
	}
}
int main()
{
	int T;
	//for(scanf("%d",&T);T--;)
	{
		scanf("%d%d",&n,&R);
		times=tot=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			g[i].clear();
		}
		for(int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			g[x].push_back(y);
			g[y].push_back(x);
		}
		deep[R]=1;
		dfs(R,0);
		for(int i=1;i<=n;i++)
		{
			p[i]=i;
		}
		sort(p+1,p+n+1,cmp);
		num[0]=1E9+7;
		for(int i=1;i<=n;i++)
		{
			modify(root[i-1],root[i]=++tot,1,n,dfn[p[i]],a[p[i]]);
			r[deep[p[i]]]=i;
		}
		scanf("%d",&m);ans=0;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			x=(x+ans)%n+1;y=(y+ans)%n;
			printf("%d\n",ans=get(root[r[min(deep[x]+y,deep[p[n]])]],1,n,dfn[x],dfn[x]+size[x]-1));
		}
	}
	return 0;
}