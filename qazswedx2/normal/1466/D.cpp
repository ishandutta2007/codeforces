#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,m,a[1000005],deg[1000005],ft;
ll f[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++)
			deg[i]=0;
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			deg[u]++,deg[v]++;
		}
		ft=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<deg[i];j++)
				f[++ft]=a[i];
		sort(f+1,f+ft+1);
		for(int i=1;i<n;i++)
		{
			printf("%lld ",sum);
			sum+=f[ft-i+1];
		}
		printf("\n");
	}
	return 0;
}