#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n,a[1000005],m,tans[1000005][2],t,vis[1000005];
vector<int> val[200005];
void getswap(int x,int y)
{
	swap(a[x],a[y]);
	tans[++t][0]=x;
	tans[t][1]=y;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(a[i]!=i&&!vis[i])
		{
			m++;
			int nw=i;
			while(!vis[nw])
			{
				val[m].push_back(nw);
				vis[nw]=1;
				nw=a[nw];
			}
		}
	for(int i=1;i+1<=m;i+=2)
	{
		int sz0=val[i].size(),sz1=val[i+1].size();
		int u=val[i][0],v=val[i+1][0];
		getswap(u,v);
		for(int j=1;j<sz1;j++)
			getswap(u,val[i+1][j]);
		for(int j=1;j<sz0;j++)
			getswap(v,val[i][j]);
		getswap(u,v);
	}
	if(m%2)
	{
		int sz=val[m].size();
		if(sz==2)
		{
			int u=val[m][0],v=val[m][1],id=1;
			while(id==u||id==v) id++;
			getswap(u,id);
			getswap(v,id);
			getswap(u,id);
		}
		else
		{
			int u=val[m][0],v=val[m][1],w=val[m][2];
			getswap(u,v);
			getswap(v,w);
			getswap(u,w);
			for(int i=3;i<sz;i++)
				getswap(v,val[m][i]);
			getswap(u,v);
		}
	}
	for(int i=1;i<=n;i++)
		fprintf(stderr,"%d ",a[i]);
	fprintf(stderr,"\n");
	printf("%d\n",t);
	for(int i=1;i<=t;i++)
		printf("%d %d\n",tans[i][0],tans[i][1]);
	return 0;
}