#include <bits/stdc++.h>

using namespace std;

long long n,a[200069];

inline bool chk(long long x)
{
	return x>1&&x<n&&a[x]>max(a[x-1],a[x+1]);
}

int main()
{
	long long t,rr,i,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		for(i=2;i<=n;i++)
		{
			if(chk(i-1))
			{
				mx=a[i-1];
				if(chk(i+1))
				{
					mx=max(mx,a[i+1]);
				}
				z++;
				a[i]=mx;
			}
		}
		printf("%lld\n",z);
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",a[i]," \n"[i==n]);
		}
	}
}