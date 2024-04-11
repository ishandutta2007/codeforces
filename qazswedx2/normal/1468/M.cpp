#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;
typedef long long ll;
struct edge
{
	ll v;
	int val;
	int nxt;
}e[20000005];
int h[5000005],mod=4999997,tot,d[5000005],dt;
void ins(ll x,int y)
{
	int u=x%mod;
	if(!h[u]) d[++dt]=u;
	e[++tot].v=x;
	e[tot].val=y;
	e[tot].nxt=h[u];
	h[u]=tot;
}
int query(ll x)
{
	int u=x%mod;
	for(int i=h[u];i;i=e[i].nxt)
		if(e[i].v==x) return e[i].val;
	return -1;
}
int t,n,bs=300,b[1000005],bt,vis[1000005];
vector<int> val[200005];
unordered_map<ll,int> mp;
ll F(int x,int y)
{
	if(x>y) swap(x,y);
	return (((ll)x)<<32)+y;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		tot=0;
		scanf("%d",&n);
		bs=min(300,(int)(sqrt(n)+0.5));
		bt=0;
		for(int i=1;i<=n;i++)
		{
			int k;
			scanf("%d",&k);
			val[i].clear();
			for(int j=1;j<=k;j++)
			{
				int x;
				scanf("%d",&x);
				b[++bt]=x;
				val[i].push_back(x);
			}
		}
		sort(b+1,b+bt+1);
		bt=unique(b+1,b+bt+1)-b-1;
		for(int i=1;i<=n;i++)
		{
			int sz=val[i].size();
			for(int j=0;j<sz;j++)
				val[i][j]=lower_bound(b+1,b+bt+1,val[i][j])-b;
		}
		for(int i=1;i<=n;i++)
		{
			int sz=val[i].size();
			if(sz<=bs)
			{
				for(int j=0;j<sz;j++)
					for(int k=j+1;k<sz;k++)
					{
						ll u=F(val[i][j],val[i][k]);
						int q=query(u);
						if(q!=-1)
						{
							printf("%d %d\n",q,i);
							goto qwq;
						}
						ins(u,i);
					}
			}
		}
		for(int i=1;i<=n;i++)
		{
			int sz=val[i].size();
			if(sz>bs)
			{
				for(int j=1;j<=bt;j++)
					vis[j]=0;
				for(int j=0;j<sz;j++)
					vis[val[i][j]]=1;
				for(int j=1;j<=n;j++)
				{
					if(j==i) continue;
					int szz=val[j].size(),ct=0;
					if(szz>bs&&j<i) continue;
					for(int k=0;k<szz;k++)
						ct+=vis[val[j][k]];
					if(ct>=2)
					{
						printf("%d %d\n",i,j);
						goto qwq;
					}
				}
			}
		}
		printf("-1\n");
		qwq:;
		for(int i=1;i<=dt;i++) h[d[i]]=0;
	}
	return 0;
}