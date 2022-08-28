#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,t,a[300005],b[300005];
ll f[300005][3];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		a[0]=-3;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]);
		f[0][0]=f[0][1]=f[0][2]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
			{
				f[i][j]=1e18;
				for(int k=0;k<3;k++)
					if(a[i]+j!=a[i-1]+k)
						f[i][j]=min(f[i][j],f[i-1][k]+1ll*b[i]*j);
			}
		printf("%I64d\n",min(min(f[n][0],f[n][1]),f[n][2]));
	}
	return 0;
}