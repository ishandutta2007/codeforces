#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn=300005;
int a[maxn],times[maxn],n;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		times[i]=1;
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
		times[i]+=i+1;
	times[n-1]--;
	long long ans=0;
	for(int i=0;i<n;i++)
		ans+=times[i]*1ll*a[i];
	printf("%I64d\n",ans);
	return 0;
}