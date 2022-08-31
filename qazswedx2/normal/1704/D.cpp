#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n,m;
ll a[2000005];
inline int F(int x,int y)
{
	return (x-1)*m+y;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%lld",&a[F(i,j)]);
		ll mn=4e18;
		for(int i=1;i<=n;i++)
		{
			ll sum=0;
			for(int j=1;j<=m;j++)
				sum+=1ll*j*a[F(i,j)];
			mn=min(mn,sum); 
		}
		for(int i=1;i<=n;i++)
		{
			ll sum=0;
			for(int j=1;j<=m;j++)
				sum+=1ll*j*a[F(i,j)];
			if(sum!=mn)
			{
				printf("%d %lld\n",i,sum-mn);
			}
		}
	}
	return 0;
}