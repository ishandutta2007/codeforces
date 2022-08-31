#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n;
int a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			a[i]=0;
		for(int i=1;i<=n;i++)
		{
			int x;
			scanf("%d",&x);
			a[x]=1;
		}
		int ans1=0,ans2=0,ct=0;
		for(int i=2*n;i>0;i--)
		{
			if(!a[i])
			{
				if(ct) ct--,ans1++;
			}
			else ct++;
		}
		ct=0;
		for(int i=1;i<=2*n;i++)
		{
			if(!a[i])
			{
				if(ct) ct--,ans2++; 
			}
			else ct++;
		}
		ans2=n-ans2;
	//	printf("%d,%d\n",ans1,ans2);
		printf("%d\n",ans1-ans2+1);
	}
	return 0;
}