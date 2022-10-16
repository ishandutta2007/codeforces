#include <bits/stdc++.h>

using namespace std;

long long a[3],as[3];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(i=0;i<3;i++)
		{
			scanf("%lld",a+i);
			as[i]=a[i];
		}
		sort(as,as+3,greater<long long>());
		for(i=0;i<3;i++)
		{
			printf("%lld%c",max(as[as[0]==a[i]]+1-a[i],0ll)," \n"[i==2]);
		}
	}
}