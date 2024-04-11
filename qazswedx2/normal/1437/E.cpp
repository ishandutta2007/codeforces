#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,a[1000005],b[1000005],f[1000005],ft;
int solve(int l,int r)
{
	ft=0;
	f[0]=a[l];
	for(int i=l+1;i<=r;i++)
	{
		int u=upper_bound(f,f+ft+1,a[i])-f;
		if(!u) continue;
		if(i==r) return r-l-u;
		f[u]=a[i];
		if(u==ft+1) ft++;
	}
	return -1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]-=i;
	}
	b[0]=0;
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	b[m+1]=n+1;
	a[0]=-1e9;
	a[n+1]=1.5e9;
	for(int i=0;i<=m;i++)
		if(a[b[i]]>a[b[i+1]])
		{
			printf("-1\n");
			return 0;
		}
	int ans=0;
	for(int i=0;i<=m;i++)
		ans+=solve(b[i],b[i+1]);
	printf("%d\n",ans);
	return 0;
}