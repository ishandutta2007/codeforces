#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,a[5005],b[5005];
ll f[2][5005];
inline int F(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		f[1][1]=0;
		for(int i=2;i<=n;i++)
		{
			int nw=i%2;
			memset(f[nw],0,sizeof(f[nw]));
			f[nw][i]=0;
			for(int j=i-1;j;j--)
			{
				if(b[i]!=b[j])
				{
					f[nw][j]=max(f[nw^1][j],f[nw][i]+F(a[j]-a[i]));
					f[nw][i]=max(f[nw][i],f[nw^1][j]+F(a[j]-a[i]));
				}
				else f[nw][j]=f[nw^1][j];
			}
		}
	/*	for(int i=1;i<=n;i++)	
		{
			for(int j=1;j<=i;j++)
				printf("%lld ",f[i][j]);
			printf("\n");
		}*/
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,f[n%2][i]);
		printf("%lld\n",ans);
	}
	return 0;
}