#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
using namespace std;
int n,a[1000005],c[1000005];
multiset<int> b;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		b.insert(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(b.lower_bound((n-a[i])%n)!=b.end())
		{
			int w=*b.lower_bound((n-a[i])%n);
			//printf("w=%d\n",w);
			c[i]=w+a[i];
			b.erase(b.lower_bound((n-a[i])%n));
			//printf("size=%d\n",b.size());
		}
		else
		{
			int w=*b.lower_bound(0);
			c[i]=w+a[i];
			//printf("-w=%d\n",w);
			b.erase(b.lower_bound(0));
		}
		printf("%d ",c[i]%n);
	}
	return 0;
}