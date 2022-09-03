#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn=500005;
int n;
ll arr[maxn],ans,sum,tmp,calc[maxn];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&arr[i]);
		sum+=arr[i];
	}
	if(sum%3||n<3)
	{
		printf("0\n");
		return 0;
	}
	sum/=3;
	tmp=0;
	for(int i=1;i<=n;i++)
	{
		tmp+=arr[i];
		calc[i]=calc[i-1];
		if(tmp==sum)
			calc[i]++;
	}
	tmp=0;
	for(int i=n;i;i--)
	{
		tmp+=arr[i];
		if(tmp==sum)
			ans+=calc[max(i-2,0)];
	}
	printf("%I64d\n",ans);
	return 0;
}