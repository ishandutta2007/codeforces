#include <bits/stdc++.h>

using namespace std;

long long a[3],tg[3];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",a+i);
		}
		tg[0]=a[1]-(a[2]-a[1]);
		tg[1]=(a[0]+a[2])/2;
		tg[2]=a[1]+a[1]-a[0];
		if(tg[0]>0&&tg[0]%a[0]==0||(a[0]+a[2])%2==0&&tg[1]%a[1]==0||tg[2]>0&&tg[2]%a[2]==0)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}