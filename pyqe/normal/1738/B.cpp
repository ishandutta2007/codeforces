#include <bits/stdc++.h>

using namespace std;

const long long ma=1e9;
long long n,d,a[100069];

inline long long dvd(long long x,long long y)
{
	return (x+ma*y-1)/y+1-ma;
}

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=d;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=3;i<=d;i++)
		{
			if(a[i]-a[i-1]<a[i-1]-a[i-2])
			{
				break;
			}
		}
		if(i<=d)
		{
			printf("No\n");
			continue;
		}
		if(d==1||a[2]-a[1]>=dvd(a[1],n-d+1))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
}