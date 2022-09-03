#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
int n,k,f[2005],cnt[2005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
		cnt[f[i]]++;
	}
	int ans=0,tmp=0;
	for(int i=1999;i>=1;i--)
	{
		tmp+=cnt[i+1];
		ans+=((tmp+k-1)/k)*2;
	}
	printf("%d\n",ans);
	return 0;
}