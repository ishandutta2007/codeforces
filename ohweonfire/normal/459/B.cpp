#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,x,a[200005];
int main()
{
	scanf("%d",&n);
	int mx=0,mn=2147483647;
	int ca=0,cb=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(mx<a[i])
		{
			mx=a[i];
			ca=1;
		}
		else if(mx==a[i])
			ca++;
		if(mn>a[i])
		{
			mn=a[i];
			cb=1;
		}
		else if(mn==a[i])
			cb++;
	}
	long long ans=0;
	if(mx!=mn)
		ans=ca*1ll*cb;
	else
		ans=ca*(ca-1ll)/2;
	printf("%d %I64d\n",mx-mn,ans);
	return 0;
}