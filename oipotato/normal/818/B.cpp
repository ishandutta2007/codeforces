#include<cstdio>
using namespace std;
bool use[110];
int l[110],a[110],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		printf("1");
		return 0;
	}
	for(int i=1;i<=m;i++)scanf("%d",&l[i]);
	int now=l[1];
	for(int i=2;i<=m;i++)
	{
		int need=1;
		for(int p=now+1;p!=l[i];p=p%n+1,need++);
		if(a[now]&&a[now]!=need||need>n||!a[now]&&use[need])
		{
			printf("-1");
			return 0;
		}
		use[a[now]=need]=1;
		now=l[i];
	}
	int j=1;
	for(int i=1;i<=n;i++)
	if(!a[i])
	{
		for(;use[j];j++);
		use[a[i]=j]=1;
	}
	for(int i=1;i<n;i++)printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}