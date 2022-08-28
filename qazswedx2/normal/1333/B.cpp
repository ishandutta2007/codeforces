#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int t,n,a[1000005],b[1000005];
int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int g=0,fl0=0,fl1=0,fl2=0,fl3=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		int fl=1;
		for(int i=1;i<=n;i++)
		{
			if((b[i]<a[i]&&fl0==0)||(b[i]>a[i]&&fl1==0))
			{
				fl=0;
				//printf("i=%d\n",i);
				break;
			}
			if(a[i]==1) fl1=1;
			if(a[i]==-1) fl0=1;
		}
		if(fl) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}