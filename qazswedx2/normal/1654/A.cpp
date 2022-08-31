#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n,a[1000005];
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int mx=0,sd=0;
		for(int i=1;i<=n;i++)
		{
			if(mx<a[i]) sd=mx,mx=a[i];
			else if(sd<a[i]) sd=a[i];
		}
		printf("%d\n",sd+mx); 
	}
	return 0;
}