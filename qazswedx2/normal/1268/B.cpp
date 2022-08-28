#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005];
ll tans1,tans2;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(i%2)
		{
			tans1+=a[i]-a[i]/2;
			tans2+=a[i]/2;
		}
		else
		{
			tans2+=a[i]-a[i]/2;
			tans1+=a[i]/2;
		}
	}
	printf("%I64d",min(tans1,tans2));
	return 0;
}