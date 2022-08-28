#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005];
ll f[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),f[a[i]-i+500000]+=a[i];
	ll ans=0;
	for(int i=0;i<=1000000;i++)
		ans=max(ans,f[i]);
	printf("%I64d",ans);
	return 0;
}