#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		if(n<=4)
		{
			printf("0 0 0\n");
			continue;
		}
		int val=a[1],nw=1,nw1,nw2,nw3;
		while(nw<n&&a[nw+1]==val) nw++;
		if(2*nw+1>n)
		{
			printf("0 0 0\n");
			continue;
		}
		nw1=2*nw+1;
		val=a[nw1];
		while(nw1<n&&a[nw1+1]==val) nw1++;
		if(nw1+nw+1>n)
		{
			printf("0 0 0\n");
			continue;
		}
		nw2=nw1+nw+1;
		val=a[nw2];
		while(nw2<n&&a[nw2+1]==val) nw2++;
		if(nw2>n/2)
		{
			printf("0 0 0\n");
			continue;
		}
		val=a[n/2+1];
		nw3=n/2+1;
		while(nw3>0&&a[nw3-1]==a[nw3]) nw3--;
		printf("%d %d %d\n",nw,nw1-nw,nw3-nw1-1);
	}
	return 0;
}