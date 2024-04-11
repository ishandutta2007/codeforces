#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n,a[1005][1005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ll sum=0;
		int ans=2e9+100;
		for(int i=1;i<=2*n;i++)
			for(int j=1;j<=2*n;j++)
			{
				scanf("%d",&a[i][j]);
				if(i>n&&j>n) sum+=a[i][j];
			}
		ans=min(ans,min(min(a[n+1][1],a[n+1][n]),min(a[2*n][1],a[2*n][n])));
		ans=min(ans,min(min(a[1][n+1],a[n][n+1]),min(a[1][2*n],a[n][2*n])));
		printf("%lld\n",ans+sum);
	}
	return 0;
}