#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int tt,n,a[100005],f[100005],tans[1005][1005];
bool cmp(int x,int y)
{
	printf("1 %d %d\n",x-1,y-1);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
bool query(int x,int y)
{
	printf("2 %d %d ",a[x]-1,y);
	for(int i=1;i<=y;i++)
		printf("%d ",a[i]-1);
	printf("\n");
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	return ans;
}
int find(int x)
{
	if(f[x]==x) return f[x];
	return f[x]=find(f[x]);
}
void link(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y) return;
	f[y]=x;
}
int tmp[100005],t;
void solve(int l,int r)
{
	if(l==r) return;
	int mid=(l+r)/2;
	solve(l,mid);
	solve(mid+1,r);
	int nw1=l,nw2=mid+1;
	t=l-1;
	while(nw1<=mid&&nw2<=r)
	{
		if(cmp(a[nw1],a[nw2]))
		{
			tmp[++t]=a[nw1];
			nw1++;
		}
		else
		{
			tmp[++t]=a[nw2];
			nw2++;
		}
	}
	while(nw1<=mid)
	{
		tmp[++t]=a[nw1];
		nw1++;
	}
	while(nw2<=r)
	{
		tmp[++t]=a[nw2];
		nw2++;
	}
	for(int i=l;i<=r;i++)
		a[i]=tmp[i];
}
int main()
{
	scanf("%d",&tt);
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			a[i]=i,f[i]=i;
		solve(1,n);
		for(int i=2;i<=n;i++)
		{
			int nw=i-1;
			while(nw)
			{
				if(!query(i,nw)) break;
				link(nw,i);
				nw=find(nw)-1;
			}
		}
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				tans[i][j]=0;
		for(int l=1,r;l<=n;l=r+1)
		{
			r=l;
			while(r<n&&find(r+1)==find(l)) r++;
			for(int i=l;i<=r;i++)
				for(int j=l;j<=n;j++)
					tans[a[i]][a[j]]=1;
		}
		printf("3\n");
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				printf("%d",tans[i][j]);
			printf("\n");
		}
		fflush(stdout);
		int x;
		scanf("%d",&x);
		if(x==-1) return 1;
	}
	return 0;
}