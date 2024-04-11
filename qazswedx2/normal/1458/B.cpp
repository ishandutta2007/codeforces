#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,f[105][10005],a[105],b[105],pn=1e4;
int main()
{
	memset(f,0xcf,sizeof(f));
	f[0][0]=0;
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{ 
		scanf("%d%d",&a[i],&b[i]);
		sum+=b[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j;j--)
			for(int k=pn;k>=a[i];k--)
				f[j][k]=max(f[j][k],f[j-1][k-a[i]]+b[i]);
	for(int j=1;j<=n;j++)
	{
		double ans=0;
		for(int k=0;k<=pn;k++)
		{
			ans=max(ans,min((double)k,(f[j][k]+sum)/2.0));
		//	if(f[j][k]>=0) printf("ans=%f,f=%d\n",ans,f[j][k]);
		}
		printf("%.12f ",ans);
	}
	return 0;
}