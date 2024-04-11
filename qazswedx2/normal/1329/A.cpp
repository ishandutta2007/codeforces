#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,tans[1000005],a[1000005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]),tans[i]=i;
	for(int i=1;i<=m;i++)
		if(tans[i]+a[i]-1>n)
		{
			printf("-1");
			return 0;
		}
	int r=n;
	for(int i=m;i>0;i--)
	{
		tans[i]=max(r-a[i]+1,i);
		r=tans[i]-1;
	}
	if(r) printf("-1");
	else
	{
		for(int i=1;i<=m;i++)
			printf("%d ",tans[i]);
	}
	return 0;
}