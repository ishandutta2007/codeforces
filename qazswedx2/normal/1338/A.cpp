#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,n,a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int mx=a[1],len=0;
		ll ans=0,lim=1;
		for(int i=1;i<=n;i++)
		{
			if(mx>a[i]) ans=max(ans,(ll)mx-a[i]);
			mx=max(mx,a[i]);
		}
		while(lim<=ans) lim<<=1,len++;
		printf("%d\n",len);
	}
	return 0;
}