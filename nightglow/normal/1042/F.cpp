#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 1000005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,f[N],fa[N],d[N],ans;

vector<int>v[N];

void dfs(int x)
{
		int i;
		for (i=0;i<(int)v[x].size();++i)
		{
				int p=v[x][i];
				if (fa[x]==p) continue;
				fa[p]=x;
				dfs(p);
		}
		if (v[x].size()==1) return;
		d[0]=0;
		for (i=0;i<(int)v[x].size();++i)
		{	
				int p=v[x][i];
				if (fa[x]==p) continue;
				if (f[p]==-1) continue;
				d[++d[0]]=f[p]+1;
		}
		sort(d+1,d+d[0]+1);
		if (!d[0]) f[x]=-1;
		else if (d[0]==1)
		{
				if (d[1]>k) ++ans,f[x]=-1;
				else f[x]=d[1];
		}
		else
		{
				if (d[1]>k) ans+=d[0],f[x]=-1;
				else
				{
						while (d[0]>1&&d[d[0]-1]+d[d[0]]>k) ++ans,--d[0];
						f[x]=d[d[0]];
				}
		}
}

int main()
{
		scanf("%d%d",&n,&k);
		for (i=1;i<n;++i)
		{
				int x,y;
				scanf("%d%d",&x,&y);
				v[x].pb(y);
				v[y].pb(x); 
		}
		for (i=1;i<=n;++i) if (v[i].size()>1) break;
	    dfs(i);
		if (f[i]!=-1) ++ans; 
		printf("%d\n",ans);
}