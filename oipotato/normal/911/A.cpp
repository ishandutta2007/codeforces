#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int a[100010],ans,minn,n,last;
int main()
{
	scanf("%d",&n);
	minn=1000000001;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		minn=min(minn,a[i]);
	}
	last=-100000;
	ans=100000;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==minn)
		{
			ans=min(ans,i-last);
			last=i;
		}
	}
	printf("%d\n",ans);
	return 0;
}