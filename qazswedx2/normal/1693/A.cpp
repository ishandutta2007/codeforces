#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,n,a[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		ll sum=0;
		int fl=0,q=0;
		for(int i=1;i<=n;i++)
		{
			sum+=a[i];
			if(sum==0) fl=1;
			if(fl&&sum!=0||sum<0)
			{
				q=1;
				break;
			}
		}
		if(!fl) q=1;
		if(!q) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}