#include <bits/stdc++.h>

using namespace std;

long long n,d,a[100069];

int main()
{
	long long t,rr,i,l,c;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a,a+n,greater<long long>());
		c=0;
		l=-1;
		for(i=0;i<n;i++)
		{
			if(a[i]==l)
			{
				continue;
			}
			if(a[i]-c*d<=0)
			{
				break;
			}
			c++;
			l=a[i];
		}
		printf("%lld\n",c);
	}
}