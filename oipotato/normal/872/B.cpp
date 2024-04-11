#include<cstdio>
#include<algorithm>
using namespace std;
int n,k,minn,maxn,a[100010];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	minn=a[1];
	maxn=a[1];
	for(int i=1;i<=n;i++)
	{
		minn=min(minn,a[i]);
		maxn=max(maxn,a[i]);
	}
	if(k>=3)
	{
		printf("%d\n",maxn);
	}
	else if(k==2)
	{
		printf("%d\n",max(a[1],a[n]));
	}
	else
	{
		printf("%d\n",minn);
	}
	return 0;
}