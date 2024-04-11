#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,k,a[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		int fl=0;
		for(int i=1;i<=n;i++)
		{
			int u=lower_bound(a+1,a+n+1,a[i]-k)-a;
			if(a[u]==a[i]-k) fl=1;
		}
		if(fl) printf("Yes\n");
		else printf("No\n");
	}
}