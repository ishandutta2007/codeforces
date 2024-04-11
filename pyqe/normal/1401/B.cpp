#include <bits/stdc++.h>

using namespace std;

long long n,a[2][3];

int main()
{
	long long t,rr,i,ii,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			n=0;
			for(i=0;i<3;i++)
			{
				scanf("%lld",&a[ii][i]);
				n+=a[ii][i];
			}
		}
		w=min(a[0][2],a[1][1]);
		z=w*2;
		n-=w;
		w=max(a[0][1]+a[1][2]-n,0ll);
		z-=w*2;
		printf("%lld\n",z);
	}
}