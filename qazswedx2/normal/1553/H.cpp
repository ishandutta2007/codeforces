#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,a[1000005],tans[22][1000005],b[1000005],c[1000005];
void solve(int k,int l,int r)
{
	if(l>=r) return;
	//printf("solve:k=%d,l=%d,r=%d\n",k,l,r);
	int lim=(1<<(k-1));
	for(int i=0;i<(1<<k);i++)
		b[i]=-1e9,c[i]=1e9;
	int mid=l-1;
	while(mid<r&&((a[mid+1]>>(k-1))&1)==0) mid++;
	int mn=max(0,lim-m),mx=min((1<<k)-1,lim+m);
	for(int i=l;i<=r;i++)
	{
		int u=a[i]&((1<<k)-1);
		//printf("i=%d,u=%d,mn=%d,mx=%d\n",i,u,mn,mx); 
		for(int j=mn;j<lim;j++)
			b[u^j]=max(b[u^j],j);
		for(int j=lim;j<=mx;j++)
			c[u^j]=min(c[u^j],j);
		//for(int j=0;j<(1<<k);j++)
		//	printf("i=%d,j=%d,b=%d,c=%d\n",i,j,b[j],c[j]);
	}
	for(int i=0;i<(1<<k);i++)
		tans[k][i]=min(tans[k][i],c[i]-b[i]);
	solve(k-1,l,mid);
	solve(k-1,mid+1,r);
}
int k;
int main()
{
	scanf("%d%d",&n,&k);
	m=((1<<k)-1)/(n-1);
	//m=1<<k;
	for(int j=1;j<=k;j++)
		for(int i=0;i<(1<<j);i++)
			tans[j][i]=m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	solve(k,1,n);
/*	for(int j=1;j<=k;j++)
	{
		for(int i=0;i<(1<<j);i++)
			printf("%d ",tans[j][i]);
		printf("\n");
	}*/
	for(int i=0;i<(1<<k);i++)
	{
		int ans=1e9;
		for(int j=1;j<=k;j++)
			ans=min(ans,tans[j][i&((1<<j)-1)]);
		printf("%d ",ans);
	}
	return 0;
}