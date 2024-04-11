#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
using namespace std;
int a[2010],s1[2010],s2[2010],ans,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s1[i]=s1[i-1];s2[i]=s2[i-1];
		if(a[i]==1)
		{
			s1[i]++;
		}
		else
		{
			s2[i]++;
		}
	}
	ans=max(s1[n],s2[n]);
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,s1[i]+s2[n]-s2[i]);
	}
	for(int i=0;i<n;i++)
	{
		int now=-2*n;
		for(int j=i+1;j<=n;j++)
		{
			now=max(now,s2[j]-s1[j]);
			ans=max(ans,s1[i]+s1[j]+s2[n]-s2[j]-s2[i]+now);
		}
	}
	printf("%d\n",ans);
	return 0;
}