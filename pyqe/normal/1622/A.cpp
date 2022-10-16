#include <bits/stdc++.h>

using namespace std;

long long a[3];

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
		sort(a,a+3);
		if(a[2]==a[0]+a[1]||a[0]%2==0&&a[1]==a[2]||a[2]%2==0&&a[0]==a[1])
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}