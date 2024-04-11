#include <bits/stdc++.h>

using namespace std;

long long n,nn,a[200069],sk[200069];
bitset<200069> vtd;

int main()
{
	long long t,rr,i,p,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			vtd[i]=0;
		}
		for(p=1,i=1;i<=n;i++)
		{
			if(i==1||a[i]!=a[i-1])
			{
				z=a[i];
			}
			else
			{
				for(;vtd[p];p++);
				z=p;
			}
			printf("%lld%c",z," \n"[i==n]);
			vtd[z]=1;
		}
		nn=0;
		for(p=0,i=1;i<=n;i++)
		{
			for(;p<a[i];)
			{
				p++;
				nn++;
				sk[nn]=p;
			}
			printf("%lld%c",sk[nn]," \n"[i==n]);
			nn--;
		}
	}
}