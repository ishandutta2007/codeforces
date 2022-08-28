#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct pt
{
	int val,id;
	pt(int val=0,int id=0):val(val),id(id){}
	bool operator<(const pt x) const
	{
		return id<x.id;
	}
}b[3005];
int t,n,a[3005],f[3005][3005],bt,c[3005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=1e9;
		f[1][0]=0;
		for(int i=1;i<=n;i++)
		{
			bt=0;
			for(int j=0;j<i;j++)
				b[++bt]=pt(f[i][j],a[j]+j+1);
			sort(b+1,b+bt+1);
			int nw=1,mn=1e9,sum=0;
			for(int j=i+1;j<=a[i]+i;j++)
				c[j]=0;
			for(int j=i+1;j<=a[i]+i;j++)
			{
				while(nw<=bt&&b[nw].id<=j)
				{
					mn=min(mn,b[nw].val);
					nw++;
				}
				sum+=c[j];
			//	printf("i=%d,j=%d,sum=%d,mn=%d\n",i,j,sum,mn);
				f[j][i]=sum+mn;
				sum++;
				c[j+a[j]+1]--;
			}
		}
		int ans=1e9;
		for(int i=0;i<=n;i++)
			ans=min(ans,f[n][i]);
		printf("%d\n",ans);
	}
	return 0;
}