#include <bits/stdc++.h>

using namespace std;

long long n,m,d,a[169];

int main()
{
	long long t,rr,i,df;
	bool g;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		for(i=0;i<n;i++)
		{
			scanf("%lld",a+i);
		}
		g=true;
		for(i=0;i<n-1;i++)
		{
			df=a[i]-max((long long)0,a[i+1]-d);
			if(m+df<0)
			{
				g=false;
				break;
			}
			m+=df;
		}
		if(g)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}