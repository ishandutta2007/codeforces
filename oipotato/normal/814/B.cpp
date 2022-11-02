#include<cstdio>
#include<algorithm>
using namespace std;
int a[1010],b[1010],p[1010],num[1010],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p[j]=a[j];
			num[j]=0;
		}
		for(int j=1;j<=n;j++)
		if(j!=i)
		num[p[j]]++;
		for(int j=1;j<=n;j++)
		if(!num[j])
		{
			p[i]=j;
			num[j]=1;
			break;
		}
		bool flag=1;
		for(int j=1;j<=n;j++)
		if(!num[j])
		{
			flag=0;
			break;
		}
		if(!flag)continue;
		int t=0;
		for(int j=1;j<=n;j++)
		if(p[j]!=b[j])
		t++;
		if(t==1)
		{
			for(int j=1;j<n;j++)printf("%d ",p[j]);
			printf("%d",p[n]);
			return 0;
		}
	}
	return 0;
}