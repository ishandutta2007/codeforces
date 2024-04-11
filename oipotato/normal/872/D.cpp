#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int a[5010],b[5010],p[5010],tmp[5010],ansp[5010],c[5010],ansb[5010],n,ans,fuck;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("? %d %d\n",i,0);
		fflush(stdout);
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++)
	{
		printf("? %d %d\n",i,i);
		fflush(stdout);
		scanf("%d",&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		if(a[i]==i)
		{
			bool flag=1;
			for(int j=0;j<n;j++)
			{
				tmp[j]=p[j]=a[j]^i;
				if(p[j]>=n)
				{
					flag=0;
					break;
				}
				c[p[j]]=j;
			}
			sort(tmp,tmp+n);
			for(int j=0;j<n;j++)
			{
				if(tmp[j]!=j)
				{
					flag=0;
					break;
				}
			}
			for(int j=0;j<n;j++)
			{
				if((p[j]^c[j])!=b[j])
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				for(int j=0;j<n;j++)
				{
					ansp[j]=p[j];
					ansb[p[j]]=j;
				}
				ans++;
			}
		}
	}
	puts("!");
	printf("%d\n",ans);
	for(int i=0;i<n;i++)
	{
		printf("%d%c",ansp[i],i==n-1?'\n':' ');
	}
	fflush(stdout);
	return 0;
}