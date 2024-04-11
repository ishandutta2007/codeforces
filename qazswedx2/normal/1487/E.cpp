#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
int n[4],m[3],a[4][200005],c[200005],nw;
set<pair<int,int> > st[3];
bool cmp(const int x,const int y)
{
	return a[nw][x]<a[nw][y];
}
int main()
{
	scanf("%d%d%d%d",&n[0],&n[1],&n[2],&n[3]);
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<=n[i];j++)
			scanf("%d",&a[i][j]);
	}
	for(int i=0;i<3;i++)
	{
		scanf("%d",&m[i]);
		for(int j=1;j<=m[i];j++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			st[i].insert(make_pair(u,v));
		}
	}
	int ans=1e9;
	for(int i=0;i<3;i++)
	{
		nw=i;
		for(int j=1;j<=n[i];j++)
			c[j]=j;
		sort(c+1,c+n[i]+1,cmp);
		for(int j=1;j<=n[i+1];j++)
		{
			int mn=1e9;
			for(int k=1;k<=n[i];k++)
				if(st[i].find(make_pair(c[k],j))==st[i].end())
				{
					mn=min(mn,a[i][c[k]]+a[i+1][j]);
					break;
				}
			a[i+1][j]=mn;
			if(i+1==3) ans=min(ans,mn);
		}
	}
	if(ans>=9e8) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}