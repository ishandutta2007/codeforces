#include <bits/stdc++.h>

using namespace std;

long long n,nn,aa[100069],a[100069];

int main()
{
	long long t,rr,i,mk,sm,z;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(nn=0;n;n/=10,nn++)
		{
			aa[nn]=n%10;
		}
		z=0;
		for(mk=0;mk<1ll<<max(nn-2,0ll);mk++)
		{
			for(i=0;i<nn;i++)
			{
				a[i]=aa[i];
			}
			for(i=nn-3;i>=0;i--)
			{
				if(mk>>i&1)
				{
					if(!a[i+2])
					{
						break;
					}
					a[i+2]--;
					a[i]+=10;
				}
			}
			if(i<0)
			{
				sm=1;
				bad=1;
				for(i=0;i<nn;i++)
				{
					sm*=min(a[i]+1,19-a[i]);
					bad&=a[i]<10;
				}
				z+=max(sm-bad*2,0ll);
			}
		}
		printf("%lld\n",z);
	}
}