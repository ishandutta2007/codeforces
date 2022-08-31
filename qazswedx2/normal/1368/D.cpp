#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,a[1000005],cnt[105],b[1000005];
ll ans=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		for(int j=0;j<20;j++)
			if(a[i]&(1<<j))
				cnt[j]++;
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<20;j++)
			if(cnt[j]>=i)
				b[i]|=(1<<j);
	for(int i=1;i<=n;i++)
		ans+=1ll*b[i]*b[i];
	printf("%lld",ans);
	return 0;
}