#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,s[1000005],f[1000005],g[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int i=0;i<=n+1;i++)
			f[i]=g[i]=0;
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=max(s[i]-g[i]-1,0);
			if(s[i]-g[i]-1<0) g[i+1]+=-(s[i]-g[i]-1);
		//	printf("i=%d,f=%d\n",i,f[i]);
			for(int j=i+2;j<=min(n,i+s[i]);j++)
				g[j]++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}