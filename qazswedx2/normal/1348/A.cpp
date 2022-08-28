#include<cstdio> 
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans=(1<<n);
		for(int i=1;i<n/2;i++)
			ans+=(1<<i);
		for(int i=n/2;i<n;i++)
			ans-=(1<<i);
		printf("%d\n",ans);
	}
	return 0;
}