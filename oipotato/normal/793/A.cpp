#include<cstdio>
#include<algorithm>
using namespace std;
long long ans;
int a[100010],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
	if((a[i]-a[1])%k==0)ans+=(a[i]-a[1])/k;
	else
	{
		ans=-1;
		break;
	}
	printf("%I64d",ans);
	return 0;
}